//A string S of lowercase letters is given.We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
//
//Example 1:
//Input: S = "ababcbacadefegdehijhklij"
//	Output : [9, 7, 8]
//	Explanation :
//	The partition is "ababcbaca", "defegde", "hijhklij".
//	This is a partition so that each letter appears in at most one part.
//	A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
//	Note :
//
//	S will have length in range[1, 500].
//	S will consist of lowercase letters( 'a' to 'z' ) only.

//Complete this in 36 minutes. //We completed it in 10 minutes.

#include "Problem32.h"
#include <vector>
#include <string>

std::vector<size_t> Partition( std::string s )
{
	std::vector<size_t> partitions;
	size_t start = 0;
	size_t farthest = s.find_last_of( s[0] );
	for ( int i = 1; i < s.size(); ++i )
	{
		if ( i == farthest )
		{
			partitions.push_back( farthest - start + 1 );
			start = i + 1;
		}
		else 
		{
			size_t next = s.find_last_of( s[i] );
			if ( next > farthest )
			{
				farthest = next;
			}
		}
	}
	return partitions;
}

void Problem32::RunTest()
{
	std::printf( "\nProblem32:\n" );
	std::string s( "ababcbacadefegdehijhklij" );
	std::printf( "input: %s\noutput: ", s.c_str() );
	Util::PrintContainer( Partition( s ) );
}
