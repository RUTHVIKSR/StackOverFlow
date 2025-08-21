#include "Answer.h"
#include "Types.h"
#include "Vote.h"
#include <string>
#include <chrono>

std::string generateId(){
    static int counter = 0;
    return "ANS" + std::to_string(counter++);
}

Answer::Answer(const User& author, const Question& question, std::string content)
: accepted(false), author(author), question(question), id(generateId()), 
content(std::move(content)), creation_date(std::chrono::system_clock::now())
{
}

std::string Answer::getId() const{
    return id;
}

std::string Answer::getContent() const{
    return content;
}

const User& Answer::getAuthor() const{
    return author;
}

const Question& Answer::getQuestion() const{
    return question;
}

bool Answer::isAccepted() const{
    return accepted;
}

void Answer::markAccepted(){
    accepted = true;
}

void Answer::vote(const User& voter, VoteType type){
	votes.emplace_back(std::make_unique<Vote>(voter, type));
}

int Answer::getVoteCount() const {
    int ans = 0;
    for(const auto &vote : votes){
        ans += getVoteValue(vote->getType());
    }
    return ans;
};

	
void Answer::addComment(const Comment& comment){
    comments.emplace_back(std::make_unique<Comment>(comment));
}

std::vector<Comment> Answer::getComments() const{
    std::vector<Comment> ans;
    for(const auto &comment : comments)
        ans.push_back(*comment);
    return ans;
}