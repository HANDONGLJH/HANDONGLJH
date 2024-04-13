# Java Utilities Overview

This documentation provides an overview of the Java utilities available in this project. Currently, the project includes two main utilities: `Lotto` and `MakePW`. 

## Lotto Class

`Lotto.java` offers functionality related to the generation and evaluation of Lotto numbers.

### Features

- **Automatic Lottery Number Generation**: Automatically generates a random set of 6 unique lottery numbers.
- **Manual Lottery Number Input**: Allows the user to manually input a unique set of 6 lottery numbers.
- **Print Lottery Numbers**: Displays the current set of lottery numbers.
- **Checking Lotto Numbers**: Compares a set of lottery numbers against the current set to count how many numbers match.

### Usage

- To generate a new set of lottery numbers automatically, instantiate the `Lotto` class and call `remakeAuto()`.
- To input your own lottery numbers, use `remake()`.
- To print the current set of lottery numbers, use `printNumbers()`.
- To check how many numbers match with another set, use `checkLotto(int[] checkNumbers)`.

## MakePW Class

`MakePW.java` is designed to create random passwords or codes based on specific requirements.

### Features

- **Random Password Creation**: Generates a random password with a specified length.
- **Random Code Generation for Products**: Creates a random code composed of uppercase alphabets and numbers. The length of each part (alphabets and numbers) can be specified.

### Usage

- To generate a random password, instantiate the `MakePW` class and call `make(int length)`.
- To create a product code, use `makeCode(int length1, int length2)` where `length1` is the length of the alphabetical part and `length2` is the length of the numerical part.

### Method Summaries:

solveJ031: Initiates our journey with a problem focused on array manipulation, demonstrating how to perform efficient element searches and updates.

solveJ032: Explores string handling in Java, showing methods for string analysis, modification, and advanced manipulation techniques.

solveJ033: Focuses on sorting algorithms, providing a detailed look at their implementation and effectiveness across different scenarios.

solveJ034: Deals with Java's collection framework, emphasizing the usage of Lists, Sets, and Maps for complex data management tasks.

solveJ035: A dive into recursion, showcasing how certain problems can be solved more elegantly with a recursive approach.

solveJ036: Introduces basic input/output operations in Java, including file reading and writing, along with parsing data from various sources.

solveJ037: Examines the concept of threading and concurrency, demonstrating how to perform multiple tasks simultaneously within a Java application.

solveJ038: Covers exception handling and debugging techniques, ensuring your Java code can gracefully handle and recover from unexpected conditions.

solveJ039: Focuses on algorithm optimization, teaching how to improve the efficiency and performance of your Java code.

solveJ040: Looks into graphical user interface design using Java Swing, guiding through the creation of user-friendly interfaces.

solveJ041: Explores network programming, illustrating how to make network requests, handle responses, and build simple client-server applications.

solveJ042: Delves into database operations, showing how to connect to, query, and manipulate data within a relational database system using Java.

solveJ043: Introduces unit testing in Java, emphasizing the importance of testing in the software development lifecycle.

solveJ044: Examines secure coding practices in Java, covering topics such as encryption, secure data handling, and protecting applications from common vulnerabilities.

solveJ045: Concludes with a capstone project, incorporating elements from all previous methods to solve a comprehensive problem. This final challenge tests the cumulative knowledge and skills acquired throughout the previous exercises.


