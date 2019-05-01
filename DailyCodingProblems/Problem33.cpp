#include "Problem33.h"
//Given a non - negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//	Input : num = "1432219", k = 3
//	Output : "1219"
//	Explanation : Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//	Example 2 :
//
//	Input : num = "10200", k = 1
//	Output : "200"
//	Explanation : Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//	Example 3 :
//
//	Input : num = "10", k = 2
//	Output : "0"
//	Explanation : Remove all the digits from the number and it is left with nothing which is 0.

#include <string>

std::string LowestString( std::string s, size_t k )
{
	std::string output = s;
	while ( k > 0 )
	{
		bool removed = false;
		for ( size_t i = 0; i < output.size() - 1; ++i )
		{
			if ( output[i] > output[i + 1] )
			{
				output = output.substr( 0, i ) + output.substr( i + 1, output.size() - i );
				removed = true;
				break;
			}
		}
		if ( !removed && output.size() > 0 )
		{
			output.pop_back();
		}

		if ( output.size() == 0 )
		{
			return "0";
		}
		--k;
	}
	//remove all leading zeros
	size_t i = 0;
	while ( i < output.size() && output[i] == '0' )
	{
		++i;
	}
	output = output.substr( i, output.size() - i );

	return output;
}


void Problem33::RunTest()
{
	std::string s1( "1432219" );
	std::string s2( "10200" );
	std::string s3( "10" );
	size_t k1 = 3;
	size_t k2 = 1;
	size_t k3 = 2;

	std::printf( "\nProblem33:\n" );
	std::printf( "Input: %s, output: %s\n", s1.c_str(), LowestString( s1, k1 ).c_str() );
	std::printf( "Input: %s, output: %s\n", s2.c_str(), LowestString( s2, k2 ).c_str() );
	std::printf( "Input: %s, output: %s\n", s3.c_str(), LowestString( s3, k3 ).c_str() );
}

