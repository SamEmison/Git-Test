/**
 * @file phonebook.h
 * @author Sam Emison
 * @date 2024-10-30
 * @brief Sets up structure
 * 
 * Sets up structure for the phonebook class by defining its members and operations
 */


// phonebook.h
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>


/**
 * Establishes the class Phonebook and its variables/prototypes and whether they are public/private
 *
 * @class Phonebook phonebook.h "HW2/phonebook.h"
 * @brief Sets up the structure  
 *
 */
class Phonebook {
 private:
  struct Entry {
    std::string first_name; //Variable for first name
    std::string last_name; //Variable for last name
    std::string phone_number; //Variable for phone number
    Entry* next; //Pointer for the next node in the list

/**
 * Constructor for initializing an Entry Node
 *
 * @param const std::string& fname 
 * @param const std::string& lname 
 * @param const std::string& phone 
 * @param Entry* nxt = nullptr 
 * @pre 
 * @post 
 * 
 */
    Entry(const std::string& fname, const std::string& lname, const std::string& phone, Entry* nxt = nullptr)
      : first_name(fname), last_name(lname), phone_number(phone), next(nxt) {}
  };

  Entry* head; //Head of the linked list


 public:
/**
 * Constructor
 *
 * @pre 
 * @post Initializes an empty phonebook with no entries 
 * 
 */
  Phonebook();

/**
 * Destructor
 *
 * @pre 
 * @post All allocated memory for the entries is released
 * 
 */
  ~Phonebook();

  //Method declarations

/**
 * Inserts a new enttry at the beginning of the phonebook
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @param const std::string phone_number 
 * @pre 
 * @return void 
 * @post New entry is added to the front of the list
 * 
 */
  void push_front(const std::string& first_name, const std::string& last_name, const std::string phone_number);

/**
 * Inserts a new entry at the end of the phonebook
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @param const std::string phone_number 
 * @pre 
 * @return void 
 * @post New entry is added to the end of the list
 * 
 */
  void push_back(const std::string& first_name, const std::string& last_name, const std::string phone_number);

/**
 * Inserts a new entry in sorted order by last name
 *
 * @param const std::string& first_name 
 * @param const std::string& last_name 
 * @param const std::string phone_number 
 * @pre 
 * @return void 
 * @post New entry is inserted in alphabetical order based on last name
 * 
 */
  void insert_sorted(const std::string& first_name, const std::string& last_name, const std::string phone_number);


/**
 * Looks up a user's phone number by name
 *
 * @param const std::string& name 
 * @pre 
 * @return std::string 
 * @post 
 * 
 */
  std::string lookup(const std::string& name) const;

/**
 * Finds a user by their phone number
 *
 * @param const std::string& phone_number 
 * @pre 
 * @return std::string 
 * @post 
 * 
 */
  std::string reverse_lookup(const std::string& phone_number) const;


/**
 * Prints the phonebook to the terminal
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void print() const;

/**
 * Deletes a user from the phonebook by their name
 *
 * @param const std::string& name 
 * @pre 
 * @return bool 
 * @post Deletes the user
 * 
 */
  bool delete_user(const std::string& name);

  //File operations

/**
 * Reads phonebook data from a specified file
 *
 * @param const std::string& filename 
 * @pre 
 * @return bool 
 * @post The phonebook recieves the files from the selected file
 * 
 */
  bool read_from_file(const std::string& filename);

/**
 * Writes the phonebook data to a specified file
 *
 * @param const std::string& filename 
 * @pre 
 * @return bool 
 * @post All data in a specified file 
 * 
 */
  bool write_to_file(const std::string& filename) const;
};

#endif
    
