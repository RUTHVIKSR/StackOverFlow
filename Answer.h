#pragma once

#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include "Votable.h"
#include "Commentable.h"

class User;
class Question;
class Comment;
class Vote;

class Answer : public Votable, public Commentable{
public:
	Answer(const User& author, const Question& question, std::string content);
	
	std::string getId() const;
	std::string getContent() const;
	const User& getAuthor() const;
	const Question& getQuestion() const;
	bool isAccepted() const;

	void markAccepted();

	void vote(const User& voter, VoteType type) override;
	int getVoteCount() const override;
	
	void addComment(const Comment& comment) override;
	std::vector<Comment> getComments() const override;

private:
	bool accepted;
	const User& author;
	const Question& question;
	std::string id;
	std::string content;

	std::chrono::system_clock::time_point creation_date;

	std::vector<std::unique_ptr<Vote>> votes;
	std::vector<std::unique_ptr<Comment>> comments;
};