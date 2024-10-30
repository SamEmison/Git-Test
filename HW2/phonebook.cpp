#include "phonebook.h"
#include <iostream>
#include <fstream>



//Constructor
Phonebook::Phonebook() : head(nullptr) {}

//Destructor
Phonebook::~Phonebook() {
  Entry* current = head;
  while (current != nullptr) {
    Entry* next = current->next;
    delete current;
    current = next;
  }
}

//Add a entry to the front
void Phonebook::push_front(const std::string &first_name, const std::string &last_name, const std::string phone_number) {
  Entry* new_entry = new Entry(first_name, last_name, phone_number, head);
  head = new_entry;
}

//Add a entry to the back
void Phonebook::push_back(const std::string &first_name, const std::string &last_name, const std::string phone_number) {
  Entry* new_entry = new Entry(first_name, last_name, phone_number);
  if (!head) { //If list is empty, set head to new entry
    head = new_entry;
  }
  else {
    // Traverse to the end
    Entry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next =new_entry; //Sets the last node's next to the new entry
  }
}


void Phonebook::insert_sorted(const std::string &first_name, const std::string &last_name, const std::string phone_number) {
  Entry* new_entry = new Entry(first_name, last_name, phone_number);

  //If the list is empty, the new entry should be at the head
  if (!head || head->last_name > last_name) {
    new_entry->next = head;
    head = new_entry;
  }
  else { //Traverse to find the insertion point
    Entry* current = head;
    while (current-> next && current->next->last_name < last_name) {
      current = current->next;
    }

    //Insert the new entry
    new_entry->next = current->next;
    current->next = new_entry;
  }
}

//Lookup a user's phone number via full name
std::string Phonebook::lookup(const std::string &name) const {
  Entry* current = head;
  while (current) {
    std::string full_name = current->first_name + " " + current->last_name;
    if (full_name == name) {
      return current->phone_number; //Returns the phone number if the name matches
    }
    current = current->next;
  }
  return "Name not found"; //Return error if name is not in the phonebook
}

//Reverse lookup a user via phone number
std::string Phonebook::reverse_lookup(const std::string &phone_number) const {
  Entry* current = head;
  while (current) {
    if (current->phone_number == phone_number) {
      return current->first_name + " " + current->last_name; //Returns the name if the phone number matches
    }
    current = current->next;
  }
  return "Phone number not found"; //Return error message if phone number is not in the phonebook
}

//Delete a user from the phonebook via full name
bool Phonebook::delete_user(const std::string &name) {
  if (!head) return false; //Return false is list is empty

  //Check if head is the entry to delete
  std::string head_full_name = head->first_name + " " + head->last_name;
  if (head_full_name == name) {
    Entry* temp = head;
    head = head->next;
    delete temp;
    return true; //Successfully deleted
  }

  //Traverse the list to find the entry to be deleted
  Entry* current = head;
  while (current->next) {
    std::string next_full_name = current->next->first_name + " " + current->next->last_name;
    if (next_full_name == name) {
      Entry* temp = current->next;
      current->next = current->next->next;
      delete temp;
      return true; //Successfully deleted
    }
    current = current->next;
  }

  return false; //Entry not found in phonebook
}

//Write the phonebook to a file
bool Phonebook::write_to_file(const std::string &filename) const {
  std::ofstream outfile(filename);
  if (!outfile.is_open()) {
    return false; //File couldnt be opened
  }

  Entry* current = head;
  while (current) {
    outfile << current->first_name << " " << current->last_name << "\n";
    outfile << current->phone_number << "\n";
    current = current->next;
  }
  outfile.close();
  return true; //Successfully wrote to file
}

//Read the phonebook from txt file
bool Phonebook::read_from_file(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file." << std::endl;
    return false; //Return false, file couldnt be opened
  }

  std::string first_name, last_name, phone_number;
  while (std::getline(file, first_name, ' ') && std::getline(file, last_name)) {
    std::getline(file, phone_number);	 
      //Insert the new entry in the order
    insert_sorted(first_name, last_name, phone_number);  
    }
  
    file.close();
    return true; //Successfully read from the file
}

void Phonebook::print() const {
  Entry* current = head;
  while (current != nullptr) {
    std::cout << current->first_name << " " << current->last_name << "\n";
    std::cout << current->phone_number << "\n";
    current = current->next;
  }
}
