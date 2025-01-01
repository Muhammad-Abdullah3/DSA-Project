#include <iostream>
#include <string>
#include <windows.h>
#include <commdlg.h> // For common dialog boxes

using namespace std;

int main() {
    OPENFILENAME ofn;                // Struct to store file dialog info
    char szFileName[MAX_PATH] = ""; // Buffer for the selected file name

    // Initialize the OPENFILENAME structure
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = NULL; // Set the owner window handle if applicable
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0"; // File type filter
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = NULL;

    // Display the Open File dialog
    if (GetOpenFileName(&ofn)) {
        cout << "Selected file: " << szFileName << endl;
        // Use the selected file (szFileName) here
    } else {
        DWORD error = CommDlgExtendedError(); // Retrieve extended error info
        if (error != 0) {
            cout << "An error occurred. Error code: " << error << endl;
        } else {
            cout << "No file selected or dialog canceled." << endl;
        }
    }
    return 0;
}
