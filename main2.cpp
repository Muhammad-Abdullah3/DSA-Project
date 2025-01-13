#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<regex>
using namespace std;

static int current_user =1;// for storing the id of the current user present

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
        user_id = UserProfile::user_count;// user id auto incrementing for each new user
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
        user_id = UserProfile::user_count;// user
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
    void setAddress(string address) {
        this->address = address;
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
    void setSemester(int sem) {
        semester = sem;
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
    string getAddress() {
        return address;
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
int UserProfile::user_count = 1;

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
vector<string> Universities::domains = {"students.riphah", "fast", "nust","au","uet","umt","pucit"};
vector<vector<string>> Universities::campus = {{"Raiwind Lahore","Gulberg Lahore","Islamabad","Faislabad"}, {"Lahore","Islamabad","Peshawar","Karachi"}, {"Islamabad"},{"Rawalpindi"},{"Peshawar","Lahore","Islamabad","Karachi"},{"Lahore"}};

// Doubly Linked List UserNode Structure for User Profile objects
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



void signupConsole(UserProfileLinkedList& userList);
void displayHomePage(UserProfileLinkedList& userList);
void login(UserProfileLinkedList& userList);
void myDocs();
void myWallet();
void discussionForum();
void displayFirstPage(UserProfileLinkedList& userList);
void aboutUs();
bool validateEmail(string email,int uni_index);
bool validateEmailLogin(string email);
void signUp(UserProfileLinkedList& userList,  string& name, string& email,  string& password,string& uni_name);
void currentProfile(UserProfileLinkedList& userList);
void editProfile(UserProfileLinkedList& userList,UserNode* node);
bool validDOB(string dob);
bool isLeapYear(int year);
int showAllCampus(string uni);















int main() {
    UserProfileLinkedList userList;
    displayFirstPage(userList);
    return 0;
}





















void signupConsole(UserProfileLinkedList& userList) {
    system("cls");
    Universities uni;
    string name, email, password,confirmPass;
    bool checkName;
    do {
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);

    checkName = true;

    for (int i = 0; i < name.length(); i++) {
      if (!((name.at(i) >= 'A' && name.at(i) <= 'Z') ||
            (name.at(i) >= 'a' && name.at(i) <= 'z')||(name.at(i)==' '))) {
        cout << "A name must only consist of alphabets. Please Enter a valid name." << endl;
        checkName = false;
        break;
      }
    }
  } while (!checkName);
    cout << "Select University"<<endl;
    uni.displayUniversities();  
    int choice=0;
    bool select_university = false;
    do{ 
        cout<<"Enter a digit between 1 and "<<Universities::uni_names.size()<<" :";
        cin>>choice;
        if(choice>=0&&choice<=Universities::uni_names.size()) {
            select_university = true;
        }
        else {
            cout<<"University Not registered with Doc-Spot. Please try again."<<endl;
        }
    }while(!(select_university));
    if(choice==0) {
        displayFirstPage(userList);
    }
    do{
        cin.ignore();
        cout << "Enter email: ";
        getline(cin, email);
        cout<<"";
        if (validateEmail(email, choice)) {
            break;
        }
        else {
            cout << "You should only use University Email. Please try again." << endl;

        }
    } while (!(validateEmail(email, choice)));
    cin.ignore();
    cout << "Enter Passowrd: ";
    getline(cin, password);
    cout << "Confirm Password: ";
    getline(cin, confirmPass);
    if (password == confirmPass) {
        signUp(userList, name, email, password, Universities::uni_names.at(choice - 1));
        cout << "Successful Account Creation";
        system("cls");
        displayHomePage(userList);
    }
}

void displayFirstPage(UserProfileLinkedList& userList) {
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
        login(userList);
        break;
    case 2:
        signupConsole(userList);
        break;
    case 3:
        aboutUs();
        break;
    case 4:
        cout << "Exiting DOC-SPOT. Goodbye!\n";
        exit(0);
    default:
        cout << "Invalid choice. Please try again.\n";
        displayFirstPage(userList);
    }
}

void login(UserProfileLinkedList& userList) {
    string em, pass;
    system("cls");
    cout << "\n--- Login ---\n";
    cout << "Enter University Email: ";
    cin.ignore();
    getline(cin,em);
    if(!(validateEmailLogin(em))) {
        cout<<"Please enter your official university Email.Try Again";
        login(userList);
    }
    cout << "Enter Password: ";
    cin.ignore();
     getline(cin,pass); 
    bool checkEmail = false;
    UserNode* temp = userList.head;
    while (temp!=nullptr) {
        if (temp->user.getEmail() == em) {
            checkEmail =true;
            break;
        }
        temp = temp->next;
    }
    if(temp->user.getPassword()==pass && checkEmail){    
    cout << "Login successful!\n";
    current_user= temp->user.getUserID();
    displayHomePage(userList); 
    }
    else{
        cout<<"Incorrect Email OR Password."<<endl;
        login(userList);
    }
}

void displayHomePage(UserProfileLinkedList& userList) {
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
            currentProfile(userList);
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
            cout<<"...Sucessfully Logged Out...\n\n\n\n\n";
            system("cls");
            displayFirstPage(userList);
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}



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

void discussionForum() {
    cout << "\n--- Discussion Forum ---\n";
    cout << "Feature to start and join discussions will be here.\n";
}

void aboutUs(){
cout<<"Doc-Spot is a document sharing platform that enables students of different university from different Academic Backgrounds having different interests to come together and help each other in their Academic journey and solve many of the problems, they face. Doc-Spot also encourges the students who are still struggling and learning by producing a stream of income with the help of documents they have shared on the platform. Here, on this platform, a student has the power to either giveaway their work freely or at some minimal cost, which will help them by giving them a steady means of income without extra effort. The only thing you need to Register yoursekf on Doc-Spot is your University E-mail, a will to achieve something and connect with fellow learners.";
}

bool validateEmail(string email,int uni_index){
    string pattern = R"(^[\w\.-]+@\.)" + Universities::domains.at(uni_index-1) + R"(\.edu\.pk$)";
    regex emailRegex(pattern);
    return regex_match(email, emailRegex);
}

void signUp(UserProfileLinkedList& userList, string& name, string& email, string& password, string& uni_name) {
    UserProfile user(name, password, email, uni_name); // Create the user profile
    userList.addUserAtEnd(user); // Add user to the linked list
    current_user = user.getUserID(); // Set the current user ID
    UserProfile::user_count++; // Increment user count

    cout << "User added with ID: " << user.getUserID() << ", Name: " << user.getUserName() << endl;

}

bool validateEmailLogin(string email) {
    string basePattern = R"(^[\w\.-]+@\.)";
    string suffix = R"(\.edu\.pk$)";
    
    for (auto domain : Universities::domains) {
        string fullPattern = basePattern + domain + suffix;
        regex emailRegex(fullPattern);
        if (regex_match(email, emailRegex)) {
            return true; 
        }
    }
    return false; 
}

void currentProfile(UserProfileLinkedList& userList) {
    if (current_user <= 0) {
        cout << "No user is currently logged in.\n";
        return;
    }
    
    UserNode* current = userList.head;
    // Search for the user with the ID matching current_user
    while (current) {
        if (current->user.getUserID() == current_user) {
            // Display the profile of the current user
            current->user.displayProfile();
            // editProfile(userList,current);
            // return;
        }
        current = current->next;
    }
    cout << "Error: Current user profile not found.\n";
}

void editProfile(UserProfileLinkedList& userList,UserNode* current) {
    int choice = -1;
    if(current->user.getProfileComleteCheck()) {
        cout<<"Press 1 to edit your profile."<<endl;
        cout<<"Press 2 to go back to homepage."<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice) {
            case 1:
                system("cls");
                int ch;
                bool validChoice;
                cout<<current->user.getUserName()<<endl;
                cout<<"Do you want to edit your Name? Press 1 for yes and 0 for No:";
                cin>>ch;
                do{
                    validChoice=false;
                    if(ch==1) {
                        string name;
                        bool checkName=true;
                        do {
                        cin.ignore();
                        cout << "Enter your new name: ";
                        getline(cin, name);
                        checkName = true;
                            for (int i = 0; i < name.length(); i++) {
                                if (!((name.at(i) >= 'A' && name.at(i) <= 'Z') ||
                                        (name.at(i) >= 'a' && name.at(i) <= 'z')||(name.at(i)==' '))) {
                                    cout << "A name must only consist of alphabets. Please Enter a valid name." << endl;
                                    checkName = false;
                                    break;
                                }
                            }
                        } while (!checkName);
                        current->user.setUserName(name);
                        validChoice=true;
                        break;
                    }
                    else if(ch==0) {
                        validChoice=true;
                        break;
                    }
                    else {
                        cout<<"Invalid choice. Please enter 1 for yes and 0 for No."<<endl;
                    }
                }while(!validChoice);

                cout<<current->user.getDOB()<<endl;
                cout<<"Do you want to edit your Date of Birth? Press 1 for yes and 0 for No:";
                cin>>ch;
                do{
                    validChoice=false;
                    if(ch==1) {
                        string DOB;
                        bool checkDOB=true;
                        do {
                        
                        cin.ignore();
                        cout << "Enter your DOB in \'DD-MM-YYYY\' Format: ";
                        getline(cin, DOB);
                            if(!validDOB(DOB)) {
                                checkDOB=false;
                            }
                        } while (!checkDOB);
                        current->user.setDOB(DOB);
                        validChoice=true;
                        break;
                    }
                    else if(ch==0) {
                        validChoice=true;
                        break;
                    }
                    else {
                        cout<<"Invalid choice. Please enter 1 for yes and 0 for No."<<endl;
                    }
                }while(!validChoice);


                cout<<current->user.getAddress()<<endl;
                cout<<"Do you want to edit your Address? Press 1 for yes and 0 for No:";
                cin>>ch;
                do{
                    validChoice=false;
                    if(ch==1) {
                        string address;
                        cin.ignore();
                        cout << "Enter your new Address";
                        getline(cin, address);
                        current->user.setAddress(address);
                        validChoice=true;
                    }
                    else if(ch==0) {
                        validChoice=true;
                        break;
                    }
                    else {
                        cout<<"Invalid choice. Please enter 1 for yes and 0 for No."<<endl;
                    }
                }while(!validChoice);


                cout<<current->user.getDepartment()<<endl;
                cout<<"Do you want to edit your Department? Press 1 for yes and 0 for No:";
                cin>>ch;
                do{
                    validChoice=false;
                    if(ch==1) {
                        string department;
                        cin.ignore();
                        cout << "Enter your new Department";
                        getline(cin, department);
                        current->user.setDepartment(department);
                        validChoice=true;
                    }
                    else if(ch==0) {
                        validChoice=true;
                        break;
                    }
                    else {
                        cout<<"Invalid choice. Please enter 1 for yes and 0 for No."<<endl;
                    }
                }while(!validChoice);


                cout<<current->user.getProgram()<<endl;
                cout<<"Do you want to edit your Program? Press 1 for yes and 0 for No:";
                cin>>ch;
                do{
                    validChoice=false;
                    if(ch==1) {
                        string program;
                        cin.ignore();
                        cout << "Enter your new Program";
                        getline(cin, program);
                        current->user.setProgram(program);
                        validChoice=true;
                    }
                    else if(ch==0) {
                        validChoice=true;
                        break;
                    }
                    else {
                        cout<<"Invalid choice. Please enter 1 for yes and 0 for No."<<endl;
                    }
                }while(!validChoice);

                cout<<current->user.getSemester()<<endl;
                cout<<"Do you want to edit your Semester? Press 1 for yes and 0 for No:";
                cin>>ch;
                do{
                    validChoice=false;
                    if(ch==1) {
                        int semester;
                        cin.ignore();
                        cout << "Enter your new Semester";
                        cin>>semester;
                        current->user.setSemester(semester);
                        validChoice=true;
                    }
                    else if(ch==0) {
                        validChoice=true;
                        break;
                    }
                    else {
                        cout<<"Invalid choice. Please enter 1 for yes and 0 for No."<<endl;
                    }
                }while(!validChoice);


                cout<<current->user.getCampusLocation()<<endl;
                cout<<"Do you want to edit your Campus Location? Press 1 for yes and 0 for No:";
                cin>>ch;
                do{
                    validChoice=false;
                    if(ch==1) {
                        string campus_location;
                        campuscount:
                        int ch_camp;
                        cin.ignore();
                        cout << "Chose your Campus from the given campuses.";
                        int uni_index = showAllCampus(current->user.getUniName());
                        int campus_count= Universities::campus.at(uni_index).size();
                        cout<<"Enter the number of your campus: ";
                        cin>>ch_camp;
                        if(ch_camp>0 && ch_camp<=campus_count) {
                            current->user.setCampus(Universities::campus.at(uni_index).at(ch_camp-1));
                        }
                        else {  
                            cout<<"Invalid Choice Please Only chose from the given campuses.";
                            goto campuscount;
                        }
                    }
                    else if(ch==0) {
                        validChoice=true;
                        break;
                    }
                    else {
                        cout<<"Invalid choice. Please enter 1 for yes and 0 for No."<<endl;
                    }
                }while(!validChoice);
                break;
            case 2:
                displayHomePage(userList);
                break;
            default:
                cout<<"Invalid Choice Please Try Again."<<endl;
                editProfile(userList,current);
        }
    }
    

}

bool validDOB(string dob) {
  if (dob.size() != 10) {
    return false;
  }

  int day = stoi(dob.substr(0, 2));
  int month = stoi(dob.substr(3, 2));
  int year = stoi(dob.substr(6, 4));

  if (year < 1947 || year > 2008) {
    return false;
  }

  if (month < 1 || month > 12) {
    return false;
  }

  // Check for valid days based on month and leap year
  if (day < 1 || day > 31) {
    return false;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      return false;
    }
  } else if (month == 2) {
    if (isLeapYear(year) && day <= 29) {
      // valid for leap year
    } else if (!isLeapYear(year) && day <= 28) {
      // valid for non-leap year
    } else {
      return false;
    }
  }

  return true;
}

// Function to check if a year is a leap year
bool isLeapYear(int year) {
  if (year % 400 == 0) {
    return true;
  } else if (year % 100 == 0) {
    return false;
  } else if (year % 4 == 0) {
    return true;
  } else {
    return false;
  }
}

int showAllCampus(string uni) {
    int index=-1;
    for(int i=0;i<Universities::uni_names.size();i++) {
        if(Universities::uni_names[i]==uni) {
            index=i;
        }
    }
    cout << "Campus Locations: "<< endl;
    int i=0;
    for(;i<Universities::campus.at(index).size();i++) {
        cout <<i<<". "<< Universities::campus.at(index).at(i) << endl;
    }
    return index;
}