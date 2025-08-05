#include "User.h"
#include <algorithm>

std::string generateId(){
	static int counter = 0;
	return "user-" + std::to_string(counter++);
}

User::User(const std::string& name, const std::string& email)
: userId(generateId()),
	name(name),
	email(email),
	reputation(0)
{
	
}

void User::updateReputation(int value){
	this->reputation += value;
	this->reputation = std::max(this->reputation, 0);
}

std::string User::getUserId() const{
	return this->userId;
}

std::string User::getName() const{
	return this->name;
}

int User::getReputation() const{
	return this->reputation;
}

std::string User::getEmail() const{
	return this->email;
}

