//Given an array of integers, return a new array such that each element at index i of the new array
//is the product of all the numbers in the original array except the one at i.
//
//For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].
//If our input was[3, 2, 1], the expected output would be[2, 3, 6].
//
//Follow - up: what if you can't use division?

#include <vector>
#include "Util.h"
#include "Problems.h"

const std::vector<int> Solution( const std::vector<int>& input )
{
	//no division
	std::vector<int> lhs( input.size() );
	lhs[0] = 1;
	for ( std::size_t i = 1; i < lhs.size(); ++i )
	{
		lhs[i] = lhs[i - 1] * input[i - 1];
	}

	std::vector<int> rhs( input.size() );
	rhs[input.size() - 1] = 1;
	for ( int i = input.size() - 2; i >= 0; --i )
	{
		rhs[i] = rhs[i + 1] * input[i + 1];
	}

	for ( std::size_t i = 0; i < lhs.size(); ++i )
	{
		lhs[i] *= rhs[i];
	}
	

	return lhs;
}

void Problem2::RunTest()
{
	const std::vector<int> testVec = { 1, 2, 3, 4, 5 };
	std::printf( "\nProblem2:\n" );
	Util::PrintContainer( testVec );
	Util::PrintContainer( Solution( testVec ) );
}
