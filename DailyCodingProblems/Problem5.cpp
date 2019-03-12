//Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
//
//For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
//
//You can assume that the messages are decodable.For example, '001' is not allowed.

#include <array>
#include <vector>
#include <string>
#include "Problems.h"
#include "Util.h"

int Permutations( const std::vector<int>::const_iterator begin, const std::vector<int>::const_iterator end )
{
	static constexpr std::array<char, 26> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	const auto size = end - begin;
	if ( size == 0 )
	{
		return 0;
	}
	else if ( size == 1 )
	{
		return 1;
	}
	else if ( size == 2 )
	{
		const std::string s = std::to_string( *begin ) + std::to_string( *(begin + 1) );
		const size_t num = static_cast<size_t>(std::atoi( s.c_str() ));
		if ( num <= alphabet.size() )
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return Permutations( begin + 1, end ) + (Permutations( begin, begin + 2 ) - 1)*Permutations( begin + 2, end );
	}
}

int Permutations( const std::vector<int>& nums )
{
	return Permutations( nums.cbegin(), nums.cend() );
}

void Problem5::RunTest()
{
	std::vector<int> nums = { 1,1,1,2 };
	std::printf( "\nProblem5:\n");
	Util::PrintContainer( nums );
	std::printf( "Permutations: %d\n", Permutations( nums ) );
	nums = { 1,2,1,3,1,1 };
	Util::PrintContainer( nums );
	std::printf( "Permutations: %d\n", Permutations( nums ) );
}
