//This is a header guard. It's a directive that tells the compiler to include this file only once, no matter how many other files try to #include it.
#pragma once

#include <vector>
#include "Comment.h"


class Commentable{
public:
/*
	virtual ensures that if you delete a derived class object through a pointer to the base class,
	the correct destructor is called first, followed by the base class's destructor. 
	Forgetting to make the destructor virtual in a base class can lead to memory leaks.

	default tells the compiler to generate a default, empty implementation for the destructor. 
	We don't need any special cleanup logic for Commentable, so the default behavior is sufficient.

*/	
	virtual ~Commentable() = default;

/*
	= 0 : This syntax is what makes the function pure virtual. 
	It signifies that the class provides no implementation for this function. 
	Any class that inherits from the class must provide its own implementation, 
	otherwise, it too will be an abstract class.

	const Comment& comment : is a const reference (no permission to modify)
*/
	virtual void addComment(const Comment& comment) = 0;

	virtual std::vector<Comment> getComments() const = 0;
};