#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<regex>
using namespace std;

static int current_user =0;// for storing the id of the current user present

// class for storing the user's profile info or we can say student's info
class UserProfile{
    private:
    // for storing user id
    int user_id;
    
    string password, user_name, email, dob, address,department,program,uni_name,campus_location;
    int semester;
    bool is_profile_complete;
    public:
    //for auto incrementation of user_id we use static variable of user count
    static int user_count;
    // Default Constructor
    UserProfile() {
        user_id = user_count+1;// user id auto incrementing for each new user
        password="NULL";
        user_name="NULL";
        email="NULL";
        dob="NULL";
        address="NULL";
        department="NULL";
        program="NULL";
        uni_name="NULL";
        campus_location="NULL";
        int semester = -1;
        is_profile_complete = false;
    }
    // Constructor for SignUp function
    UserProfile(string name,string pass,string email,string uni) {
        user_id = user_count+1;// user id auto incrementing for each new user
        password=pass;
        user_name=name;
        this->email=email;
        dob="NULL";
        address="NULL";
        department="NULL";
        program="NULL";
        uni_name=uni;
        campus_location="NULL";
        int semester = -1;
        is_profile_complete = false;
    }
    // setter functions
    void setPassword(string pass) {
        password = pass;
    }
    void setUserName(string name) {
        user_name = name;
    }
    void setEmail(string email) {
        this->email = email;
    }
    void setDOB(string dob) {
        this->dob = dob;
    }
    void setDepartment(string depart) {
        department = depart;
    }
    void setProgram(string prog) {
        program = prog;
    }
    void setUniName(string uni) {
        uni_name = uni;
    }
    void setCampus(string camp) {
        campus_location = camp;
    }
    void setProfileCompleteCheck() {
        is_profile_complete = !(password=="NULL"||user_name=="NULL"||password=="NULL"||email=="NULL"||dob=="NULL"||department=="NULL"||program=="NULL"||uni_name=="NULL"||campus_location=="NULL");
    }

    //Getter Functions
    int getUserID() {
        return user_id;
    }
    string getUserName() {
        return user_name;
    }
    string getPassword() {
        return password;
    }
    string getEmail() {
        return email;
    }
    string getDOB() {
        return dob;
    }
    string getDepartment() {
        return department;
    }
    string getProgram() {
        return program;
    }
    string getUniName() {
        return uni_name;
    }
    string getCampusLocation() {
        return campus_location;
    }
    int getSemester() {
        return semester;
    }
    bool getProfileComleteCheck() {
        return is_profile_complete;
    }
    // function to display the profile
    void displayProfile() {
        system("cls");
        cout<<"---------------------------------------------------------\n";
        cout<<"|                     My Profile                        |\n";
        cout<<"---------------------------------------------------------\n";
        cout << "Name: " << user_name << endl;
        cout << "Email: " << email << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Address: " << address << endl;
        cout << "University Name: " << uni_name << endl;
        cout << "University Campus: " << campus_location << endl;
        cout << "Department: " << department << endl;
        cout << "Program: " << program << endl;
        cout << "Semester: " << semester << endl;
       
    }
};
// initializing the static counter variable for user id
int UserProfile::user_count = 0;

class Universities {
public:
    static vector<string> uni_names;
    static vector<string> domains ;
    static vector<vector<string>> campus;

    void displayUniversities() {
        cout << "Available Universities:\n";
        for(int i=0;i<uni_names.size();i++) {
            cout<<i+1<<". "<<uni_names.at(i)<<endl;
        }
        cout<<"Enter 0 to go back to homepage"<<endl;
    }
};

vector<string> Universities::uni_names = {"Riphah International University", "Fast University", "NUST","Air University","UET","UMT","Punjab University"};
vector<string> Universities::domains = {"riphah", "fast", "nust","au","uet","umt","pucit"};
vector<vector<string>> Universities::campus = {{"Raiwind Lahore","Gulberg Lahore","Islamabad","Faislabad"}, {"Lahore","Islamabad","Peshawar","Karachi"}, {"Islamabad"},{"Rawalpindi"},{"Peshawar","Lahore","Islamabad","Karachi"},{"Lahore"}};

// Doubly Linked List Node Structure for User Profile objects
struct UserNode {
    UserProfile user;
    UserNode* next;
    UserNode* prev;
    // User Node constructor
    UserNode(UserProfile userObject) {
        user = userObject;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked list class for storing head, tail pointer and all operations for UserProfile Object Linked List
class UserProfileLinkedList {
    public:
    UserNode* head;
    UserNode* tail;
    UserProfileLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    // Destructor
    ~UserProfileLinkedList() {
        UserNode* current = head;
        while (current) {
            UserNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    // Adding a user at the end of the Linked List
    void addUserAtEnd(UserProfile& user) {
        UserNode* newNode = new UserNode(user);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            UserNode* current = head;
            while(current->next!=nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
        }
    } 
    
};

int main() {
    UserProfileLinkedList userProfileLinkedList;

    return 0;
}
