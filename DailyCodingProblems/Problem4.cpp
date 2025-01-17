//An XOR linked list is a more memory efficient doubly linked list.
//Instead of each node holding next and prev fields, 
//it holds a field named both, which is an XOR of the next node and the
//previous node.Implement an XOR linked list; it has an add( element ) 
//which adds the element to the end, and a get( index ) which returns the
//node at index.

//If using a language that has no pointers( such as Python ),
//you can assume you have access to get_pointer and dereference_pointer functions
//that converts between nodes and memory addresses.

#include "Problem4.h"
#include <iostream>
#include <cassert>

void Problem4::RunTest()
{
	TXLinkedList<int> list;
	list.add( 1 );
	list.add( 2 );
	list.add( 3 );
	list.add( 4 );

	std::printf( "\nProblem4:\n%d,%d,%d,%d\n", list.get( 0 ), list.get( 1 ), list.get( 2 ), list.get( 3 ) );
}
