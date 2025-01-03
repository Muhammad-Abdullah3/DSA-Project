#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

// Class to store user profile
class UserProfile {
private:
    int user_id;
    string name;
    string email;
    int age;
    string address;
    string department;
    string program;
    int semester;
    string university_name;
    string university_address;

public:
    static int user_count;

    UserProfile() : user_id(user_count++) {} // Constructor initializes unique user ID

    // Parameterized constructor for easy initialization
    UserProfile(string name, string email, int age, string address, string department, string program, int semester,
                string university_name, string university_address)
        : user_id(user_count++), name(name), email(email), age(age), address(address), department(department),
          program(program), semester(semester), university_name(university_name), university_address(university_address) {}

    // Getter functions
    int get_user_id() const { return user_id; }
    string get_name() const { return name; }
    string get_email() const { return email; }
    int get_age() const { return age; }
    string get_address() const { return address; }
    string get_department() const { return department; }
    string get_program() const { return program; }
    int get_semester() const { return semester; }
    string get_university_name() const { return university_name; }
    string get_university_address() const { return university_address; }

    // Display user profile
    void displayProfile() const {
        cout << "User ID: " << user_id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Department: " << department << endl;
        cout << "Program: " << program << endl;
        cout << "Semester: " << semester << endl;
        cout << "University Name: " << university_name << endl;
        cout << "University Address: " << university_address << endl;
    }
};

int UserProfile::user_count = 1; // Initialize static member

// Class for universities
class Universities {
public:
    vector<string> uni_names;
    vector<string> uni_addresses;

    Universities() {
        // Predefined list of universities
        uni_names = {"University A", "University B", "University C"};
        uni_addresses = {"Campus A (Pakistan)", "Campus B (Pakistan)", "Campus C (Pakistan)"};
    }

    void displayUniversities() const {
        cout << "Available Universities:\n";
        for (size_t i = 0; i < uni_names.size(); ++i) {
            cout << i + 1 << ". " << uni_names[i] << " - " << uni_addresses[i] << endl;
        }
    }

    bool selectUniversity(int index, string &selected_name, string &selected_address) const {
        if (index < 1 || index > (int)uni_names.size()) {
            cout << "Invalid selection.\n";
            return false;
        }
        selected_name = uni_names[index - 1];
        selected_address = uni_addresses[index - 1];
        return true;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    struct Node {
        UserProfile data;
        Node* prev;
        Node* next;

        Node(const UserProfile& user) : data(user), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add user to the end of the list
    void addUser(const UserProfile& user) {
        Node* newNode = new Node(user);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display all users
    void displayUsers() const {
        Node* current = head;
        if (!current) {
            cout << "No users in the list.\n";
            return;
        }

        int index = 1;
        while (current) {
            cout << "User " << index++ << ":\n";
            current->data.displayProfile();
            cout << "-------------------------\n";
            current = current->next;
        }
    }
};

// Signup function (handles profile creation)
void signup(DoublyLinkedList& userList, const string& name, const string& email, int age, const string& address,
            const string& department, const string& program, int semester, const string& university_name,
            const string& university_address) {
    UserProfile user(name, email, age, address, department, program, semester, university_name, university_address);
    userList.addUser(user);
    cout << "User added successfully.\n";
}

// Signup Console function (temporary local variables)
void signupConsole(DoublyLinkedList& userList, Universities& uni) {
    system("cls");
    string name, email, address, department, program, university_name, university_address;
    int age, semester;

    cin.ignore(); // Clear input buffer
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter department: ";
    getline(cin, department);
    cout << "Enter program: ";
    getline(cin, program);
    cout << "Enter semester: ";
    cin >> semester;
    cin.ignore();

    cout << "\nSelect a University:\n";
    uni.displayUniversities();
    int uni_choice;
    cout << "Enter your choice: ";
    cin >> uni_choice;

    if (uni.selectUniversity(uni_choice, university_name, university_address)) {
        signup(userList, name, email, age, address, department, program, semester, university_name, university_address);
    } else {
        cout << "Failed to add user due to invalid university selection.\n";
    }
}

int main() {
    DoublyLinkedList userList;
    Universities uni;

    // Call the signupConsole function
    signupConsole(userList, uni);

    return 0;
}
