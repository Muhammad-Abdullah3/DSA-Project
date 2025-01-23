#include <iostream>
#include <string>
#include <vector>
#include <sstream> // For stringstream
#include <limits>  // For numeric_limits
#include <windows.h>
#include <commdlg.h> // For common dialog boxes

using namespace std;

void uploadDocument() {
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
        cout << "Selected file: " << szFileName << endl;
    } else {
        DWORD error = CommDlgExtendedError();
        if (error != 0) {
            cout << "An error occurred. Error code: " << error << endl;
        } else {
            cout << "No file selected or dialog canceled." << endl;
        }
        return;
    }

    string file_path(szFileName); // Convert file path to string

    // Variables for document details
    string instructor;
    string academic_year;
    string course_name;
    int semester;
    string description;
    string uploaded_date;
    string uni_name;
    string title;
    vector<string> tags;

    // Get details from the user
    cout << "Enter instructor name: ";
    getline(cin, instructor);

    cout << "Enter academic year (e.g., 2023): ";
    getline(cin, academic_year);

    cout << "Enter course name: ";
    getline(cin, course_name);

    cout << "Enter semester (e.g., 1 or 2): ";
    while (!(cin >> semester)) {
        cout << "Invalid input. Please enter a valid integer for semester: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Clear the input buffer

    cout << "Enter description: ";
    getline(cin, description);

    cout << "Enter uploaded date (YYYY-MM-DD): ";
    getline(cin, uploaded_date);

    cout << "Enter university name: ";
    getline(cin, uni_name);

    cout << "Enter document title: ";
    getline(cin, title);

    // Get tags
    cout << "Enter tags (comma-separated): ";
    string tags_input;
    getline(cin, tags_input);

    // Split tags by commas
    stringstream ss(tags_input);
    string tag;
    while (getline(ss, tag, ',')) {
        tags.push_back(tag);
    }

    // Print the details for verification
    cout << "\nDocument Details:\n";
    cout << "File Path: " << file_path << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Academic Year: " << academic_year << endl;
    cout << "Course Name: " << course_name << endl;
    cout << "Semester: " << semester << endl;
    cout << "Description: " << description << endl;
    cout << "Uploaded Date: " << uploaded_date << endl;
    cout << "University Name: " << uni_name << endl;
    cout << "Title: " << title << endl;
    cout << "Tags: ";
    for (const string& tag : tags) {
        cout << tag << " ";
    }
    cout << endl;
}

int main() {
    uploadDocument();
    return 0;
}
