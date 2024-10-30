#include <iostream>
#include <string>
#include "phonebook.h"

using namespace std;

void display_menu() {
  cout << "Welcome to my phonebook! You can select one of the following options...\n";
  cout << "1. Read a phonebook from a file\n";
  cout << "2. Write the phonebook to a file\n";
  cout << "3. Print the phonebook\n";
  cout << "4. Search for a user's phone number\n";
  cout << "5. Reverse lookup by phone number\n";
  cout << "6. Add a user\n";
  cout << "7. Delete a user\n";
  cout << "8. Exit this program\n";
}

int main() {
  Phonebook phonebook;
  int choice;

do {
  display_menu();
  cout << "Please enter your choice now: ";
  cin >> choice;
  cin.ignore(); // To ignore the newline character from the input buffer
  
  switch (choice) {
  case 1: {
    string filename;
    cout << "Enter the filename to read from: ";
    getline(cin, filename);
    if (phonebook.read_from_file(filename)) {
      cout << "Phonebook read successfully.\n";
    }
    else {
      cout << "Error reading the phonebook from file.\n";
    }
    break;
  }
  case 2: {
    string filename;
    cout << "Enter the filename to write to: ";
    getline(cin, filename);
    if (phonebook.write_to_file(filename)) {
      cout << "Phonebook written successfully.\n";
    }
    else {
      cout << "Error writing the phonebook to file.\n";
    }
    break;
  }
  case 3:
    phonebook.print();
    break;
  case 4: {
    string full_name;
    cout << "Enter the full name (first last) to search for: ";
    getline(cin, full_name);
    string number = phonebook.lookup(full_name);
    if (!number.empty()) {
      cout << "Phone number: " << number << "\n";
    }
    else {
      cout << "User not found.\n";
    }
    break;
  }
  case 5: {
    string phone_number;
    cout << "Enter the phone number to reverse lookup: ";
    getline(cin, phone_number);
    string name = phonebook.reverse_lookup(phone_number);
    if (!name.empty()) {
      cout << "Name: " << name << "\n";
    }
    else {
      cout << "Number not found.\n";
    }
    break;
  }
  case 6: {
    string first_name, last_name, phone_number;
    cout << "Enter the first name: ";
    getline(cin, first_name);
    cout << "Enter the last name: ";
    getline(cin, last_name);
    cout << "Enter the phone number: ";
    getline(cin, phone_number);
    phonebook.insert_sorted(first_name, last_name, phone_number);
    cout << "User added successfully.\n";
    break;
  }
  case 7: {
    string full_name;
    cout << "Enter the full name (first last) of the user to delete: ";
    getline(cin, full_name);
    if (phonebook.delete_user(full_name)) {
      cout << "User deleted successfully.\n";
    }
    else {
      cout << "User not found.\n";
    }
    break;
  }
  case 8:
    cout << "Exiting the program. Goodbye!\n";
    break;
  default:
    cout << "Invalid choice. Please try again.\n";
  }

 } while (choice != 8); // Loop until the user chooses to exit

 return 0;
}
