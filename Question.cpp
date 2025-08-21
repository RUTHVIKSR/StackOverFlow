#include "Question.h"
#include <string>
#include <vector>
#include <memory>
#include "Types.h"
#include "Vote.h"

class Answer;

std::string generateId(){
    static int counter = 0;
    return "QUE" + std::to_string(counter++);
}

Question::Question(const User& author, const std::string title, const std::string content)
: author_(author), content_(content), creation_date(std::chrono::system_clock::now()),
  id_(generateId()), title_(title)
{}

std::string Question::getId() const{
    return id_;
}
const User& Question::getAuthor() const{
    return author_;
}
std::string Question::getContent() const{
    return content_;
}
std::chrono::system_clock::time_point Question::getCreationDate() const{
    return creation_date;
}


void Question::addAnswer(const Answer& answer){
    answers_.push_back(std::make_unique<Answer>(answer));
}

std::vector<Answer> Question::getAnswers() const{
    std::vector<Answer> ans;
    for (const auto& answer : answers_) {
        ans.push_back(*answer);
    }
    return ans;
}

void Question::vote(const User& voter, VoteType type){
	votes_.emplace_back(std::make_unique<Vote>(voter, type));
}

int Question::getVoteCount() const{
    int ans = 0;
    for(const auto &vote : votes_){
        ans += getVoteValue(vote->getType());
    }
    return ans;
};

	
void Question::addComment(const Comment& comment){
    comments_.emplace_back(std::make_unique<Comment>(comment));
}

std::vector<Comment> Question::getComments() const{
    std::vector<Comment> ans;
    for(const auto &comment : comments_){
        ans.push_back(*comment);
    }
    return ans;
}