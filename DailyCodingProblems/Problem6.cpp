#include "Problem6.h"
#include <vector>
#include <algorithm>

//Given a list of integers, write a function that returns the largest sum of non - adjacent numbers.Numbers can be 0 or negative.
//
//For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.[5, 1, 1, 5] should return 10, since we pick 5 and 5.
//
//Follow - up: Can you do this in O( N ) time and constant space ?

template<typename T>
struct ValidType
{
	using value_type = T;

	ValidType() :valid( false ) {}
	ValidType( const T& val ) :value( val ), valid( true ) {}

	void operator=( T val )
	{
		value = val;
		valid = true;
	}

	bool IsValid() { return valid; }

	operator T()
	{
		return value;
	}

private:
	T value;
	bool valid;
};

int LargestNonAdjacentSum( const std::vector<int>& input, const size_t index, std::vector<ValidType<int>>& memory )
{
	if ( index >= input.size() )
	{
		return 0;
	}
	if ( memory[index].IsValid() )
	{
		return memory[index];
	}
	else
	{
		if ( input.size() - index == 1 )
		{
			memory[index] = input[index];
		}
		else if ( input.size() - index == 2 )
		{
			memory[index] = std::max( input[index], input[index + 1] );
		}
		else
		{
			memory[index] = std::max( input[index] + LargestNonAdjacentSum( input, index + 2, memory ), input[index + 1] + LargestNonAdjacentSum( input, index + 3, memory ) );
		}
		return memory[index];
	}
}

int LargestNonAdjacentSum( const std::vector<int>& input )
{
	std::vector<ValidType<int>> memory( input.size(), ValidType<int>() );
	return LargestNonAdjacentSum( input, 0 , memory);
}

void Problem6::RunTest()
{
	std::vector<int> temp = { 2,4,6,2,5 };
	std::printf( "\nProblem6:\n%d\n", LargestNonAdjacentSum( temp ) );
}

