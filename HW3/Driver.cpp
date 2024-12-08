#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

int main() {
    BST tree;
    string key;
    int data;
    int choice;

    while (true) {
        cout << "1. Set a key-value pair (insert or overwrite)\n";
        cout << "2. Find a value by key\n";
        cout << "3. Print the tree\n";
        cout << "4. Find the smallest key\n";
        cout << "5. Find the largest key\n";
        cout << "6. Save tree to file\n";
        cout << "7. Load tree from file\n";
        cout << "8. Delete a key\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter data: ";
                cin >> data;
                tree.set(key, data);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                try {
                    cout << "Data: " << tree.find(key) << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                tree.print();
                break;
            case 4:
                tree.min();
                break;
            case 5:
                tree.max();
                break;
            case 6:
                cout << "Enter filename to save: ";
                cin >> key;
                tree.saveFile(key);
                break;
            case 7:
                cout << "Enter filename to load: ";
                cin >> key;
                tree.loadFile(key);
                break;
            case 8:
                cout << "Enter key to delete: ";
                cin >> key;
                tree.deleteNode(key);
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
