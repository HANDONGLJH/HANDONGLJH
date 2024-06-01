#include <fstream>
#include <iostream>
#include <sstream>
#define MAX 50

using namespace std;
string kname[2] = {"A+~F", "P/F"}; // String for grading

class MyClass {
private:
  int code;    // class code
  string name; // class name
  int unit;    // credites
  int grading; // grading category (1:A+~F, 2:P/F)
public:
  MyClass(int ncode, string nname, int nunit, int ngrading) {
    code = ncode;
    name = nname;
    unit = nunit;
    grading = ngrading;
  }
  ~MyClass();
  int getCode() { return code; }
  string getName() { return name; }
  int getUnit() { return unit; }
  int getGrading() { return grading; };
  void setCode(int newcode) { code = newcode; }
  void setName(string newname) { name = newname; }
  void setUnit(int newunit) { unit = newunit; }
  void setGrading(int newgrading) { grading = newgrading; }
  string toString() {
    stringstream sstm;
    sstm << "[" << code << "] " << name << " [credit " << unit
         << " - " + kname[grading - 1] << "]";
    return sstm.str();
  }
  string toStringSave() {
    stringstream sstm;
    sstm << code << " " << name << " " << unit << " " << grading;
    return sstm.str();
  }
};

class MyClassManager {
private:
  MyClass *allclasses[MAX];
  MyClass *myclasses[10];
  int count;
  int mycount;

public:
  MyClassManager() {
    count = 0;
    mycount = 0;
  }
  ~MyClassManager() {}
  int getCount() { return count; }
  int getMyCount() { return mycount; }

  void loadData(string filename);
  void printAllClasses();               // Print all class list
  void findClasses(string name);        // Search a class by name from the list
  void saveAllClasses(string filename); // Save all class list

  // Functions for modifying
  void addClass();  // Add a class into the list
  void editClass(); // Modify a class in the list

  // Functions for making
  void applyMyClass();                 // Apply a class
  void printMyClasses();               // Print my classes
  void saveMyClasses(string filename); // Save my classes
};

int main() {
  int no; // menu number
  int quit = 0;
  string name;

  MyClassManager manager; // MyClassManager obj

  manager.loadData("classes.txt");

  while (!quit) {
    cout << "Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save "
            "0.Quit\n";
    cout << ">> Menu? > ";
    cin >> no;
    switch (no) {
    case 1:
      cout << "> 1.Print All Classes\n";
      manager.printAllClasses();
      break;
    case 2:
      cout << "> 2.Add a Class\n";
      manager.addClass();
      break;
    case 3:
      cout << "> 3.Modify a Class\n";
      manager.editClass();
      break;
    case 4:
      cout << "> 4.Search a Class\n";
      cout << ">> Enter class name > ";
      cin >> name;
      manager.findClasses(name);
      break;
    case 5:
      cout << "> 5.Apply a class\n";
      manager.applyMyClass();
      cout << manager.getMyCount() << " classes has been applied.\n";
      break;
    case 6:
      cout << "> 6.My classes\n";
      manager.printMyClasses();
      break;
    case 7:
      cout << "> 7.Save\n";
      manager.saveMyClasses("myclasses.txt");
      cout << "\n> All my classes ware saved to my_classes.txt.\n";
      manager.saveAllClasses("classes.txt");
      cout << "\n> All of class list ware saved to classes.txt.\n";
      break;
    case 0:
      quit = 1;
      break;
    }
  }
  return 0;
}

// 0. 교과목 목록 잃어오기
void MyClassManager::loadData(string filename) {
  string line, name;
  int code, unit, grading;
  ifstream file(filename);
  while (!file.eof()) {
    if (file.eof())
      break;
    file >> code >> name >> unit >> grading;
    if (count < MAX) { // 추가된 검증
      allclasses[count] = new MyClass(code, name, unit, grading);
      count++;
    } else {
      cout << "Error: Maximum class count reached." << endl;
      break;
    }
  }
  file.close();
  cout << count << " classes are loaded.\n";
}

// 1. 교과목 목록 출력하기
void MyClassManager::printAllClasses() {
  for (int i = 0; i < count; i++) {
    cout << allclasses[i]->toString() << endl;
  }
}

// 7-1. 교과목 목록 파일로 저장
void MyClassManager::saveAllClasses(string filename) {
  ofstream file(filename);
  for (int i = 0; i < count; i++) {
    file << allclasses[i]->toStringSave();
    if (i < count - 1)
      file << endl;
  }
  file.close();
}

// 4. 교과목 목록 검색
void MyClassManager::findClasses(string name) {
  int found = 0;
  cout << "Searching keyword: " << name << endl;
  for (int i = 0; i < count; i++) {
    if (allclasses[i]->getName().find(name) != string::npos) {
      cout << allclasses[i]->toString() << endl;
      found++;
    }
  }
  cout << count << " classes found.\n";
}

// ----------------------------------------------------------------

// 2. 교과목 목록 추가
void MyClassManager::addClass() {
  int code, unit, grading;
  string name;

  cout << ">> code number > ";
  cin >> code;
  cout << ">> class name > ";
  cin >> name;
  cout << ">> credits > ";
  cin >> unit;
  cout << ">> grading (1: A+~F, 2: P/F) > ";
  cin >> grading;

  // 중복된 코드 확인
  for (int i = 0; i < count; i++) {
    if (allclasses[i]->getCode() == code) {
      cout << "Error: Duplicate class code." << endl;
      return;
    }
  }

  //새로운 과목을 목록에 추가
  allclasses[count++] = new MyClass(code, name, unit, grading);
  cout << "Class added successfully." << endl;
}

// 3. 교과목 목록 수정
void MyClassManager::editClass() {
  int code, unit, grading;
  string name;

  cout << ">> Enter a code of class > ";
  cin >> code;

  // 해당 코드의 과목 찾기
  for (int i = 0; i < count; i++) {
    if (allclasses[i]->getCode() == code) {
      // 새 정보 입력받기
      cout << ">> new class name > ";
      cin >> name;
      cout << ">> new credits > ";
      cin >> unit;
      cout << ">> new grading (1: A+~F, 2: P/F) > ";
      cin >> grading;

      // 과목 수정
      allclasses[i]->setName(name);
      allclasses[i]->setUnit(unit);
      allclasses[i]->setGrading(grading);

      cout << "Class edited successfully." << endl;
      return;
    }
  }
  cout << "Error: Class code not found." << endl;
}

// 5. 내 수강과목 등록
void MyClassManager::applyMyClass() {
  int code;

  cout << "Enter the class code to apply (or -1 to finish): ";
  cin >> code;

  while (code != -1) {
    bool found = false;

    // 등록된 과목 코드 확인
    for (int i = 0; i < count; i++) {
      if (allclasses[i]->getCode() == code) {
        // 이미 내 수강과목에 등록된 경우 체크
        for (int j = 0; j < mycount; j++) {
          if (myclasses[j]->getCode() == code) {
            cout << "Error: Class already applied." << endl;
            found = true;
            break;
          }
        }

        // 새로운 수강과목 추가
        if (!found && mycount < 10) { // 수정된 부분
          myclasses[mycount++] = allclasses[i];
          cout << "Class applied successfully." << endl;
        } else if (mycount >= 10) {
          cout << "Error: Maximum class limit reached." << endl;
        }
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "Error: Class code not found." << endl;
    }

    cout << "Enter the class code to apply (or -1 to finish): ";
    cin >> code;
  }
}

// 6. 내 수강과목 출력
void MyClassManager::printMyClasses() {
  for (int i = 0; i < mycount; i++) {
    cout << myclasses[i]->toString() << endl;
  }
}

// 7-2. 내 수강과목 파일로 저장
void MyClassManager::saveMyClasses(string filename) {
  ofstream file(filename);
  int totalCredits = 0;
  int pfCredits = 0;
  int gpCredits = 0;

  for (int i = 0; i < mycount; i++) {
    file << myclasses[i]->toStringSave() << endl;
    totalCredits += myclasses[i]->getUnit();
    if (myclasses[i]->getGrading() == 1) {
      gpCredits += myclasses[i]->getUnit();
    } else {
      pfCredits += myclasses[i]->getUnit();
    }
  }

  file << "Total credits: " << totalCredits << endl;
  file << "P/F credits: " << pfCredits << endl;
  file << "A+~F credits: " << gpCredits << endl;
  file << "Total classes: " << mycount << endl;

  file.close();
  cout << "My classes have been saved to " << filename << endl;
}