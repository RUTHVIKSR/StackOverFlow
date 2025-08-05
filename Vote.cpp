#include "Vote.h"

class User;

Vote::Vote(const User& voter, VoteType type)
:voter_(voter), type_(type)
{
	
}

const User& Vote::getUser() const{
	return voter_;
}

VoteType Vote::getType() const{
	return type_;
}

