//Given an array of integers, find the first missing positive integer in linear time and constant space.In other words, find the lowest positive integer that does not exist in the array.The array can contain duplicates and negative numbers as well.
//
//For example, the input[3, 4, -1, 1] should give 2. The input[1, 2, 0] should give 3.
//
//You can modify the input array in - place.
#include "Problem3.h"
#include "Util.h"

std::size_t Solution( std::vector<int>& input )
{
	//remove negative elements ( they dont matter and will mess with the alg.
	for ( std::vector<int>::iterator it = input.begin(); it != input.end(); )
	{
		if ( *it < 0 )
		{
			std::swap( *it, *(input.end() - 1) );
			input.pop_back();
		}
		else
		{
			it++;
		}
	}

	//Mark number in vector negative if its index number has been seen
	for ( std::size_t i = 0; i < input.size(); ++i )
	{
		std::size_t index = std::abs( input[i] );
		if ( index < input.size() )
		{
			input[index] = -input[index]; //use index to mark the number as seen
		}
	}

	//Return lowest number which hasn't been seen, else return the size()
	for ( std::size_t i = 0; i < input.size(); ++i )
	{
		if ( input[i] > 0 && i > 0)
		{
			return i;
		}
	}
	return input.size();
}

void Problem3::RunTest()
{
	std::printf( "\n\nProblem3:\n" );
	std::vector<int> test1 = { 3,4,-1,1 };
	Util::PrintContainer( test1 );
	std::printf( "%u\n", static_cast<unsigned int>( Solution( test1 ) ) );
	test1 = { 3,2,1,0};
	Util::PrintContainer( test1 );
	std::printf( "%u\n", static_cast<unsigned int>( Solution( test1 ) ) );
}
