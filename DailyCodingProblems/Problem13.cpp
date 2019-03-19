//This problem was asked by Google.
//
//Given two singly linked lists that intersect at some point, find the intersecting node.The lists are non - cyclical.
//
//For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
//
//In this example, assume nodes with the same value are the exact same node objects.
//
//Do this in O( M + N ) time( where M and N are the lengths of the lists ) and constant space.

#include "Problems.h"
#include <list>

int CommonNode( std::list<int>& A, std::list<int>& B )
{
	A.reverse();
	B.reverse();

	auto ita = A.cbegin();
	auto itb = B.cbegin();

	while ( ita != A.cend() && itb != B.cend() && *ita == *itb )
	{
		++ita; ++itb;
	}
	const int common = *--ita;

	A.reverse();
	B.reverse();

	return common;
}

void Problem13::RunTest()
{
	std::list<int> A = { 3,7,8,10 };
	std::list<int> B = { 99,1,8,10 };
	std::printf( "\nProblem13:\n" );
	std::printf( "CommonNode: %d\n", CommonNode( A, B ) );
}
