#pragma once

enum class VoteType{
	UPVOTE,
	DOWNVOTE
};

inline int getVoteValue(VoteType type){
	switch(type){
		case VoteType::UPVOTE: return 1;
		case VoteType::DOWNVOTE: return -1;
	}
	return 0;
}

enum class ReputationType{
	ANSWER_ACCEPTED,
	QUESTION_UPVOTED,
	QUESTION_DOWNVOTED,
	ANSWER_UPVOTED,
	ANSWER_DOWNVOTED
};

int getReputationValue(ReputationType type){
	switch(type){
		case ReputationType::ANSWER_ACCEPTED: return 5;
		case ReputationType::ANSWER_UPVOTED: return 1;
		case ReputationType::ANSWER_DOWNVOTED: return -1;
		case ReputationType::QUESTION_UPVOTED: return 1;
		case ReputationType::QUESTION_DOWNVOTED: return -1;
	}
	return 0;
}