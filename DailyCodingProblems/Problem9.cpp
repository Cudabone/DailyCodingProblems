//Given an integer k and a string s, find the length of the longest substring 
//that contains at most k distinct characters.
//
//For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

#include "Problems.h"
#include <unordered_set>
#include <unordered_map>

size_t NumUniqueCharacters( const uint k, const std::string s )
{
	size_t first = 0; //first char
	size_t last = 0; //last char

	std::unordered_set<char> seen;
	std::unordered_map<char,uint> repeated; //map char to number of times it is repeated
	size_t numrepeated = 0;
	size_t maxlength = 0;

	while ( last < s.size() && last >= first )
	{
		// If we have not counted this character
		if ( seen.find( s[last] ) != seen.end() )
		{
			seen.insert( s[last] );
			last++;
		}
		// Else if we can repeat another character
		else if ( numrepeated < k )
		{
			std::unordered_map<char,uint>::iterator rit = repeated.find( s[last] );
			if ( rit != repeated.end() )
			{
				rit->second++;
			}
			else
			{
				repeated.insert( std::pair<char, uint>( s[last], 1 ) );
			}
			numrepeated++;
			last++;
		}
		// Else remove the first character from the substring we are checking
		else
		{
			std::unordered_map<char, uint>::iterator rit = repeated.find( s[first] );
			if ( rit != repeated.end() )
			{
				if ( rit->second == 1 ) //only repeated once and we can remove it
				{
					repeated.erase( rit );
				}
				else
				{
					rit->second--;
				}
				numrepeated--;
			}
			else //if not a repeated character we can mark it as unseen
			{
				seen.erase( s[first] );
			}
			first++;
		}

		//update the longest substring if longer
		const size_t length = last - first + 1;
		if ( length > maxlength )
		{
			maxlength = length;
		}
		else if ( last == s.size() - 1 && length <= maxlength )
		{
			break;
		}
	}
	return maxlength;
}

void Problem9::RunTest()
{
	std::printf( "\nProblem9:\n" );
	uint k = 2;
	std::string s = "abcba";
	std::printf( "Max substring k = %u, s = %s, %zu", k, s.c_str(), NumUniqueCharacters( k, s ) );
}
