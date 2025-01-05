#include <iostream>
#include <string>
#include<vector>
#include<conio.h>
using namespace std;

// Function declarations
void displayHomePage();
void login();
void signUp();
void myProfile();
void myDocs();
void myWallet();
void discussionForum();
void displayFirstPage();
void aboutUs();
bool validateEmail(string email,int uni_index);
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
        cout<<"Enter 0 to go back to homepage"<<endl;
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
    void addUser(UserProfile& user) {
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
    void displayUsers() {
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
        if(choice>=0&&choice<=uni.uni_names.size()) {
            select_university = true;
        }
        else {
            cout<<"University Not registered with Doc-Spot. Please try again.";
        }
    }while(!(select_university));
    if(choice==0) {
        displayFirstPage();
    }
    bool validEmail=false;
    do{
        cout << "Enter email: ";
        getline(cin, email);
    }while(!(validEmail));
}

int main() {
    displayFirstPage();
    return 0;
}
void displayFirstPage() {
    int choice;

    cout << "\n=== Welcome to DOC-SPOT ===\n";
    cout << "1. Login\n";
    cout << "2. Sign Up\n";
    cout << "3. About Us\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
        login();
        break;
    case 2:
        signUp();
        break;
    case 3:
        aboutUs();
        break;
    case 4:
        cout << "Exiting DOC-SPOT. Goodbye!\n";
        exit(0);
    default:
        cout << "Invalid choice. Please try again.\n";
        displayFirstPage();
    }
}
// Login Function
void login() {
    string email, password;

    cout << "\n--- Login ---\n";
    cout << "Enter University Email: ";
    cin >> email;
    cout << "Enter Password: ";
    cin >> password;

    // Simulating successful login for demo purposes
    cout << "Login successful!\n";
    displayHomePage();
}

// Sign Up Function
void signUp() {
    string firstName, lastName, university, email, password, confirmPassword;

    cout << "\n--- Sign Up ---\n";
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "University: ";
    cin >> university;
    cout << "University Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;
    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (password == confirmPassword) {
        cout << "Account created successfully!\n";
    } else {
        cout << "Passwords do not match. Try again.\n";
    }
}
// Home Page
void displayHomePage() {
    int choice;

    while (true) {
        cout << "\n=== DOC-SPOT Home Page ===\n";
        cout << "1. My Profile\n";
        cout << "2. My Docs\n";
        cout << "3. My Wallet\n";
        cout << "4. Discussion Forum\n";
        cout << "5. Log Out\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myProfile();
            break;
        case 2:
            myDocs();
            break;
        case 3:
            myWallet();
            break;
        case 4:
            discussionForum();
            break;
        case 5:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

// My Profile Function
void myProfile() {
    cout << "\n--- My Profile ---\n";
    cout << "Name: John Doe\n";
    cout << "Email: johndoe@university.edu\n";
    cout << "Age: 21\n";
    cout << "Department: BSCS\n";
    cout << "Program: BSCS\n";
    cout << "Semester: 3\n";
    cout << "University Address: UET Lahore\n";
    cout << "Role: Student\n";
}

// My Docs Function
void myDocs() {
    cout << "\n--- My Docs ---\n";
    cout << "1. Uploaded Documents\n";
    cout << "2. Downloaded Documents\n";
    cout << "3. Upload a New Document\n";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Displaying uploaded documents...\n";
        break;
    case 2:
        cout << "Displaying downloaded documents...\n";
        break;
    case 3:
        cout << "Feature to upload a new document...\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
}

// My Wallet Function
void myWallet() {
    cout << "\n--- My Wallet ---\n";
    cout << "1. Current Balance: $100\n";
    cout << "2. Deposit Balance\n";
    cout << "3. Withdraw Balance\n";
    cout << "4. Take a Loan\n";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Your current balance is $100.\n";
        break;
    case 2:
        cout << "Feature to deposit balance...\n";
        break;
    case 3:
        cout << "Feature to withdraw balance...\n";
        break;
    case 4:
        cout << "Feature to take a loan...\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
}

// Discussion Forum Function
void discussionForum() {
    cout << "\n--- Discussion Forum ---\n";
    cout << "Feature to start and join discussions will be here.\n";
}

void aboutUs() {
    cout << "\n--- About Us ---\n";

}