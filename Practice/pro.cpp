#include <iostream>
#include <string>
using namespace std;

// Student structure to hold student information
struct Student {
    int rollNumber;
    string name;
    string department;
    int year;
    
    // Constructor for easy initialization
    Student(int roll = 0, string n = "", string dept = "", int y = 0)
        : rollNumber(roll), name(n), department(dept), year(y) {}
};

// BST Node structure
struct BSTNode {
    Student data;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(Student s) : data(s), left(nullptr), right(nullptr) {}
};

class StudentDatabase {
private:
    BSTNode* root;
    
    // Helper function to insert a student recursively
    BSTNode* insertHelper(BSTNode* node, Student student) {
        if (node == nullptr) {
            return new BSTNode(student);
        }
        
        if (student.rollNumber < node->data.rollNumber) {
            node->left = insertHelper(node->left, student);
        } else if (student.rollNumber > node->data.rollNumber) {
            node->right = insertHelper(node->right, student);
        }
        
        return node;
    }
    
    // Helper function to search for a student recursively
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
    
    // Helper function for inorder traversal (sorted order)
    void inorderHelper(BSTNode* node) {
        if (node == nullptr) return;
        
        inorderHelper(node->left);
        displayStudent(node->data);
        inorderHelper(node->right);
    }
    
    // Helper function for preorder traversal
    void preorderHelper(BSTNode* node) {
        if (node == nullptr) return;
        
        displayStudent(node->data);
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    
    // Helper function to find the minimum value node
    BSTNode* minValueNode(BSTNode* node) {
        BSTNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    
    // Helper function to delete a node recursively
    BSTNode* deleteHelper(BSTNode* node, int rollNumber) {
        if (node == nullptr) return node;
        
        if (rollNumber < node->data.rollNumber) {
            node->left = deleteHelper(node->left, rollNumber);
        } else if (rollNumber > node->data.rollNumber) {
            node->right = deleteHelper(node->right, rollNumber);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            
            // Node with two children: Get inorder successor
            BSTNode* temp = minValueNode(node->right);
            
            // Copy the inorder successor's content to this node
            node->data = temp->data;
            
            // Delete the inorder successor
            node->right = deleteHelper(node->right, temp->data.rollNumber);
        }
        return node;
    }
    
    // Helper function to display a student's information
    void displayStudent(const Student& s) {
        cout << "\nRoll Number: " << s.rollNumber << endl;
        cout << "Name: " << s.name << endl;
        cout << "Department: " << s.department << endl;
        cout << "Year: " << s.year << endl;
        cout << "--------------------------" << endl;
    }
    
public:
    StudentDatabase() : root(nullptr) {}
    
    // Insert a new student
    void insertStudent(Student student) {
        root = insertHelper(root, student);
        cout << "Student with roll number " << student.rollNumber 
             << " has been added to the database.\n";
    }
    
    // Search for a student by roll number
    void searchStudent(int rollNumber) {
        BSTNode* result = searchHelper(root, rollNumber);
        if (result != nullptr) {
            cout << "\nStudent found:\n";
            displayStudent(result->data);
        } else {
            cout << "\nStudent with roll number " << rollNumber 
                 << " not found in the database.\n";
        }
    }
    
    // Display all students in sorted order (inorder traversal)
    void displayAllStudentsSorted() {
        if (root == nullptr) {
            cout << "The database is empty.\n";
            return;
        }
        cout << "\nAll Students in Sorted Order (by Roll Number):\n";
        inorderHelper(root);
    }
    
    // Display students in preorder traversal
    void displayPreorder() {
        if (root == nullptr) {
            cout << "The database is empty.\n";
            return;
        }
        cout << "\nStudents in Preorder Traversal:\n";
        preorderHelper(root);
    }
    
    // Delete a student record
    void deleteStudent(int rollNumber) {
        BSTNode* node = searchHelper(root, rollNumber);
        if (node == nullptr) {
            cout << "Student with roll number " << rollNumber 
                 << " not found in the database.\n";
            return;
        }
        
        root = deleteHelper(root, rollNumber);
        cout << "Student with roll number " << rollNumber 
             << " has been deleted from the database.\n";
    }
    
    // Destructor to free memory
    ~StudentDatabase() {
        // Implement tree deletion here if needed
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nStudent Database Management System\n";
    cout << "1. Add a new student\n";
    cout << "2. Search for a student\n";
    cout << "3. Display all students (sorted by roll number)\n";
    cout << "4. Display students (preorder traversal)\n";
    cout << "5. Delete a student record\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Function to get student information from user
Student getStudentInfo() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cin.ignore(); // Clear the input buffer
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Department: ";
    getline(cin, s.department);
    cout << "Enter Year: ";
    cin >> s.year;
    return s;
}

int main() {
    StudentDatabase database;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                Student s = getStudentInfo();
                database.insertStudent(s);
                break;
            }
            case 2: {
                int roll;
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                database.searchStudent(roll);
                break;
            }
            case 3: {
                database.displayAllStudentsSorted();
                break;
            }
            case 4: {
                database.displayPreorder();
                break;
            }
            case 5: {
                int roll;
                cout << "Enter Roll Number to delete: ";
                cin >> roll;
                database.deleteStudent(roll);
                break;
            }
            case 6: {
                cout << "Exiting the program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 6);
    
    return 0;
}