#include <iostream>
#include <fstream>  // For file operations
#include <string>
#include <windows.h>
#include <commdlg.h> // For common dialog boxes

using namespace std;

// Function to simulate downloading a file
void downloadDocument(const string& sourceFilePath, const string& defaultTitle) {
    // File path variable for destination
    char szFileName[MAX_PATH] = ""; // Buffer for the destination file name
    strncpy(szFileName, defaultTitle.c_str(), defaultTitle.size()); // Set default name

    // Set up the OPENFILENAME struct
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = NULL; // Owner window handle
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0"; // Filter for all files
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT; // Overwrite prompt if file exists
    ofn.lpstrDefExt = NULL;

    // Show the "Save As" dialog box
    if (GetSaveFileName(&ofn)) {
        cout << "File will be saved to: " << szFileName << endl;

        // Simulate file download by copying the source file to the selected destination
        ifstream sourceFile(sourceFilePath, ios::binary); // Open source file
        if (!sourceFile) {
            cout << "Error: Could not open source file: " << sourceFilePath << endl;
            return;
        }

        ofstream destFile(szFileName, ios::binary); // Open destination file
        if (!destFile) {
            cout << "Error: Could not create destination file: " << szFileName << endl;
            return;
        }

        // Copy file contents
        destFile << sourceFile.rdbuf();

        // Close the files
        sourceFile.close();
        destFile.close();

        cout << "File successfully saved to " << szFileName << endl;
    } else {
        DWORD error = CommDlgExtendedError();
        if (error != 0) {
            cout << "An error occurred. Error code: " << error << endl;
        } else {
            cout << "Save operation canceled." << endl;
        }
    }
}

int main() {
    // Example usage
    string sourceFilePath = "D:\\DSA-Project\\documents.cpp"; // Source file to "download"
    string defaultTitle = "DownloadedDocument.cpp"; // Default title for the file

    downloadDocument(sourceFilePath, defaultTitle);

    return 0;
}
