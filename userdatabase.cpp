#include <iostream>
#include <string>
#include <vector>
#include <mysql/jdbc.h> // MySQL Connector/C++ header
#include <conio.h>
using namespace std;

// Include the MySQL namespace for convenience
using namespace sql::mysql;

// Class to store user profile (unchanged)
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

    UserProfile() : user_id(user_count++) {}

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
};

int UserProfile::user_count = 1;

// Class for universities (unchanged)
class Universities {
public:
    vector<string> uni_names;
    vector<string> uni_addresses;

    Universities() {
        uni_names = {"University A", "University B", "University C"};
        uni_addresses = {"Campus A (Pakistan)", "Campus B (Pakistan)", "Campus C (Pakistan)"};
    }

    void displayUniversities() const {
        for (size_t i = 0; i < uni_names.size(); ++i) {
            cout << i + 1 << ". " << uni_names[i] << " - " << uni_addresses[i] << endl;
        }
    }

    bool selectUniversity(int index, string &selected_name, string &selected_address) const {
        if (index < 1 || index > (int)uni_names.size()) return false;
        selected_name = uni_names[index - 1];
        selected_address = uni_addresses[index - 1];
        return true;
    }
};

// Doubly linked list class (unchanged)
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

    void addUser(const UserProfile& user) {
        Node* newNode = new Node(user);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
};

// Function to insert data into MySQL database
void insertIntoDatabase(const UserProfile& user) {
    try {
        // Establish MySQL connection
        sql::Driver* driver = get_driver_instance();
        unique_ptr<sql::Connection> conn(driver->connect("tcp://127.0.0.1:3306", "root", "password"));
        conn->setSchema("UserDB");

        // Prepare and execute SQL statement
        unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("INSERT INTO Users (name, email, age, address, department, program, semester, university_name, university_address) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)"));
        pstmt->setString(1, user.get_name());
        pstmt->setString(2, user.get_email());
        pstmt->setInt(3, user.get_age());
        pstmt->setString(4, user.get_address());
        pstmt->setString(5, user.get_department());
        pstmt->setString(6, user.get_program());
        pstmt->setInt(7, user.get_semester());
        pstmt->setString(8, user.get_university_name());
        pstmt->setString(9, user.get_university_address());
        pstmt->execute();

        cout << "Data inserted into database successfully.\n";
    } catch (sql::SQLException& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// Signup function
void signup(DoublyLinkedList& userList, const string& name, const string& email, int age, const string& address,
            const string& department, const string& program, int semester, const string& university_name,
            const string& university_address) {
    UserProfile user(name, email, age, address, department, program, semester, university_name, university_address);
    userList.addUser(user);
    insertIntoDatabase(user); // Store in database
}

// Console signup function
void signupConsole(DoublyLinkedList& userList, Universities& uni) {
    system("cls");
    string name, email, address, department, program, university_name, university_address;
    int age, semester;

    cin.ignore();
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
        cout << "Invalid university selection.\n";
    }
}

int main() {
    DoublyLinkedList userList;
    Universities uni;
    signupConsole(userList, uni);
    return 0;
}
