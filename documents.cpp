#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Documents{
    private:
    int document_id;
    int user_id;
    bool isfree;
    string discription; 
    string uploaded_date;
    string title;
    string file_path;
    float price;
    vector <string> tag;
    public:
        static int  document_count;
        Documents(){
            document_id = document_count++;
        }
       Documents(int doc,int usr,string dis, string upl, string tit,string flp,float pri,bool free){
     document_id = doc;
     user_id = usr;    
     isfree = free;
     discription = dis; 
     uploaded_date = upl;
     title = tit;
     file_path = flp;
     price = pri;
        }

          // Getter functions
    int get_document_id() const { return document_id; }
    int get_user_id() const { return user_id; }
    bool get_isfree() const { return isfree; }
    string get_discriptione() const { return discription; }
    string get_uploaded_date() const { return uploaded_date; }
    string get_title() const { return title; }
    string get_file_path() const { return file_path; }
    float get_price() const { return price; }
 void addtag(string t){
tag.push_back(t);
}

};
struct DocNode {
    Documents data; // Document object
    DocNode* next;

    DocNode(const Documents& doc) : data(doc), next(nullptr) {}
};

class DocumentSinglyLinkedList {
public:
    DocNode* head;

    // Constructor
    DocumentSinglyLinkedList()  {
         head=nullptr;
    }

    // Add document to the end of the list
    void addDocument(const Documents& doc) {
        DocNode* newNode = new DocNode(doc);
        if (!head) {
            head = newNode;
        } else {
            DocNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Display all documents
    void displayDocuments() const {
        DocNode* current = head;
        if (!current) {
            cout << "No documents uploaded yet.\n";
            return;
        }

        while (current) {
            current->data.displayDocument();
            cout << "-------------------------\n";
            current = current->next;
        }
    }

    // Display documents by a specific user
    void displayDocumentsByUser(int userId) const {
        DocNode* current = head;
        bool found = false;

        while (current) {
            if (current->data.get_user_id() == userId) {
                current->data.displayDocument();
                cout << "-------------------------\n";
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No documents uploaded by this user.\n";
        }
    }

    // Delete a document by ID
    bool deleteDocument(int docId) {
        if (!head) return false;

        // If the document to delete is the head
        if (head->data.get_document_id() == docId) {
            DocNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        DocNode* current = head;
        while (current->next && current->next->data.get_document_id() != docId) {
            current = current->next;
        }

        if (current->next) {
            DocNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true; // Document deleted successfully
        }

        return false; // Document not found
    }

};
int Documents::document_count=0;

int main(){
    
}




//    void displayDocument() const {
//         cout << "Document ID: " << document_id << endl;
//         cout << "Uploaded by User ID: " << user_id << endl;
//         cout << "Title: " << title << endl;
//         cout << "Description: " << description << endl;
//         cout << "Uploaded Date: " << uploaded_date << endl;
//         cout << "Price: " << (isfree ? "Free" : "$" + to_string(price)) << endl;
//         cout << "File Path: " << file_path << endl;
//         cout << "Tags: ";
//         for (const auto& tag : tags)
//             cout << tag << " ";
//         cout << endl;
//     }
// };