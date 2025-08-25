
//STUDENT DATABASE MANAGEMENT SYSTEM
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    string course;
    float gpa;

    Student() : rollNumber(0), name(""), course(""), gpa(0.0) {}
    Student(int roll, string n, string c, float g) : rollNumber(roll), name(n), course(c), gpa(g) {}
};

struct BSTNode {
    Student data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Student student) : data(student), left(nullptr), right(nullptr) {}
};

class StudentDatabase {
private:
    BSTNode* root;

    BSTNode* insertHelper(BSTNode* node, Student student) {
        if (node == nullptr) {
            return new BSTNode(student);
        }

        if (student.rollNumber < node->data.rollNumber) {
            node->left = insertHelper(node->left, student);
        } else if (student.rollNumber > node->data.rollNumber) {
            node->right = insertHelper(node->right, student);
        } else {

            node->data = student;
        }

        return node;
    }

    BSTNode* searchHelper(BSTNode* node, int rollNumber) {
        if (node == nullptr || node->data.rollNumber == rollNumber) {
            return node;
        }

        if (rollNumber < node->data.rollNumber) {
            return searchHelper(node->left, rollNumber);
        } else {
            return searchHelper(node->right, rollNumber);
        }
    }

    void inorderHelper(BSTNode* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            displayStudent(node->data);
            inorderHelper(node->right);
        }
    }

    void preorderHelper(BSTNode* node) {
        if (node != nullptr) {
            displayStudent(node->data);
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    //find minimum value node
    BSTNode* findMin(BSTNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    //delete a student
    BSTNode* deleteHelper(BSTNode* node, int rollNumber) {
        if (node == nullptr) {
            return node;
        }

        if (rollNumber < node->data.rollNumber) {
            node->left = deleteHelper(node->left, rollNumber);
        } else if (rollNumber > node->data.rollNumber) {
            node->right = deleteHelper(node->right, rollNumber);
        } else {
            // Node to be deleted found
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }


            BSTNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data.rollNumber);
        }
        return node;
    }

    //display student information
    void displayStudent(const Student& student) {
        cout << "| " << setw(4) << student.rollNumber
             << " | " << setw(20) << student.name
             << " | " << setw(15) << student.course
             << " | " << setw(4) << fixed << setprecision(2) << student.gpa << " |" << endl;
    }

    //destroy the tree
    void destroyTree(BSTNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    StudentDatabase() : root(nullptr) {}

    // Destructor
    ~StudentDatabase() {
        destroyTree(root);
    }

    // Insert a student record
    void insertStudent(int rollNumber, string name, string course, float gpa) {
        Student newStudent(rollNumber, name, course, gpa);
        root = insertHelper(root, newStudent);
        cout << "Student with Roll Number " << rollNumber << " inserted successfully!" << endl;
    }

    // Search for a student by roll number
    void searchStudent(int rollNumber) {
        BSTNode* result = searchHelper(root, rollNumber);
        if (result != nullptr) {
            cout << "\nStudent Found:" << endl;
            cout << "+------+----------------------+-----------------+------+" << endl;
            cout << "| Roll |        Name          |     Course      | GPA  |" << endl;
            cout << "+------+----------------------+-----------------+------+" << endl;
            displayStudent(result->data);
            cout << "+------+----------------------+-----------------+------+" << endl;
        } else {
            cout << "Student with Roll Number " << rollNumber << " not found!" << endl;
        }
    }

    // Display all students in sorted order (inorder traversal)
    void displayAllStudents() {
        if (root == nullptr) {
            cout << "No students in the database!" << endl;
            return;
        }

        cout << "\nAll Students (Sorted by Roll Number):" << endl;
        cout << "+------+----------------------+-----------------+------+" << endl;
        cout << "| Roll |        Name          |     Course      | GPA  |" << endl;
        cout << "+------+----------------------+-----------------+------+" << endl;
        inorderHelper(root);
        cout << "+------+----------------------+-----------------+------+" << endl;
    }

    // Display all students in preorder traversal
    void displayPreorder() {
        if (root == nullptr) {
            cout << "No students in the database!" << endl;
            return;
        }

        cout << "\nAll Students (Preorder Traversal):" << endl;
        cout << "+------+----------------------+-----------------+------+" << endl;
        cout << "| Roll |        Name          |     Course      | GPA  |" << endl;
        cout << "+------+----------------------+-----------------+------+" << endl;
        preorderHelper(root);
        cout << "+------+----------------------+-----------------+------+" << endl;
    }

    // Delete a student record
    void deleteStudent(int rollNumber) {
        BSTNode* search = searchHelper(root, rollNumber);
        if (search == nullptr) {
            cout << "Student with Roll Number " << rollNumber << " not found!" << endl;
            return;
        }

        root = deleteHelper(root, rollNumber);
        cout << "Student with Roll Number " << rollNumber << " deleted successfully!" << endl;
    }

    bool isEmpty() {
        return root == nullptr;
    }
};
void displayMenu() {
    cout << "\n========== Student Database Management System ==========" << endl;
    cout << "1. Insert Student Record" << endl;
    cout << "2. Search Student by Roll Number" << endl;
    cout << "3. Display All Students (Sorted)" << endl;
    cout << "4. Display All Students (Preorder)" << endl;
    cout << "5. Delete Student Record" << endl;
    cout << "6. Exit" << endl;
    cout << "=======================================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    StudentDatabase db;
    int choice;

    cout << "Initializing database with sample data..." << endl;
    db.insertStudent(101, "Alice Johnson", "Computer Science", 3.8);
    db.insertStudent(95, "Bob Smith", "Mathematics", 3.6);
    db.insertStudent(120, "Charlie Brown", "Physics", 3.9);
    db.insertStudent(88, "Diana Prince", "Chemistry", 3.7);
    db.insertStudent(110, "Edward Norton", "Biology", 3.5);

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int rollNumber;
                string name, course;
                float gpa;

                cout << "\nEnter Student Details:" << endl;
                cout << "Roll Number: ";
                cin >> rollNumber;
                cin.ignore(); // Clear the input buffer

                cout << "Name: ";
                getline(cin, name);

                cout << "Course: ";
                getline(cin, course);

                cout << "GPA: ";
                cin >> gpa;

                db.insertStudent(rollNumber, name, course, gpa);
                break;
            }

            case 2: {
                int rollNumber;
                cout << "\nEnter Roll Number to search: ";
                cin >> rollNumber;
                db.searchStudent(rollNumber);
                break;
            }

            case 3: {
                db.displayAllStudents();
                break;
            }

            case 4: {
                db.displayPreorder();
                break;
            }

            case 5: {
                int rollNumber;
                cout << "\nEnter Roll Number to delete: ";
                cin >> rollNumber;
                db.deleteStudent(rollNumber);
                break;
            }

            case 6: {
                cout << "Thank you for using Student Database Management System!" << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}