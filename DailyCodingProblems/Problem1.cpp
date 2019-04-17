//Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
//
//For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
//
//Bonus: Can you do this in one pass ?
#include "Problem1.h"
#include "Util.h"
#include <vector>
#include <unordered_set>

bool Solution( const std::vector<int>& list, int k )
{
	std::unordered_set<int> matches;
	for ( const int& num : list )
	{
		if ( matches.find( num ) != matches.end() )
		{
			return true;
		}
		else
		{
			matches.insert( k - num );
		}
	}
	return false;
}

void Problem1::RunTest()
{
	const std::vector<int> testvec = { 10, 15, 3, 7 };
	std::printf( "Problem1:\nGiven a list of number and a number k,\nreturn whether any two numbers from the list add up to k.\n" );
	std::printf( "Test Vector: " );
	Util::PrintContainer( testvec );
	std::printf( " Test 1: K = 13, returned %d\n", Solution( testvec, 13 ) );
	std::printf( " Test 2: K = 32, returned %d\n", Solution( testvec, 22 ) );
	std::printf( " Test 3: K = 0, returned %d\n", Solution( testvec, 0 ) );
	std::printf( " Test 4: K = 10, returned %d\n", Solution( testvec, 10 ) );
	std::printf( " Test 5: K = 3, returned %d\n", Solution( testvec, 3 ) );
}
