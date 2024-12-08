#include "BST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

string cleanWord(const string& word) {
  string cleaned;
  for (char c: word) {
    if (isalnum(c)) {
      cleaned += tolower(c);
    }
  }
  return cleaned;
}

void processFile(const string& filename, bst& tree) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error: Could not open file" << filename << endl;
    return;
  }

  string word;
  while (file >> word) {
    word = cleanWord(word);
 class bst {
private:
Node* root; // Root of the binary search tree   if (!word.empty()) {
      int x = tree.find(word);
      tree.set(word, x+1);
    }
  }

  cout << "File read successfully" << endl;
  file.close();
}

int main() {
  bst tree;
  string choice, key, filename;
  int value = -1;

  while (true) {

    cout << endl << "Binary Search Tree Menu: " << endl;
    cout << "1. Insert/Update a key-value pair" << endl;
    cout << "2. Find value by key" << endl;
    cout << "3. Delete a key" << endl;
    cout << "4. Pirnt tree in order" << endl;
    cout << "5. Find min key-value pair" << endl;
    cout << "6. Find max key value pair" << endl;
    cout << "7. Save tree to file" << endl;
    cout << "8. Process text file" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    if (choice == "1") {
      cout << "Enter key";
      cin >> key;
      cout << "Enter value: ";
      cin >> value;
      tree.set(key, value);
      cout << "Inserted/updated (" << key << ", " << value << ")" << endl;
      value = -1;
    }
    else if (choice == "2") {
      cout << "Enter key to find: ";
      cin >> key;

      value = tree.find(key);
      if (value >= 0) {
	cout << "Found: (" << key << ", " << value << ")" << endl;
      }
    }
    else if (choice == "3") {
      cout << "Enter key to delete: ";
      cin >> key;
      tree.deleteKey(key);
      cout << "Deleted Key: " << key << endl;
    }
    else if (choice == "4") {
      cout << "Tree contents in order"  << endl;
      tree.print();
    }
    else if (choice ==  "5") {
      try {
	auto minPair =tree.min();
	cout << e.what() << endl;
      }
      cout << "min key value pair" << minPair.first << "," minPair.second << ")" << endl;
    }
    catch (const runtime_error& e) {
      cout << e.what() << endl;
    }
  }
  else if (choice == "6") {
    try {
      auto maxPair = tree.max();
      cout << "Maximum key value" << maxPair.first << "," << maxPair.second << endl;
    }
    catch (const runtime_error& e) {
      cout << e.what() <, endl;
    }
  }
  else if (choice == "7") {
    cout << "Enter filename to save to";
    cin >> filename;
    try{
      tree.saveFile(filename);
    }
    catch (const runtime_error& e) {
      cout << e.what() << endl;
    }
  }
  else if (choice == "8") {
    cout << "Enter filename to proccess";
    cin >> filename;
    processFile(filename, tree);
  }
  else if(choice == "9") {
    cout << "Exiting program." << endl;
    break;
  }
  else {
    cout << "Invalid option" << endl;
  }
}
return 0;
}
