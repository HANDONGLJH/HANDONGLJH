#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char kname[2][10] = {"A+~F", "P/F"}; // String for grading
struct st_class {
  int code;      // class code
  char name[30]; // class name
  int unit;      // credits
  int grading;   // grading (1:A+~F, 2:P/F)
};

void LoadData(struct st_class *c[], int *csize) {
  // Load data from file into array of struct st_class
  // Implementation provided
}

void printAllClasses(struct st_class *c[], int csize) {
  // Print all classes
  // Implementation provided
}

int addNewClass(struct st_class *c[], int csize) {
  // Add a new class
  // Additional implementation required to check for duplicate class code
  int newCode;
  char newName[30];
  int newUnit;
  int newGrading;

  printf("Enter new class code: ");
  scanf("%d", &newCode);

  // Check if the class code already exists
  for (int i = 0; i < csize; i++) {
    if (c[i]->code == newCode) {
      printf("Error: Class code already exists\n");
      return csize;
    }
  }

  getchar(); // Clear input buffer
  printf("Enter new class name: ");
  fgets(newName, 30, stdin);
  // Remove newline character at the end of the string
  newName[strcspn(newName, "\n")] = 0;

  printf("Enter new class unit: ");
  scanf("%d", &newUnit);

  printf("Enter new class grading (1:A+~F, 2:P/F): ");
  scanf("%d", &newGrading);

  c[csize] = (struct st_class *)malloc(sizeof(struct st_class));
  c[csize]->code = newCode;
  strncpy(c[csize]->name, newName, 30);
  c[csize]->unit = newUnit;
  c[csize]->grading = newGrading;

  return csize + 1;
}

void editClass(struct st_class *c[], int csize) {
  // Edit class information
  // Additional implementation required
  int editCode;
  int found = 0;

  printf("Enter the class code to edit: ");
  scanf("%d", &editCode);

  for (int i = 0; i < csize; i++) {
    if (c[i]->code == editCode) {
      found = 1;

      printf("Enter new name: ");
      getchar(); // Clear input buffer
      fgets(c[i]->name, 30, stdin);
      c[i]->name[strcspn(c[i]->name, "\n")] = 0; // Remove newline character

      printf("Enter new unit: ");
      scanf("%d", &c[i]->unit);

      printf("Enter new grading (1:A+~F, 2:P/F): ");
      scanf("%d", &c[i]->grading);

      printf("Class information updated successfully.\n");
      break;
    }
  }

  if (!found) {
    printf("Class code not found.\n");
  }
}

void findClasses(struct st_class *c[], int csize) {
  // Find classes by name
  // Implementation provided
}

void applyMyClasses(int my[], int msize, struct st_class *c[], int csize) {
  // Apply my classes
  // Additional implementation required
}

void printMyClasses(int my[], int msize, struct st_class *c[], int csize) {
  // Print my classes
  // Implementation required
}

void saveAllClasses(struct st_class *c[], int csize) {
  // Save all classes to file
  // Implementation provided
}

void saveMyClass(int my[], int msize, struct st_class *c[], int csize) {
  FILE *fp;
  fp = fopen("my_classes.txt", "w");

  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  int totalCredits = 0;
  int totalCourses = msize;

  fprintf(fp, "과목코드\t과목명\t학점수\t평가방식\n");

  for (int i = 0; i < msize; i++) {
    for (int j = 0; j < csize; j++) {
      if (my[i] == c[j]->code) {
        fprintf(fp, "%d\t%s\t%d\t%d\n", c[j]->code, c[j]->name, c[j]->unit,
                c[j]->grading);
        totalCredits += c[j]->unit;
      }
    }
  }

  int gradeCredits[2] = {0}; // Initialize grading credits array
  for (int i = 0; i < msize; i++) {
    for (int j = 0; j < csize; j++) {
      if (my[i] == c[j]->code) {
        gradeCredits[c[j]->grading - 1] += c[j]->unit;
      }
    }
  }

  fprintf(fp, "\n총 수강학점: %d\n", totalCredits);
  fprintf(fp, "A+~F 평가방식 수강학점: %d\n", gradeCredits[0]);
  fprintf(fp, "P/F 평가방식 수강학점: %d\n", gradeCredits[1]);
  fprintf(fp, "수강과목수: %d\n", totalCourses);

  fclose(fp);
}

int main() {
  struct st_class *classes[100];
  int numClasses = 0;

  LoadData(classes, &numClasses);

  // Menu-driven program
  int choice;
  do {
    printf("\nMenu:\n");
    printf("1. Print all classes\n");
    printf("2. Add a new class\n");
    printf("3. Edit a class\n");
    printf("4. Find classes\n");
    printf("5. Apply my classes\n");
    printf("6. Print my classes\n");
    printf("7. Save all classes\n");
    printf("8. Save my classes\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printAllClasses(classes, numClasses);
      break;
    case 2:
      numClasses = addNewClass(classes, numClasses);
      break;
    case 3:
      editClass(classes, numClasses);
      break;
    case 4:
      findClasses(classes, numClasses);
      break;
    case 5:
      // applyMyClasses();
      break;
    case 6:
      // printMyClasses();
      break;
    case 7:
      saveAllClasses(classes, numClasses);
      break;
    case 8:
      // saveMyClass();
      break;
    case 0:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 0);

  return 0;
}
