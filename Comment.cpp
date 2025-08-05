#include "Comment.h"

std::string generate_id(){
	static int counter = 1;
	return "comm-" + std::to_string(counter++);
}

Comment::Comment(const User& author, std::string content)
: id(generate_id()),
  author_(std::move(author)), 
  content_(content),
  creation_date(std::chrono::system_clock::now())
{}

std::string Comment::getContent() const{
	return content_;
}

const User& Comment::getAuthor() const{
	return author_;
}

std::string Comment::getId() const{
	return id;
}
