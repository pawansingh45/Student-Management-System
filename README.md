# Student Management System

This is a simple console-based **Student Management System** built using C++. The system allows you to add, update, delete, and search student records. The student information includes details like name, branch, age, gender, roll number, and CPI (Cumulative Performance Index). The records are stored in a CSV file.

## Features

- **Add Record**: Add a new student record with details such as name, branch, age, gender, roll number, and CPI.
- **Update Record**: Modify existing student details.
- **Delete Record**: Remove a student record from the file.
- **Sort Records**: Sort student records by CPI, name, or roll number.
- **Search Record**: Search student records by roll number.
- **File Handling**: Save student details to a CSV file and retrieve them when the program runs again.

## Dependencies

- Windows-specific library `windows.h` for the `Sleep()` function (you can remove or replace this for cross-platform compatibility).
- Standard C++ libraries:
  - `<iostream>`: Input/output stream.
  - `<fstream>`: File stream for reading and writing to CSV.
  - `<string>`: String manipulation.
  - `<algorithm>`: For sorting operations.

## Getting Started

### Prerequisites

- A C++ compiler (GCC, MSVC, etc.).
- A console/terminal to run the program.
- The CSV file (`student.csv`) will be generated automatically when records are added.

### Compilation & Execution

1. **Compile** the program using a C++ compiler. For example, with GCC:
   ```bash
   g++ student_management_system.cpp -o student_management_system
