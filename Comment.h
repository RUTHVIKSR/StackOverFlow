#pragma once

#include <string>
#include <chrono>
#include "User.h"

class Comment{
public:
	Comment(const User& author, std::string content);

	std::string getId() const;
	std::string getContent() const;
	const User& getAuthor() const;

private:
	const User& author_;
	std::string content_;
	std::string id;
	std::chrono::system_clock::time_point creation_date;
};