#include "Factory.h"
#include "linkedlist.h"


/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getLinkedListInt() and

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<int>();".
*/
LinkedListInterface<int> * Factory::getLinkedListInt()
{
	return new LinkedList<int>(); 
}

/*
	getLinkedListString() and

	Creates and returns an object whose class extends LinkedListInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "LinkedList", you might say, "return new LinkedList<string>();".
*/
LinkedListInterface<string>* Factory::getLinkedListString()
{
	return new LinkedList<string>();//Modify this line
}
