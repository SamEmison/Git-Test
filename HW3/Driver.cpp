#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
using namespace std;

string cleanWord(const string& word) {
    string cleaned;
    for (char c : word) {
        if (c >= 'A' && c <= 'Z') {
            cleaned += c + 'a' - 'A';
        } else if (isalnum(c)) {
            cleaned += c;
        }
    }
    return cleaned;
}

void processFile(const string& filename, bst& tree) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    string word;
    while (file >> word) {
        word = cleanWord(word);
        if (!word.empty()) {
            try {
                int count = tree.find(word);
                tree.set(word, count + 1);
            } catch (const runtime_error&) {
                tree.set(word, 1);
            }
        }
    }
    cout << "File processed successfully: " << filename << endl;
    file.close();
}

int main() {
    bst tree;
    string choice, key, filename;
    int value = -1;
    
    while (true) {
        cout << endl << "Binary Search Tree Menu:" << endl;
        cout << "1. Insert/Update a Key-Value Pair" << endl;
        cout << "2. Find Value by Key" << endl;
        cout << "3. Delete a Key" << endl;
        cout << "4. Print Tree (In-Order)" << endl;
        cout << "5. Find Minimum Key-Value Pair" << endl;
        cout << "6. Find Maximum Key-Value Pair" << endl;
        cout << "7. Save Tree to File" << endl;
        cout << "8. Process Text File" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            tree.set(key, value);
            cout << "Inserted/Updated (" << key << ", " << value << ")" << endl;
            value = -1;
        } else if (choice == "2") {
            cout << "Enter key to find: ";
            cin >> key;
            try {
                value = tree.find(key);
                cout << "Found: (" << key << ", " << value << ")" << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (choice == "3") {
            cout << "Enter key to delete: ";
            cin >> key;
            tree.deleteKey(key);
            cout << "Deleted key: " << key << endl;
        } else if (choice == "4") {
            cout << "Tree contents (in-order):" << endl;
            tree.print();
        } else if (choice == "5") {
            try {
                auto minPair = tree.min();
                cout << "Minimum key-value pair: (" << minPair.first << ", " << minPair.second << ")" << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (choice == "6") {
            try {
                auto maxPair = tree.max();
                cout << "Maximum key-value pair: (" << maxPair.first << ", " << maxPair.second << ")" << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (choice == "7") {
            cout << "Enter filename to save tree: ";
            cin >> filename;
            try {
                tree.saveFile(filename);
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (choice == "8") {
            cout << "Enter filename to process: ";
            cin >> filename;
            processFile(filename, tree);
        } else if (choice == "9") {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
