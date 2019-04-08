#include "Problems.h"

//The power set of a set is the set of all its subsets.Write a function that, given a set, generates its power set.
//
//For example, given the set{ 1, 2, 3 }, it should return { {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3} }.
//
//You may also use a list or array to represent a set.


#include <vector>
#include <cassert>
#include <algorithm>
#include "Util.h"

inline bool CheckBit( long I, size_t bit )
{
	return I & (1 << bit);
}

const std::vector<std::vector<int>> PowerSets( const std::vector<int>& input )
{
	std::vector<std::vector<int>> powersets;

	unsigned int setbits = 0;
	assert( input.size() <= sizeof( setbits )*8);

	const unsigned int lastbit = 1 << input.size();
	for ( ; setbits < lastbit; ++setbits )
	{
		std::vector<int> set;
		for ( size_t i = 0; i < input.size(); i++ )
		{
			if ( CheckBit( setbits, i ) )
			{
				set.push_back( input[i] );
			}
		}
		powersets.push_back( set );
	}

	std::sort( powersets.begin(), powersets.end(), []( const std::vector<int>& lhs, const std::vector<int>& rhs ) { return lhs.size() < rhs.size(); } );

	return powersets;
}

void Problem19::RunTest()
{
	std::vector<int> set{ 1,2,3,4,5 };
	std::printf( "\nProblem19:\n" );
	Util::PrintContainer( set );
	const auto powerset = PowerSets( set );
	for ( const auto& vec : powerset )
	{
		Util::PrintContainer( vec );
	}
}