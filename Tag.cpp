#include "Tag.h"

std::string generateId(){
	static int counter = 0;
	return "tag-" + std::to_string(counter++);
}

Tag::Tag(const std::string& name)
:id(generateId()),
name(name)
{

}

std::string Tag::getName() const{
	return this->name;
}

std::string Tag::getId() const{
	return this->id;
}