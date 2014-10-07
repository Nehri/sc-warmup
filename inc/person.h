#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Person {

  private:

    string username;
    string firstname;
    string lastname;

    int age;
    string tagline;

    queue<string> inbox;
  
  public:

    // constructors
    Person();
    Person(string _username, string _firstname, string _lastname, 
           int _age, string _tagline);

    // getters
    string get_username();
    string get_firstname();
    string get_lastname();
    int get_age();
    string get_tagline();
    string get_info();

    //validators (helper functions)
    bool valid_username(string _username);
    bool valid_firstname(string _firstname);
    bool valid_lastname(string _lastname);
    bool valid_age(int _age);
    bool valid_tagline(string _tagline);

    // setters
    bool set_username(string _username);
    bool set_firstname(string _firstname);
    bool set_lastname(string _lastname);
    bool set_age(int _age);
    bool set_tagline(string _tagline);
    bool set_info(string _username, string _firstname, string _lastname,
                  int _age, string _tagline);

    // operations on messages
    void send_msg(Person &recipient, string msg);
    bool read_msg();

    bool equal_person(Person other);
};

/* external, provided helper functions */

// check if a string only contains alphabetical characters
bool str_isalpha(const string str);

// check if a string only contains alphabetical or numerical characters
bool str_isalnum(const string str);

#endif /* COMMUNITY_H */

