// phonebook.h

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

class Phonebook {
 private:
  struct Entry {
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    Entry* next; //Pointer for the next node in the list

    //Constructor for initilizing an Entry node
    Entry(const std::string& fname, const std::string& lname, const string& phone, Entry* nxt = nullptr)
      : first_name(fname), last_name(lname), phone_number(phone), next(nxt) {}
  };

  Entry* head; //Head of the linked list


 public:
  //Constructor and Destructor
  Phonebook();
  ~Phonebook();

  //Method declarations
  void push_front(const std::string& first_name, const std::string& last_name, const std::string phone_number);
  void push_back(const std::string& first_name, const std::string& last_name, const std::string phone_number);
  void insert_sorted(const std::string& first_name, const std::string& last_name, const std::string phone_number);

  std::string lookup(const std::string& name) const;
  std::string reverse_lookup(const std::string& phone_number) const;

  void print() const;
  bool delete_user(const std::string& name);

  //File operations
  bool read_from_file(const std::string& filename);
  bool write_to_file(const std::string& filename) const;
};

#endif
    
