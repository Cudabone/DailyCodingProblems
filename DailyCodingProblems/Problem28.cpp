#include "Problem28.h"
#include <string>

//Given a string, find the longest palindromic contiguous substring.If there are more than one with the maximum length, return any one.
//
//For example, the longest palindromic substring of "aabcdcb" is "bcdcb".The longest palindromic substring of "bananas" is "anana".

std::string LongestPalindrome( const std::string s )
{
	std::string longest;
	for ( size_t i = 0; i < s.size(); ++i )
	{
		size_t leftidx = i > 0 ? i - 1 : 0;
		size_t rightidx = i < s.size() - 1 ? i + 1 : s.size();
		if ( i > 0 && rightidx < s.size() )
		{
			// ex "aa" i = 0
			if ( s[i] == s[rightidx] )
			{
				leftidx = i;
			}
			// ex "aba", i = 1
			else if ( s[leftidx] != s[rightidx] )
			{
				continue;
			}

			while ( leftidx != 0 && rightidx + 1 < s.size() && s[leftidx - 1] == s[rightidx + 1] )
			{
				--leftidx;
				++rightidx;
			}
			const size_t length = rightidx - leftidx + 1;
			if ( length > longest.size() )
			{
				longest = s.substr( leftidx, length );
			}
		}
	}
	return longest;
}

void Problem28::RunTest()
{
	std::string test( "aabcdcb" );
	std::string test2( "abannables" );
	std::string test3( "banana" );
	std::printf( "\nProblem28:\n" );
	std::printf( "Longest palindrome in %s: %s\n", test.c_str(), LongestPalindrome( test ).c_str() );
	std::printf( "Longest palindrome in %s: %s\n", test2.c_str(), LongestPalindrome( test2 ).c_str() );
	std::printf( "Longest palindrome in %s: %s\n", test3.c_str(), LongestPalindrome( test3 ).c_str() );
}