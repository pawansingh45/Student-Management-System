#include<iostream>
#include<fstream>
#include<cstring>
#include<thread> // for sleep
#include<chrono> // for sleep
#include <winbase.h>

using namespace std;

// structure to store student record
struct Student{
    string name;
    string branch;
    int age;
    string gender;
    string roll_no;
    float cpi;
};

void swap(Student& a, Student& b) {
    // Function to swap two Student structs
    Student temp = a;
    a = b;
    b = temp;
}

void sort_by_cpi(Student students[], int n) {
    // Function to sort array of structs by cpi in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].cpi > students[j].cpi) {
                swap(students[i], students[j]);
            }
        }
    }
}

void sort_by_name(Student students[], int n) {
    // Function to sort array of structs by name in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].name > students[j].name) {
                swap(students[i], students[j]);
            }
        }
    }
}

void sort_by_rollno(Student students[], int n) {
    // Function to sort array of structs by roll in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].roll_no > students[j].roll_no) {
                swap(students[i], students[j]);
            }
        }
    }
}

void to_upper(string& str) {
    // Function to convert string to uppercase
    for (char& c : str) {
        c = toupper(c);
    }
}

void to_cap(string& str) {
    // Function to capitalize first letter of each word
    bool flag = true;
    for (size_t i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) && flag) {
            str[i] = toupper(str[i]);
            flag = false;
        } else if (isalpha(str[i]) && !flag) {
            str[i] = tolower(str[i]);
        }
        if (str[i] == ' ') {
            flag = true;
        }
    }
}

void to_lower(string& str) {
    // Function to convert string to lowercase
    for (char& c : str) {
        c = tolower(c);
    }
}

void showAnimation(const string& str) {
    for(char c : str) {
        cout << c;
        Sleep(40);
    }
}

void quit() {
    showAnimation("\n Closing Program...\n");
    Sleep(1000);
    cout << "\n Program Closed !\n";
}

int askMenu(int& choice) {
    // Function to show menu after each operation
    cout << "\nSelect an option to proceed: \n1. Main Menu\n2. Repeat Operation\n3. Exit\nEnter your choice: ";
    int option;
    cin >> option;
    if (option == 1) {
        return 0;
    } else if (option == 2) {
        return 1;
    } else if (option == 3) {
        choice = 6;
    } else {
        cout << "\nInvalid Input!\n";
        return askMenu(choice);
    }
    return 0;
}

bool check() {
    // Function to check if file is available or not
    ifstream file("student.csv");
    if (!file) {
        return true;
    }
    file.close();
    return false;
}

void deleteRecord() {
    // Function to delete student record

    if (check()) {
        cout << "No Record Present :(\n";
        return;
    }

    string roll_no;
    cout << "\nEnter Roll No. to delete: ";
    cin >> roll_no;
    to_upper(roll_no);

    int records = 0;
    int index = -1;
    Student students[100];

    ifstream file("student.csv");
    int Sno = 1;
    while (!file.eof()) {
        file >> students[records].name >> students[records].branch >> students[records].gender >> students[records].age >> students[records].roll_no >> students[records].cpi;

        if (students[records].roll_no == roll_no) {
            cout << "Record Found :)\n\n";
            cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n";
            cout << "| S.No. |                       Name |      Branch |   Gender |    Age |     Roll No. |    CPI |\n";
            cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n";
            cout << "| " << Sno++ << " | " << students[records].name << " | " << students[records].branch << " | " << students[records].gender << " | " << students[records].age << " | " << students[records].roll_no << " | " << students[records].cpi << " |\n";
            cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n\n";
            index = records;
        }
        records++;
    }

    file.close();

    if (index == -1) {
        cout << "Record Not Found!\n";
        return;
    }

    ofstream file2("student.csv");

    for (int i = 0; i < records; i++) {
        if (i == index) {
            continue;
        }
        file2 << students[i].name << ", " << students[i].branch << ", " << students[i].gender << ", " << students[i].age << ", " << students[i].roll_no << ", " << students[i].cpi << "\n";
    }

    file2.close();

    cout << "\nRecord Deleted Successfully :)\n";
}

void updateRecord() {
    // Function to update student record

    if (check()) {
        cout << "No Record Present :(\n";
        return;
    }

    string roll_no;
    cout << "\nEnter Roll No. to update: ";
    cin >> roll_no;
    to_upper(roll_no);

    int records = 0;
    int index = -1;
    Student students[100];
    int Sno = 1;

    ifstream file("student.csv");

    while (!file.eof()) {
        file >> students[records].name >> students[records].branch >> students[records].gender >> students[records].age >> students[records].roll_no >> students[records].cpi;

        if (students[records].roll_no == roll_no) {
            cout << "Record Found :)\n\n";
            cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n";
            cout << "| S.No. |                       Name |      Branch |   Gender |    Age |     Roll No. |    CPI |\n";
            cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n";
            cout << "| " << Sno++ << " | " << students[records].name << " | " << students[records].branch << " | " << students[records].gender << " | " << students[records].age << " | " << students[records].roll_no << " | " << students[records].cpi << " |\n";
            cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n\n";
            index = records;
        }
        records++;
    }
    file.close();

    if (index == -1) {
        cout << "Record Not Found!\n";
        return;
    }

    int choice;
update:
    cout << "\nSelect value to be updated: \n1. Name\n2. Branch\n3. Gender\n4. Age\n5. Roll No.\n6. CPI\n7. Cancel Operation\nEnter your Choice: ";
    cin >> choice;

    string ch;
    switch (choice) {
    case 1:
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[index].name);
        to_cap(students[index].name);
        break;
    case 2:
        cout << "Branch (CS/AI/MC/EE/ME/CE/MM/PH): ";
        cin >> students[index].branch;
        to_upper(students[index].branch);
        break;
    case 3:
        cout << "Gender (M/F): ";
        cin >> students[index].gender;
        to_upper(students[index].gender);
        break;
    case 4:
        cout << "Age: ";
        cin >> students[index].age;
        break;
    case 5:
        cout << "Roll No.: ";
        cin >> students[index].roll_no;
        to_upper(students[index].roll_no);
        break;
    case 6:
        cout << "CPI: ";
        cin >> students[index].cpi;
        break;
    case 7:
        return;
    default:
        cout << "\nInvalid Choice!\n";
        goto update;
    }

    ofstream file2("student.csv");

    for (int i = 0; i < records; i++) {
        file2 << students[i].name << ", " << students[i].branch << ", " << students[i].gender << ", " << students[i].age << ", " << students[i].roll_no << ", " << students[i].cpi << "\n";
    }

    file2.close();

    cout << "\nRecord Updated Successfully :)\n";
}

void insertRecord() {
    // Function to insert student record

    string name, branch, roll_no, gender;
    int age;
    float cpi;

    cout << "\nEnter Student Name: ";
    cin.ignore();
    getline(cin, name);
    to_cap(name);

    cout << "Enter Branch (CS/AI/MC/EE/ME/CE/MM/PH): ";
    cin >> branch;
    to_upper(branch);

    cout << "Enter Gender (M/F): ";
    cin >> gender;
    to_upper(gender);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Roll No.: ";
    cin >> roll_no;
    to_upper(roll_no);

    cout << "Enter CPI: ";
    cin >> cpi;

    ofstream file;
    file.open("student.csv", ios::app);
    file << name << ", " << branch << ", " << gender << ", " << age << ", " << roll_no << ", " << cpi << "\n";
    file.close();

    cout << "\nRecord Added Successfully :)\n";
}

void viewRecord() {
    // Function to view all records

    if (check()) {
        cout << "No Record Present :(\n";
        return;
    }

    Student students[100];
    int records = 0;

    ifstream file("student.csv");
    int Sno = 1;

    cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n";
    cout << "| S.No. |                       Name |      Branch |   Gender |    Age |     Roll No. |    CPI |\n";
    cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n";

    while (!file.eof()) {
        file >> students[records].name >> students[records].branch >> students[records].gender >> students[records].age >> students[records].roll_no >> students[records].cpi;
        cout << "| " << Sno++ << " | " << students[records].name << " | " << students[records].branch << " | " << students[records].gender << " | " << students[records].age << " | " << students[records].roll_no << " | " << students[records].cpi << " |\n";
        records++;
    }

    cout << "+-------+----------------------------+-------------+----------+--------+--------------+--------+\n";
    file.close();
}

int main() {
    system("cls");

    showAnimation("\n -------------- Welcome to Student Management System -------------- \n\n");
    Sleep(500);
    int choice = 0;
    while (choice != 6) {
        cout << "1. Insert New Record\n2. View All Records\n3. Update Record\n4. Delete Record\n5. Quit\n";
        cout << "Enter your choice: ";
        cin >>choice;

        switch (choice){
        case 1:
            insertRecord();
            break;
        case 2:
            viewRecord();
            break;
        case 3:
            updateRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            quit();
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
        
    }

    return 0;
}
