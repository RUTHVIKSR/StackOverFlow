#pragma once

#include <string>
#include <vector>
#include "Types.h"

class User;
class Question;
class Tag;

class StackOverFlow {
public:

    StackOverFlow();

    const std::vector<Question>& getQuestions() const;
    const std::vector<User>& getUsers() const;
    const std::vector<Tag>& getTags() const;


    void askQuestion(const User& user, const std::string& title, const std::string& content);
    void registerUser(const std::string& username, const std::string& email);
    void addTag(const std::string& name);

    const User& getUser(std::string userId) const;
    const Question& getQuestion(std::string questionId) const;

private:
    std::vector<Question> questions_;
    std::vector<User> users_;
    std::vector<Tag> tags_;
};
