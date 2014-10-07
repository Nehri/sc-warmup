#include "person.h"
#include <sstream>

bool str_isalpha(const string str) {
    // find_if takes two iterators that bound the region of the container to
    // search and a boolean function; if any of the elements in the container
    // cause the function to return true, find_if returns an iterator to that
    // position; if no elements cause the function to return true, then an
    // iterator at the end position is returned. here, the whole string is
    // alphabetic if the end iterator is returned, so we return the boolean
    // indicating that this is the case.
    return find_if(str.begin(), str.end(), 
                   [](char c){ return !(isalpha(c)); }) == str.end();
}

bool str_isalnum(const string str) {
    // same as above, but with an alphanumeric check
    return find_if(str.begin(), str.end(), 
                   [](char c){ return !(isalnum(c)); }) == str.end();
}

Person::Person() 
  : username(""), firstname(""), lastname(""), age(0), tagline("") {
}

Person::Person(string _username, string _firstname, string _lastname, 
               int _age, string _tagline) 
  : username(_username), firstname(_firstname), lastname(_lastname),
    age(_age), tagline(_tagline) {
}

// write Person::get_username here!
string Person::get_username() {
	return username;
}
string Person::get_firstname() {
    return firstname;
}
string Person::get_lastname() {
    return lastname;
}
int Person::get_age() {
    return age;
}
string Person::get_tagline() {
    return tagline;
}

// write Person::get_info here!
string Person::get_info() {
	stringstream ss;
	ss << "Username: " << get_username() << "\nName: " <<
			get_firstname() << " " << get_lastname() << "\nAge: " <<
			get_age() << "\n\n " << get_tagline();
	string temp = ss.str();
	return temp;
}

bool Person::valid_username(string _username) {
	if (!_username.empty() && _username.length() <= 32 &&
				str_isalnum(_username) && str_isalpha((char *)_username[0])) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::valid_firstname(string _firstname) {
	if (_firstname.length() <= 32 && str_isalpha(_firstname)) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::valid_lastname(string _lastname) {
	if (_lastname.length() <= 32 && str_isalpha(_lastname)) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::valid_age(int _age) {
	if (_age >=0 && _age < 128) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::valid_tagline(string _tagline) {
	if (_tagline.length() <= 256) {
		return true;
	}
	else {
		return false;
	}
}

// write Person::set_username here!
bool Person::set_username(string _username) {
	if (valid_username(_username)) {
		username = _username;
		return true;
	}
	else {
		return false;
	}
}

bool Person::set_firstname(string _firstname) {
    if (valid_firstname(_firstname)) {
        firstname = _firstname;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_lastname(string _lastname) {
    if (valid_lastname(_lastname)) {
        lastname = _lastname;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_age(int _age) {
    if (valid_age(_age)) {
        age = _age;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_tagline(string _tagline) {
    if (valid_tagline(_tagline)) {
        tagline = _tagline;
        return true;
    }
    else {
        return false;
    }
}

// write Person::set_info here!
bool Person::set_info(string _username, string _firstname, string _lastname,
                  int _age, string _tagline) {

	if (valid_username(_username) && valid_firstname(_firstname) &&
			valid_lastname(_lastname) && valid_age(_age) && valid_tagline(_tagline)) {
		username = _username;
		firstname = _firstname;
		lastname = _lastname;
		age = _age;
		tagline = _tagline;
		return true;
	}
	else {
		return false;
	}
}

// write Person::send_msg here!
void Person::send_msg(Person &recipient, string msg) {
	recipient.inbox.push(msg);
	return;
}

// write Person::read_msg here!
bool Person::read_msg() {
	if (inbox.empty()) {
		cout << "Your inbox is empty!" << endl;
		return false;
	}
	else {
		cout << inbox.front() << endl;
		inbox.pop();
		return true;
	}
}

	bool Person::equal_person(Person other) {
		if (username.compare(other.username) == 0 && firstname.compare(other.firstname) == 0 &&
				lastname.compare(other.lastname) == 0 && age == other.age && tagline.compare(other.tagline) == 0) {
			return true;
		}
		else {
			return false;
		}
	}


