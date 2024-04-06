import java.util.Scanner;

public class Main {
  // Move the scanner to be a static class-level variable
  static Scanner scanner = new Scanner(System.in);

  public static void main(String[] args) {
    Main pStudio = new Main();
    while (true) {
      System.out.println("실행하고 싶은 문제 번호를 입력하세요. 종료하려면 -1을 입력하세요.");
      // 사용자로부터 문제 번호를 입력받음
      int problemNumber = scanner.nextInt();
      // 종료 조건 체크
      if (problemNumber == -1) {
        System.out.println("프로그램을 종료합니다.");
        scanner.close(); // 프로그램 종료 전에 한 번만 Scanner를 닫습니다.
        break;
      }

      // 입력받은 번호에 따라 해당 문제 실행
      switch (problemNumber) {
        case 1:
          pStudio.solveJ001();
          break;

        case 2:
          pStudio.solveJ002();
          break;
        case 3:
          pStudio.solveJ003();
          break;
        case 5:
          pStudio.solveJ005();
          break;
        case 11:
          pStudio.solveJ011();
          break;
        case 12:
          pStudio.solveJ012();
          break;
        case 15:
          pStudio.solveJ015();
          break;
        case 21:
          pStudio.solveJ021();
          break;
        case 24:
          pStudio.solveJ024();
          break;
        case 25:
          pStudio.solveJ025();
          break;
        case 29:
          pStudio.solveJ029();
          break;
        case 30:
          pStudio.solveJ030();
          break;

        default:
          System.out.println("해당 번호의 문제는 존재하지 않습니다.");
      }
    }
    scanner.close();

  }

  void solveJ001() {
    // Variables for height (in cm) and weight, and BMI
    int height, weight;
    double bmi;

    // Input for height and weight
    System.out.println("Enter your height in cm:");
    height = scanner.nextInt();
    System.out.println("Enter your weight in kg:");
    weight = scanner.nextInt();

    // Calculating BMI
    bmi = weight / Math.pow(height * 0.01, 2);

    // Output BMI
    System.out.printf("Your BMI is: %.2f\n", bmi);
  }

  void solveJ002() {
    // Variables for Celsius and Fahrenheit
    double c_degree, f_degree;

    // Input for Celsius temperature
    System.out.println("Enter the temperature in Celsius:");
    c_degree = scanner.nextDouble();

    // Calculating Fahrenheit temperature
    f_degree = c_degree * 1.8 + 32;

    // Output Fahrenheit temperature
    System.out.printf("The temperature in Fahrenheit is: %.2f\n", f_degree);
  }

  void solveJ003() {
    // Variables for square meters and pyeong
    double m2_area, pyung_area;

    // Input for apartment area in square meters
    System.out.println("Enter the apartment area in square meters:");
    m2_area = scanner.nextDouble();

    // Calculating area in pyeong
    pyung_area = m2_area / 3.305;

    // Output area in pyeong
    System.out.printf("The area in pyeong is: %.2f\n", pyung_area);
  }

  void solveJ005() {
    // Variables for month, day, and day count
    int month, day;
    int day_count = 0;

    // Input for month and day
    System.out.println("Enter the month and day:");
    month = scanner.nextInt();
    day = scanner.nextInt();

    // Calculating the day of the year
    switch (month) {
      case 1:
        day_count = 0;
        break;
      case 2:
        day_count = 31;
        break;
      case 3:
        day_count = 59;
        break;
      case 4:
        day_count = 90;
        break;
      case 5:
        day_count = 120;
        break;
      case 6:
        day_count = 151;
        break;
      case 7:
        day_count = 181;
        break;
      case 8:
        day_count = 212;
        break;
      case 9:
        day_count = 243;
        break;
      case 10:
        day_count = 273;
        break;
      case 11:
        day_count = 304;
        break;
      case 12:
        day_count = 334;
        break;
    }
    day_count += day;

    // Output the result
    System.out.printf("It's the %dth day of the year.\n", day_count);
  }

  void solveJ011() {
    System.out.println("Enter your height in cm:");
    int height = scanner.nextInt();

    System.out.println("Enter your weight in kg:");
    int weight = scanner.nextInt();

    double bmi = weight / Math.pow(height / 100.0, 2);

    String result = bmi >= 25 ? "Yes" : "No";
    System.out.println("Are you obese? \n" + result);
  }

  void solveJ012() {
    // Variables for square meter area and pyung area
    double m2_area;
    double pyung_area;

    // Input for square meter area
    System.out.println("Enter the square meter area of the apartment:");
    m2_area = scanner.nextDouble();

    // Calculating pyung area
    pyung_area = m2_area / 3.305;

    // Determining apartment type based on pyung area
    String apt_type;
    if (pyung_area < 15) {
      apt_type = "small";
    } else if (pyung_area < 30) {
      apt_type = "normal";
    } else if (pyung_area < 50) {
      apt_type = "large";
    } else {
      apt_type = "huge";
    }

    // Output the result
    System.out.println("Apartment pyung area: " + pyung_area);
    System.out.println("Apartment type: \n" + apt_type);
  }

  void solveJ015() {
    int num1, num2, num3;
    int max_num, min_num;

    // Input for three numbers
    System.out.println("Enter three numbers:");
    num1 = scanner.nextInt();
    num2 = scanner.nextInt();
    num3 = scanner.nextInt();

    // Determine the maximum number without using Math.max
    max_num = num1;
    if (num2 > max_num) {
      max_num = num2;
    }
    if (num3 > max_num) {
      max_num = num3;
    }

    // Determine the minimum number without using Math.min
    min_num = num1;
    if (num2 < min_num) {
      min_num = num2;
    }
    if (num3 < min_num) {
      min_num = num3;
    }

    // Output the maximum and minimum numbers
    System.out.println("Max number: " + max_num);
    System.out.println("Min number: " + min_num);
  }

  void solveJ021() {
    System.out.println("Enter a number:");
    int num = scanner.nextInt();
    int sum = 0;
    for (int i = 1; i <= num; i++) {
      sum += i;
    }
    System.out.println("Sum from 1 to " + num + " is: " + sum);
  }

  void solveJ024() {
    System.out.println("Enter a number to find its factorial:");
    int num = scanner.nextInt();
    int result = 1;
    for (int i = 1; i <= num; i++) {
      result *= i;
    }
    System.out.println("Factorial of " + num + " is: " + result);
  }

  void solveJ025() {
    System.out.println("Enter a number to check if it's prime:");
    int num = scanner.nextInt();
    boolean isPrime = num > 1;
    for (int i = 2; i <= Math.sqrt(num); i++) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      System.out.println(num + " is a prime number.");
    } else {
      System.out.println(num + " is not a prime number.");
    }
  }

  void solveJ029() {
    System.out.println("Enter a string to reverse:");
    String str = scanner.next(); // reads a single word; use scanner.nextLine() if you need to read a full line
    String reversed = new StringBuilder(str).reverse().toString();
    System.out.println("Reversed string: " + reversed);
  }

  void solveJ030() {
    System.out.println("Enter the position (n) to find the Fibonacci number:");
    int n = scanner.nextInt();
    int a = 0, b = 1, c;
    if (n == 0) {
      System.out.println("The Fibonacci number is: 0");
    } else if (n == 1) {
      System.out.println("The Fibonacci number is: 1");
    } else {
      for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
      }
      System.out.println("The Fibonacci number is: " + b);
    }
  }

}