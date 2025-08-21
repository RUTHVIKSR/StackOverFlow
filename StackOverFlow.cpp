#include "StackOverFlow.h"
#include "Tag.h"
#include "User.h"
#include "Question.h"

#include <vector>
#include <string>

const std::vector<Question>& StackOverFlow::getQuestions() const{
    return questions_;
}

const std::vector<User>& StackOverFlow::getUsers() const{
    return users_;
}

const std::vector<Tag>& StackOverFlow::getTags() const{
    return tags_;
}

void StackOverFlow::askQuestion(const User& author, const std::string& title, const std::string& content){
    Question newQuestion = {author, title, content};
    questions_.push_back(newQuestion);
}

void StackOverFlow::registerUser(const std::string& username, const std::string& email){
    User newUser = {username, email};
    users_.push_back(newUser);
}

void StackOverFlow::addTag(const std::string& name){
    Tag newTag = {name};
    tags_.push_back(newTag);
}

const User& StackOverFlow::getUser(std::string userId) const {
    for (const auto& user : users_) {
        if (user.getUserId() == userId) {
            return user;
        }
    }
    throw std::runtime_error("User not found");
}

const Question& StackOverFlow::getQuestion(std::string questionId) const {
    for (const auto& question : questions_) {
        if (question.getId() == questionId) {
            return question;
        }
    }
    throw std::runtime_error("Question not found");
}
