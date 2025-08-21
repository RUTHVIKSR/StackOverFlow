#pragma once

// #include "User.h"
class User;
#include "Types.h"

class Vote{
public:
	Vote(const User& voter, VoteType type);

	const User& getUser() const;
	VoteType getType() const;

private:
	// to create a reference the compiler only needs to know that the User class exists, so forward declaration.
	const User& voter_;
	// We are storing VoteType by value. The compiler needs its full definition
// from "Types.h" to know its size, so we must #include the file.
	VoteType type_;
};