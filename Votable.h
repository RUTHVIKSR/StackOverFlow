#pragma once

class User;
enum class VoteType;

class Votable{
public:
	virtual ~Votable() = default;
	
	virtual void vote(const User& voter, VoteType type) = 0;
	virtual int getVoteCount() const = 0;
};