#pragma once

#include <string>

class Tag{
public:
	Tag(const std::string& name);

	std::string getName() const;
	std::string getId() const;

private:
	std::string name;
	std::string id;
};