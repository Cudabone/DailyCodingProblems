#include "Problem31.h"

//Given an array of numbers, find the maximum sum of any contiguous subarray of the array.
//
//For example, given the array[34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.
//
//Given the array[-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.
//
//Do this in O( N ) time.

#include <vector>

size_t MaxContiguousSum( const std::vector<int> input )
{
	int maxsum = 0;
	int localsum = 0;
	std::vector<int>::const_iterator end = input.begin();

	for ( const int num : input )
	{
		if ( localsum + num > 0 )
		{
			localsum += num;
			if ( localsum > maxsum )
			{
				maxsum = localsum;
			}
		}
		else
		{
			localsum = 0;
		}
	}
	return (size_t)maxsum;
}

void Problem31::RunTest()
{
	std::vector<int> test1{ 34,-50,42,14,-5,86 };
	std::vector<int> test2{ -5,-1,-8,-9 };
	std::printf( "\nProblem31:\n" );
	Util::PrintContainer( test1 );
	std::printf( "Max contiguous subarray sum: %zu\n", MaxContiguousSum( test1 ) );
	Util::PrintContainer( test2 );
	std::printf( "Max contiguous subarray sum: %zu\n", MaxContiguousSum( test2 ) );
}
