#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<regex>
#include<ctime>
#include <windows.h>
#include <commdlg.h> 
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
    ////
    vector<int> downloaded_document_id;/// We will use this 
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
        is_profile_complete = !(password=="NULL"||user_name=="NULL"||password=="NULL"||email=="NULL"||dob=="NULL"||department=="NULL"||program=="NULL"||uni_name=="NULL"||campus_location=="NULL"|| semester==-1);
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
    bool getProfileCompleteCheck() {
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


//// Document Class and nodes and linked list for handling document
class Documents {
private:
    int document_id;
    int user_id;
    string instructor;
    string academic_year;
    string course_name;
    int semester;

    string discription;
    string uploaded_date;
    string uni_name;
    string title;
    string file_path;
    vector<string> tags;
    int downloads;


public:
    static int doc_counts;
    Documents() {
        document_id=Documents::doc_counts;
        downloads = 0;
        Documents::doc_counts++;
    }

    // Setters
    void setDocument_id(int document_id) {
        this->document_id = document_id;
    }

    void setUser_id(int user_id) {
        this->user_id = user_id;
    }

    void setInstructor(string instructor) {
        this->instructor = instructor;
    }

    void setAcademic_year(string academic_year) {
        this->academic_year = academic_year;
    }

    void setCourse_name(string course_name) {
        this->course_name = course_name;
    }

    void setSemester(int semester) {
        this->semester = semester;
    }
    void setUniName(string uni_name) {
        this->uni_name = uni_name;
    }


    void setDiscription(string discription) {
        this->discription = discription;
    }

    void setUploadedDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        uploaded_date = (ltm->tm_mday < 10 ? "0" : "") + to_string(ltm->tm_mday) + "-" + (ltm->tm_mon + 1 < 10 ? "0" : "") + to_string(ltm->tm_mon + 1) + "-" + to_string(1900 + ltm->tm_year);
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setFilePath(string file_path) {
        this->file_path = file_path;
    }


    void addTag(string tag) {
        this->tags.push_back(tag);
    }



    // Increment Methods

    void addDownload() {
        downloads++;
    }

    // Getters
    int getDocumentID()  {
        return document_id;
    }
    int getUserID()  {
        return user_id;
    }
    string getInstructor()  {
        return instructor;
    }
    string getCourseName() {
        return course_name;
    }
    string getUniName() {
        return uni_name;
    }
    string getAcademicYear() {
        return academic_year;
    }
    int getSemester() {
        return semester;
    }
    string getTitle()  {
        return title;
    }
    string getFilePath()  {
        return file_path;
    }

    vector<string> getTags()  {
        return tags;
    }


    string getUploadedDate()  {
        return uploaded_date;
    }
    int getDownloads() {
        return downloads;
    }



    // Display Document Information
    void displayDocumentInfo() {
        cout << "Document ID: " << document_id << endl;
        cout << "User ID: " << user_id << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Academic Year: " << academic_year << endl;
        cout << "Course Name: " << course_name << endl;
        cout << "Semester: " << semester << endl;
        cout << "Description: " << discription << endl;
        cout << "Uploaded Date: " << uploaded_date << endl;
        cout << "Title: " << title << endl;
        cout << "File Path: " << file_path << endl;
        cout << "Downloads: " << downloads << endl;

    }
};
int Documents::doc_counts=1;

// Doubly Linked List document Node Structure for Documents objects
struct DocNode {
    Documents doc;
    DocNode* next;
    DocNode* prev;
    // User Node constructor
    DocNode(Documents document) {
        doc = document;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked list class for storing head, tail pointer and all operations for Documents Object Linked List
class DocumentLinkedList {
    public:
    DocNode* head;
    DocNode* tail;
    DocumentLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    // Destructor
    ~DocumentLinkedList() {
        DocNode* current = head;
        while (current) {
            DocNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    // Adding a user at the end of the Linked List
    void addUserAtEnd(Documents& doc) {
        DocNode* newNode = new DocNode(doc);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            DocNode* current = head;
            while(current->next!=nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
        }
    } 
    
};

struct StackDocNode {
    Documents doc;
    StackDocNode* next;

    // Constructor for stack node
    StackDocNode(Documents document) {
        doc = document;
        next = nullptr;
    }
};

class DocumentStack {
private:
    StackDocNode* top; // Pointer to the top of the stack

public:
    DocumentStack() {
        top = nullptr; // Initialize stack as empty
    }

    ~DocumentStack() {
        while (top != nullptr) {
            StackDocNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Push a document onto the stack
    void push(Documents& doc) {
        StackDocNode* newNode = new StackDocNode(doc);
        newNode->next = top; // Link new node to current top
        top = newNode;       // Update top pointer
    }

    // Pop a document from the stack
    Documents pop() {
        if (top == nullptr) {
            throw runtime_error("No Document Found");
        }
        StackDocNode* temp = top; // Get the top node
        Documents poppedDoc = temp->doc;
        top = top->next;       // Update top to next node
        delete temp;           // Free the popped node
        return poppedDoc;      // Return the popped document
    }

    // Peek at the top document without removing it
    Documents peek() {
        if (top == nullptr) {
            throw runtime_error("No Document Found");
        }
        return top->doc; // Return the document at the top
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display all documents in the stack
    void displayStack() {
        if (isEmpty()) {
            cout << "The stack is empty." << endl;
            return;
        }
        while (top != nullptr) {
            Documents doc = pop();
            doc.displayDocumentInfo();
            cout << "----------------------------" << endl;
        }
    }
};




















void signupConsole(UserProfileLinkedList& userList,DocumentLinkedList& docList);
void displayHomePage(UserProfileLinkedList& userList,DocumentLinkedList& docList);
void login(UserProfileLinkedList& userList,DocumentLinkedList& docList);
void myDocs(UserProfileLinkedList& userList,DocumentLinkedList& docList);
void myWallet();
void discussionForum();
void displayFirstPage(UserProfileLinkedList& userList,DocumentLinkedList& docList);
void aboutUs();
bool validateEmail(string email,int uni_index);
bool validateEmailLogin(string email);
void signUp(UserProfileLinkedList& userList,  string& name, string& email,  string& password,string& uni_name);
void currentProfile(UserProfileLinkedList& userList,DocumentLinkedList& docList);
void completeProfile(UserProfileLinkedList& userList,DocumentLinkedList& docList);
void editProfile(UserProfileLinkedList& userList,DocumentLinkedList& docList,UserNode* node);
bool validDOB(string dob);
bool isLeapYear(int year);
int showAllCampus(string uni);
void displayUploadedDocuments(UserProfileLinkedList& userList, DocumentLinkedList& docList);
void filterByUni(UserProfileLinkedList& userList, DocumentLinkedList& docList);
void uploadDocument(UserProfileLinkedList& userList, DocumentLinkedList& docList);
void filterBySemester(UserProfileLinkedList& userList, DocumentLinkedList& docList);
void explore(UserProfileLinkedList& userList, DocumentLinkedList& docList);
void filterByTags(UserProfileLinkedList& userList, DocumentLinkedList& docList);

void showDocuments(UserProfileLinkedList& userList, DocumentLinkedList& docList);















int main() {
    UserProfileLinkedList userList;
    DocumentLinkedList docList;
    displayFirstPage(userList,docList);
    return 0;
}





















void signupConsole(UserProfileLinkedList& userList,DocumentLinkedList& docList) {
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
        displayFirstPage(userList,docList);
    }
    do {
        cin.ignore();
        cout << "Enter email: ";
        getline(cin, email);
        

        if (validateEmail(email, choice)) {
            break;
        } else {
            cout << "You should only use a University Email. Please try again." << endl;
        }
    } while (true);

    cin.ignore();
    cout << "Enter Passowrd: ";
    getline(cin, password);
    cout << "Confirm Password: ";
    getline(cin, confirmPass);
    if (password == confirmPass) {
        signUp(userList, name, email, password, Universities::uni_names.at(choice - 1));
        cout << "Successful Account Creation";
    
        system("cls");
        completeProfile(userList,docList);    
    }
}

void displayFirstPage(UserProfileLinkedList& userList,DocumentLinkedList& docList) {
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
        login(userList,docList);
        break;
    case 2:
        signupConsole(userList,docList);
        break;
    case 3:
    int ch;
    bool validch;
        aboutUs();
        cout<<"Enter \"0\" to Go Back and \"1\" to exit from Doc-Spot.";
        do{
          validch=true;
          cin>>ch;
          switch(ch){
            case 0:
                displayFirstPage(userList,docList);
                break;
            case 1:
                exit(0);
                break;
                default:
                cout<<"Invalid choice.";
                validch=false;
          }
        }while(!validch);
        break;
    case 4:
        cout << "Exiting DOC-SPOT. Goodbye!\n";
        exit(0);
    default:
        cout << "Invalid choice. Please try again.\n";
        displayFirstPage(userList,docList);
    }
}

void login(UserProfileLinkedList& userList,DocumentLinkedList& docList) {
    string em, pass;
    system("cls");
    cout << "\n--- Login ---\n";
    cout << "Enter University Email: ";
    cin.ignore();
    getline(cin,em);
    if(!(validateEmailLogin(em))) {
        cout<<"Please enter your official university Email.Try Again";
        login(userList,docList);
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
    displayHomePage(userList,docList); 
    }
    else{
        cout<<"Incorrect Email OR Password."<<endl;
        login(userList,docList);
    }
}

void displayHomePage(UserProfileLinkedList& userList,DocumentLinkedList& docList) {
    system("cls");
    int choice;
    while (true) {
        cout << "\n=== DOC-SPOT Home Page ===\n";
        cout << "1. My Profile\n";
        cout << "2. My Docs\n";
        cout << "3. Explore\n";
        cout << "4. Log Out\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            currentProfile(userList,docList);
            break;
        case 2:
            myDocs(userList,docList);
            break;
        case 3:
            explore(userList,docList);
            break;
        case 4:
            cout << "Logging out...\n";
            cout<<"...Sucessfully Logged Out...\n\n\n\n\n";
            system("cls");
            displayFirstPage(userList,docList);
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}



void myDocs(UserProfileLinkedList& userList,DocumentLinkedList& docList) {
    system("cls");
    cout << "\n--- My Docs ---\n";
    cout << "1. Uploaded Documents\n";
    cout << "2. Bought Documents\n";
    cout << "3. Upload a New Document\n";
    cout << "4. Go back\n";

    int choice;
    bool validch;
    do{
        validch=true;
        cout<<"Enter your Choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Displaying uploaded documents...\n";
            displayUploadedDocuments(userList,docList);
            break;
        case 2:
            cout << "Displaying downloaded documents...\n";
            break;
        case 3:
            cout << "Feature to upload a new document...\n";
            uploadDocument(userList,docList);
            break;
        case 4:
            displayHomePage(userList,docList);
            break;
        default:
            validch=false;
            cout << "Invalid choice. Please try again.\n";
        }
    }while(!validch);
}





void aboutUs(){
cout<<"Doc-Spot is a document sharing platform that enables students of different university from different Academic Backgrounds having different interests to come together and help each other in their Academic journey and solve many of the problems, they face. Doc-Spot also encourges the students who are still struggling and learning by producing a stream of income with the help of documents they have shared on the platform. Here, on this platform, a student has the power to either giveaway their work freely or at some minimal cost, which will help them by giving them a steady means of income without extra effort. The only thing you need to Register yoursekf on Doc-Spot is your University E-mail, a will to achieve something and connect with fellow learners.";
}

bool validateEmail(string email,int uni_index){
    string pattern = R"(^[\w\.-]+@)" + Universities::domains.at(uni_index-1) + R"(\.edu\.pk$)";
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

void currentProfile(UserProfileLinkedList& userList,DocumentLinkedList& docList) {
    if (current_user <= 0) {
        cout << "No user is currently logged in.\n";
        return;
    }
    
    UserNode* current = userList.head;
    // Search for the user with the ID matching current_user
    while (current!=nullptr) {
        if (current->user.getUserID() == current_user) {
            // Display the profile of the current user
            current->user.displayProfile();
            editProfile(userList,docList,current);
            return;
        }
        current = current->next;
    }
    cout<< "Error: Current user profile not found.\n";
}
void completeProfile(UserProfileLinkedList& userList,DocumentLinkedList& docList){
    cout<<"----------Complete Your Profile to Proceed------------"<<endl;
   
    UserNode* temp=userList.tail;
    if(temp->user.getAddress()=="NULL"){
            string address;
            cin.ignore();
            cout << "Enter your Address: ";
            getline(cin, address);
            temp->user.setAddress(address);
    }
    if(temp->user.getDOB()=="NULL"){
        string DOB;
        bool checkDOB;
        do {      
            checkDOB=true;
            cin.ignore();
            cout << "Enter your DOB in \'DD-MM-YYYY\' Format: ";
            getline(cin, DOB);
            if(!validDOB(DOB)) {
                cout<<"Invalid Date Format"<<endl;
                checkDOB=false;
            }
        }while(!checkDOB);
        temp->user.setDOB(DOB);                   
    }
    if(temp->user.getDepartment()=="NULL"){
        string department;
        cin.ignore();
        cout << "Enter your Department";
        getline(cin, department);
        temp->user.setDepartment(department);
    }

    if(temp->user.getProgram()=="NULL"){
        string program;
        cin.ignore();
        cout << "Enter your Program";
        getline(cin, program);
        temp->user.setProgram(program);
    }

    if(temp->user.getCampusLocation()=="NULL"){
        string campus_location;
        campuscount:
        int ch_camp;
        cin.ignore();
        cout << "Chose your Campus from the given campuses.";
        int uni_index = showAllCampus(temp->user.getUniName());
        int campus_count= Universities::campus.at(uni_index).size();
        cout<<"Enter the number of your campus: ";
        cin>>ch_camp;
        if(ch_camp>0 && ch_camp<=campus_count){
                            temp->user.setCampus(Universities::campus.at(uni_index).at(ch_camp-1));
        }
        else {  
            cout<<"Invalid Choice Please Only chose from the given campuses.";
            goto campuscount;
        }
    }
        int semester;
        cout<<"Enter your Semester: ";
        cin>>semester;
        temp->user.setSemester(semester);
    cout<<"Press any key to go Home page.";
    cin.get();
    displayHomePage(userList,docList);

    }
void editProfile(UserProfileLinkedList& userList,DocumentLinkedList& docList,UserNode* current) {
    int choice = -1;
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
                displayHomePage(userList,docList);
                break;
            default:
                cout<<"Invalid Choice Please Try Again."<<endl;
                editProfile(userList,docList,current);
        
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

void displayUploadedDocuments(UserProfileLinkedList& userList, DocumentLinkedList& docList) {
    DocumentStack docStack; // Create a stack to store documents

    // Traverse through the document linked list
    DocNode* current = docList.head;
    while (current != nullptr) {
        if (current->doc.getUserID() == current_user) {
            docStack.push(current->doc); // Push documents belonging to the current user
        }
        current = current->next;
    }

    // Display documents from the stack
    if (docStack.isEmpty()) {
        cout << "No uploaded documents found for the current user.\n";
    } else {
        cout << "\n--- Uploaded Documents ---\n";
        docStack.displayStack();
    }

    // Go back option
    cout << "\nEnter 1 to go back to Home Page. ";
    cout << "\nEnter any to go back to explore page again. ";
    cout<<"\nEnter your choice: ";
    char choice;
    cin >> choice;

    if (choice == '1') {
        displayHomePage(userList, docList);
    } else {
        cout << "Returning to My Docs menu.\n";
        explore(userList, docList);
    }
}


void filterByUni(UserProfileLinkedList& userList, DocumentLinkedList& docList) {
    DocumentStack docStack; // Create a stack to store documents

    UserNode* currentUserNode = userList.head;
    while (currentUserNode != nullptr) {
        if (currentUserNode->user.getUserID() == current_user) {
            break; 
        }
        currentUserNode = currentUserNode->next;
    }
    // Traverse through the document linked list
    DocNode* current = docList.head;
    while (current != nullptr) {
        if (current->doc.getUniName() == currentUserNode->user.getUniName()) {
            docStack.push(current->doc); // Push documents belonging to the current user
        }
        current = current->next;
    }

    // Display documents from the stack
    if (docStack.isEmpty()) {
        cout << "No uploaded documents found for the current user.\n";
    } else {
        cout << "\n--- Uploaded Documents ---\n";
        docStack.displayStack();
    }

    // Go back option
    cout << "\nEnter 1 to go back to Home Page. ";
    cout << "\nEnter any to go back to my docs page again. ";
    cout<<"\nEnter your choice: ";
    char choice;
    cin >> choice;

    if (choice == '1') {
        displayHomePage(userList, docList);
    } else {
        cout << "Returning to My Docs menu.\n";
        myDocs(userList, docList);
    }
}

void filterBySemester(UserProfileLinkedList& userList, DocumentLinkedList& docList) {
    DocumentStack docStack; // Create a stack to store documents

    UserNode* currentUserNode = userList.head;
    while (currentUserNode != nullptr) {
        if (currentUserNode->user.getUserID() == current_user) {
            break; 
        }
        currentUserNode = currentUserNode->next;
    }
    // Traverse through the document linked list
    DocNode* current = docList.head;
    while (current != nullptr) {
        if ((current->doc.getUniName() == currentUserNode->user.getUniName()) && (current->doc.getSemester() == currentUserNode->user.getSemester()) ) {
            docStack.push(current->doc); // Push documents belonging to the current user
        }
        current = current->next;
    }

    // Display documents from the stack
    if (docStack.isEmpty()) {
        cout << "No uploaded documents found for the current user.\n";
    } else {
        cout << "\n--- Uploaded Documents ---\n";
        docStack.displayStack();
    }

    // Go back option
    cout << "\nEnter 1 to go back to Home Page. ";
    cout << "\nEnter any to go back to explore page again. ";
    cout<<"\nEnter your choice: ";
    char choice;
    cin >> choice;

    if (choice == '1') {
        displayHomePage(userList, docList);
    } else {
        cout << "Returning to My Docs menu.\n";
        explore(userList, docList);
    }
}



void uploadDocument(UserProfileLinkedList& userList, DocumentLinkedList& docList) {
    // File path variable
    char szFileName[MAX_PATH] = ""; // Buffer for the selected file name

    // Set up the OPENFILENAME struct
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = NULL; // Owner window handle
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0"; // Filter for all files
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = NULL;

    // Open file dialog
    if (GetOpenFileName(&ofn)) {
        cout << "File Path Successfully Fetched"<<endl;
    } else {
        DWORD error = CommDlgExtendedError();
        if (error != 0) {
            cout << "An error occurred. Error code: " << error << endl;
        } else {
            cout << "No file selected or dialog canceled." << endl;
        }
        return;
    }

    string file_path=szFileName; // Convert file path to string

    // Create a new Documents object
    Documents doc;

    // Set the file path
    doc.setFilePath(file_path);

    // Variables for user input
    string instructor, academic_year, course_name, description, uni_name, title, tags_input;
    int semester;
    vector<string> tags;

    bool validInput; // Used for validation loops

    // Instructor validation
    do {
        cin.ignore();
        validInput = true;
        cout << "Enter instructor name: ";
        getline(cin, instructor);

        for (int i = 0; i < instructor.length(); i++) {
            char c = instructor[i];
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')) {
                cout << "Invalid instructor name. Only alphabets and spaces are allowed." << endl;
                validInput = false;
                break;
            }
        }
    } while (!validInput);
    doc.setInstructor(instructor);

    // Academic year validation
    do {
        validInput = true;
        cout << "Enter academic year (e.g., 2023): ";
        cin.ignore();
        getline(cin, academic_year);

        if (academic_year.length() != 4) {
            cout << "Academic year must be a 4-digit number." << endl;
            validInput = false;
        } else {
            for (int i = 0; i < academic_year.length(); i++) {
                if (!(academic_year[i] >= '0' && academic_year[i] <= '9')) {
                    cout << "Invalid academic year. Only digits are allowed." << endl;
                    validInput = false;
                    break;
                }
            }
        }
    } while (!validInput);
    doc.setAcademic_year(academic_year);

    // Course name
    cout << "Enter course name: ";
    getline(cin, course_name);
    doc.setCourse_name(course_name);

    // Semester validation
    do {
        cout << "Enter semester (1 or 2): ";
        cin >> semester;

        if (semester == 1 || semester == 2) {
            validInput = true;
        } else {
            cout << "Invalid semester. Please enter 1 or 2." << endl;
            validInput = false;
        }
    } while (!validInput);
    cin.ignore(); // Clear newline character left in the input buffer
    doc.setSemester(semester);

    // Description
    cout << "Enter description: ";
    getline(cin, description);
    doc.setDiscription(description);

    doc.setUploadedDate();

    // University name
    cout << "Enter university name: ";
    getline(cin, uni_name);
    doc.setUniName(uni_name);

    // Title validation
    do {
        validInput = true;
        cout << "Enter document title: ";
        getline(cin, title);

        if (title.empty()) {
            cout << "Title cannot be empty. Please enter a valid title." << endl;
            validInput = false;
        }
    } while (!validInput);
    doc.setTitle(title);

    // Tags input
    cout << "Enter tags (comma-separated): ";
    getline(cin, tags_input);

    string tag = "";
    for (int i = 0; i < tags_input.length(); i++) {
        if (tags_input[i] == ',' || i == tags_input.length() - 1) {
            if (i == tags_input.length() - 1 && tags_input[i] != ',') tag += tags_input[i]; // Add the last char
            tags.push_back(tag);
            tag = "";
        } else if (tags_input[i] != ' ') {
            tag += tags_input[i];
        }
    }

    for (int i = 0; i < tags.size(); i++) {
        doc.addTag(tags[i]);
    }

    doc.setUser_id(current_user);

    // Document details confirmation
    cout << "\nDocument successfully created.\n";
    docList.addUserAtEnd(doc);
    cout<<endl;
    cout<<"Press 1 to upload another document."<<endl;
    cout<<"Press 2 to go to My Docs"<<endl;
    cout<<"Press any other key to go back to Home Page."<<endl;
    cout<<"Enter Your Choice: ";
    char choice;
    cin>>choice;
    switch (choice)
    {
    case '1':
        uploadDocument(userList,docList);
        break;
    case '2':
        myDocs(userList,docList);
        break;
    
    default:
        displayHomePage(userList,docList);
        break;
    }
}

void explore (UserProfileLinkedList& userList, DocumentLinkedList& docList) {
    system("cls");
    cout << "-------------Explore Documents-------------\n";
    cout<<"1. Show All Documents.";
    cout<<"2. Filter your University Documents.";
    cout<<"3. Filter your Semester Documents.";
    cout<<"4. Filter Documents By Tags";
    cout<<"5. Go to Home Page.";

    char choice; // Initialize the choice variable
    bool checkChoice;

do {
    checkChoice = true; // Assume the choice is valid initially



    cout << "Enter Your Choice: ";
    cin >> choice;

    // Validate the user's choice
    if (choice < '1' || choice > '5') {
        cout << "Invalid choice! Please enter a valid option (1-7)." << endl;
        checkChoice = false; // Invalid choice, loop again
    } else {
        // Handle valid choices
        switch (choice) {
            case '1':
                showDocuments(userList,docList);
                break;
            case '2':
                filterByUni(userList,docList);
                break;
            case '3':
                filterBySemester(userList,docList);
                break;
            case '4':
                filterByTags(userList,docList);
                break;
            case '5':
                displayHomePage(userList,docList);
                break;
        }
    }    
} while (!checkChoice);


}

void showDocuments(UserProfileLinkedList& userList, DocumentLinkedList& docList) {
    DocumentStack docStack; // Create a stack to store documents

    // Traverse through the document linked list
    DocNode* current = docList.head;
    while (current != nullptr) {
        if (current->doc.getUserID() != current_user) {
            docStack.push(current->doc); // Push documents belonging to the current user
        }
        current = current->next;
    }

    // Display documents from the stack
    if (docStack.isEmpty()) {
        cout << "No uploaded documents found for the current user.\n";
    } else {
        cout << "\n--- Documents ---\n";
        docStack.displayStack();
    }

    // Go back option
    cout << "\nEnter 1 to go back to Home Page. ";
    cout << "\nEnter any to go back to explore page again. ";
    cout<<"\nEnter your choice: ";
    char choice;
    cin >> choice;

    if (choice == '1') {
        displayHomePage(userList, docList);
    } else {
        cout << "Returning to My Docs menu.\n";
        explore(userList, docList);
    }
}

void filterByTags(UserProfileLinkedList & userList, DocumentLinkedList& docList) {
    system("cls");
    cout << "------------Filter by Tag-----------" << endl;
    cout << "Enter a tag to search: ";
    string tag;
    cin.ignore(); // Clear any previous newline character in the input buffer
    getline(cin, tag);
    cout << "\n";

    DocumentStack docStack; // Stack to store matching documents
    bool documentFound = false; // Flag to track if any document matches the tag

    // Traverse through the document linked list
    DocNode* current = docList.head;

    while (current != nullptr) {
        // Get tags from the document using the getter
        vector<string> tags = current->doc.getTags();

        // Check if the specified tag exists in the tags vector
        for (int i = 0; i < tags.size(); i++) {
            if (tags[i] == tag&&current->doc.getUserID()!=current_user) {
                docStack.push(current->doc); // Push matching document onto the stack
                documentFound = true;
                break; // Stop checking other tags for this document
            }
        }

        current = current->next; // Move to the next document node
    }

    // Display documents from the stack
    if (!documentFound) {
        cout << "No documents found with the specified tag.\n";
    } else {
        cout << "\n--- Documents Matching the Tag ---\n";
        docStack.displayStack();
    }

    // Go back option
   cout << "\nEnter 1 to go back to Home Page. ";
    cout << "\nEnter any to go back to explore page again. ";
    cout<<"\nEnter your choice: ";
    char choice;
    cin >> choice;

    if (choice == '1') {
        displayHomePage(userList, docList);
    } else {
        cout << "Returning to My Docs menu.\n";
        explore(userList, docList);
    }
}

