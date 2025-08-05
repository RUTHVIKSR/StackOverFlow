#pragma once

#include "User.h"
#include "Types.h"

class Vote{
public:
	Vote(const User& voter, VoteType type);

	const User& getUser() const;
	VoteType getType() const;

private:
	const User& voter_;
	VoteType type_;
};