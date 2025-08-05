#pragma once

#include <vector>
#include "Comment.h"


class Commentable{
public:
	virtual ~Commentable() = default;

	virtual void addComment(const Comment& comment) = 0;

	virtual std::vector<Comment> getComments() const = 0;
};