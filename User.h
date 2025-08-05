#pragma once

#include <string>

class User{
public:
	User(const std::string& name, const std::string& email);

	void updateReputation(int value);

	std::string getName() const;
	std::string getUserId() const;
	std::string getEmail() const;
	int getReputation() const;

private:
	std::string userId;
	std::string name;
	std::string email;
	int reputation;
};