#include "Problem23.h"

//Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k.If such a subset cannot be made, then return null.
//
//Integers can appear more than once in the list.You may assume all numbers in the list are positive.
//
//For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return[12, 9, 2, 1] since it sums up to 24.

#include <vector>
#include <iostream>
#include <deque>
#include "Util.h"

bool SubsetSum( const std::vector<size_t> Subset, size_t K, std::deque<size_t>& SubsetOut )
{
	//Iterate through each number
	//See if there is a subset sum with that number chosen and subtracted from K.
	for ( std::vector<size_t>::const_iterator it = Subset.begin(); it != Subset.end(); ++it )
	{
		if ( *it == K )
		{
			SubsetOut.push_front( *it );
			return true;
		}
		else
		{
			//Make sure this element wouldnt exceed the sum
			if ( *it < K )
			{
				std::vector<size_t> restOfSubset( it + 1, Subset.end() );
				if ( SubsetSum( restOfSubset, K - *it, SubsetOut ) )
				{
					SubsetOut.push_front( *it );
					return true;
				}
			}
		}
	}
	return false;
}

void Problem23::RunTest()
{
	std::vector<size_t> test{ 12,1,61,5,9,2 };
	std::deque<size_t> subsetOut;
	std::printf( "\nProblem23\n" );
	if ( SubsetSum( test, 24, subsetOut ) )
	{
		Util::PrintContainer( subsetOut );
	}
}
