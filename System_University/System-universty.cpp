#include <bits/stdc++.h>

using namespace std;

    
class StudentNode {
public:
    string studentName;
    StudentNode* next;

    StudentNode(string name) {
        studentName = name;
        next = nullptr;
    }
};

class SubjectNode {
public:
    string subjectCode, subjectName;
    StudentNode* studentList;
    SubjectNode* next;

    SubjectNode(string code, string name) {
        subjectCode = code;
        subjectName = name;
        studentList = nullptr;
        next = nullptr;
    }
};
class UniversitySystem {
private:
    SubjectNode* head;

public:
    UniversitySystem() {
        head = nullptr;
    }

    void addSubject() {
        string code, name;
        cout << "Enter subject code = ";
        cin >> code;
        cin.ignore();
        cout << "Enter subject name =  ";
        getline(cin, name);

        SubjectNode* newSubject = new SubjectNode(code, name);

        // insert
        if (!head) {
            head = newSubject;
        } else {
            SubjectNode* temp = head;
            // Traverse
            while (temp->next)
                temp = temp->next;
            temp->next = newSubject;
        }

        cout << "Subject added successfully " << endl;
    }

    void displaySubjects() {
        if (!head) {
            cout << "No subjects available " << endl;
            return;
        }

        cout << "\nAvailable Subjects = " << endl;
        SubjectNode* temp = head;
        while (temp) {
            cout << "Code = " << temp->subjectCode
                 << "  Name = " << temp->subjectName << endl;
            temp = temp->next;
        }
    }

    void registerStudent() {
        if (!head) {
            cout << "No subjects available for registration " << endl;
            return;
        }

        string code;
        cout << "Enter subject code to register in = ";
        cin >> code;

        SubjectNode* temp = head;
        
        // Search
        while (temp && temp->subjectCode != code)
            temp = temp->next;

        if (!temp) {
            cout << "Subject not found = " << endl;
            return;
        }

        string studentName;
        cout << "Enter student name = ";
        cin.ignore();
        getline(cin, studentName);

        StudentNode* newStudent = new StudentNode(studentName);

        if (!temp->studentList) {
            temp->studentList = newStudent;
        } else {
            StudentNode* s = temp->studentList;
            while (s->next)
                s = s->next;
            s->next = newStudent;
        }

        cout << "Student registered successfully in " << temp->subjectName << endl;
    }

    void displayStudentsInSubject() {
        if (!head) {
            cout << "No subjects available " << endl;
            return;
        }

        string code;
        cout << "Enter subject code = ";
        cin >> code;

        SubjectNode* temp = head;
        while (temp && temp->subjectCode != code)
            temp = temp->next;

        if (!temp) {
            cout << "Subject not found " << endl;
            return;
        }

        if (!temp->studentList) {
            cout << "No students registered in this subject " << endl;
            return;
        }

        cout << endl << "Students registered in " << temp->subjectName << endl;
        StudentNode* s = temp->studentList;
        while (s) {
            cout << "-" << s->studentName << endl;
            s = s->next;
        }
    }

    void displayStudentSubjects() {
        if (!head) {
            cout << "No subjects available " << endl;
            return;
        }

        string studentName;
        cout << "Enter student name = ";
        cin.ignore();
        getline(cin, studentName);

        bool found = false;

        SubjectNode* sub = head;
        while (sub) {
            StudentNode* s = sub->studentList;
            while (s) {
                if (s->studentName == studentName) {
                    if (!found) {
                        cout << endl << "Subjects registered by " << studentName << endl;
                        found = true;
                    }
                    cout << "-" << sub->subjectName << " (" << sub->subjectCode << ")" << endl;
                }
                s = s->next;
            }
            sub = sub->next;
        }

        if (!found)
            cout << "Student is not registered in any subject " << endl;
    }

    ~UniversitySystem() {
        SubjectNode* sub = head;
        while (sub) {
            StudentNode* s = sub->studentList;
            while (s) {
                StudentNode* toDelete = s;
                s = s->next;
                delete toDelete;
            }
            SubjectNode* toDeleteSub = sub;
            sub = sub->next;
            delete toDeleteSub;
        }
    }
};

int main() {
    UniversitySystem system;
    int choice;

    do {
        cout << endl << " University Subject Registration System " << endl;
        cout << "1- Add New Subject" << endl;
        cout << "2- Display All Subjects" << endl;
        cout << "3- Register Student in a Subject" <<endl;
        cout << "4- Display Students in a Subject" <<endl;
        cout << "5- Display Subjects of a Student" <<endl;
        cout << "6- Exit\n";
        cout << "Enter your choice = ";
        cin >> choice;

        switch (choice) {
            case 1: system.addSubject(); break;
            case 2: system.displaySubjects(); break;
            case 3: system.registerStudent(); break;
            case 4: system.displayStudentsInSubject(); break;
            case 5: system.displayStudentSubjects(); break;
            case 6: cout << "Exiting program" << endl; break;
            default: cout << "Invalid choice " << endl;
        }
    } while (choice != 6);
}
