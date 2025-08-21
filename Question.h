#pragma once

#include "Votable.h"
#include "Commentable.h"
#include <string>
#include <vector>
#include <memory>
#include <chrono>

class User;
class Answer;
class Vote;

class Question : public Votable, public Commentable{
public:
    Question(const User& author, const std::string title, const std::string content);

    std::string getId() const;
    const User& getAuthor() const;
    std::string getContent() const;
    std::chrono::system_clock::time_point getCreationDate() const;

    void addAnswer(const Answer& answer);
    std::vector<Answer> getAnswers() const;
    Answer& getAnswer(const std::string& answerId);

    void vote(const User& voter, VoteType type) override;
    int getVoteCount() const override;

    void addComment(const Comment& comment) override;
    std::vector<Comment> getComments() const override;

private:
    std::string id_;
    std::string title_;
    std::string content_;
    const User& author_;

    std::vector<std::unique_ptr<Vote>> votes_;
    std::vector<std::unique_ptr<Answer>> answers_;
    std::vector<std::unique_ptr<Comment>> comments_;

    std::chrono::system_clock::time_point creation_date;
};