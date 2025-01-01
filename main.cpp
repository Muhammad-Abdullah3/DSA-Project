#include <iostream>
#include <string>
using namespace std;

// Function declarations
void displayHomePage();
void login();
void signUp();
void myProfile();
void myDocs();
void myWallet();
void discussionForum();
void homePage();

int main() {
    
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
