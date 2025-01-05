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
    vector<string> uni_names = {"Riphah International University", "Fast University", "NUST","Air University","UET","UMT"};
    vector<string> domains = {"riphah", "fast", "nust","au","uet","umt"};
    vector<vector<string>> campus = {{"Raiwind Lahore","Gulberg Lahore","Islamabad","Faislabad"}, {"Lahore","Islamabad","Peshawar","Karachi"}, {"Islamabad"},{"Rawalpindi"},{"Peshawar","Lahore","Islamabad","Karachi"},{"Lahore"}};
    

    void displayUniversities() {
        cout << "Available Universities:\n";
        for(int i=0;i<uni_names.size();i++) {
            cout<<i+1<<". "<<uni_names.at(i)<<endl;
        }
    }
    int selectCampus(int index)  {
        switch (index)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
        
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

    cin.ignore(); 
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Select University"<<endl;
    uni.displayUniversities();
    int choice=0;
    bool select_university = false;
    do{
        
        cout<<"Enter a digit between 1 and "<<uni.uni_names.size()<<" :";
        if(choice>1&&choice<=uni.uni_names.size()) {
            select_university = true;
        }
        else {
            cout<<"University Not registered with Doc-Spot. Please try again.";
        }
    }while(!(select_university));
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

}

int main() {
    DoublyLinkedList userList;
    Universities uni;

    // Call the signupConsole function
    signupConsole(userList, uni);

    return 0;
}
