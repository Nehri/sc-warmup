#include "community.h"
#include "person.h"

Community::Community()
  : name(""), people(map<string,Person>()) {
}

Community::Community(string _name, map<string,Person> _people) 
  : name(_name), people(_people) {
}

// implement Community::get_name here!
string Community::get_name(){
	return name;
}

bool Community::valid_name(string _name) {
	if (!_name.empty() && _name.length() <= 32 &&
					str_isalnum(_name) && str_isalpha((char *)_name[0])) {
				return true;
			}
			else {
				return false;
			}
}
// implement Community::set_name here!
bool Community::set_name(string _name){
	if (valid_name(_name)) {
			name = _name;
			return true;
		}
		else {
			return false;
		}
}

bool Community::add_person(Person _person) {
    contact to_add(_person.get_username(), _person);
    if (_person.equal_person(Person())) {
    	return false;
    }
    if (!get_member(_person.get_username()).equal_person(Person())) {
    	return false;
    }
    auto ret = people.insert(to_add);
    return ret.second;
}

Person Community::get_member(string username) {
    if (people.find(username) != people.end()) {
        return people[username];
    }
    else {
        return Person();
    }
}
    
list<string> Community::get_all_usernames() {
    list<string> usernames;
    for(auto it=people.begin(); it!=people.end(); ++it) {
        usernames.push_back(it->first);
    }
    return usernames;
}

// implement Community::print_all_usernames here!
void Community::print_all_usernames() {
	list<string> usernames = get_all_usernames();
	for (int i = 0; !usernames.empty(); i++) {
		cout << usernames.front() << endl;
		usernames.pop_front();
	}
}
// implement Community::find_member here!
list<Person> Community::find_member(string firstname) {
	list<Person> found;
	// iterator of type map<string, Person>::iterator
	for (auto it = people.begin(); it != people.end(); ++it) {
		if (people.at(it->first).get_firstname().compare(firstname)==0) {
			found.push_back(people.at(it->first));
		}

	}
	return found;
}

// implement Community::send_msg here!
bool Community::send_msg(list<string> usernames, string msg) {
	bool all_sent = true;
	Person temp;
	while(!usernames.empty()){
		temp = get_member(usernames.front());
		if (temp.equal_person(Person())){
			all_sent = false;
		}
		else {
			temp.send_msg(temp, msg);
		}
		usernames.pop_front();

	}
	return all_sent;

}
