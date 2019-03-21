//Given a string and a set of replacements.

#include "Problems.h"
#include <string>
#include <vector>
#include <algorithm>

struct Replacement
{
	int index; //index of where the before string starts
	std::string before; //string that currently exists
	std::string after; //string to change it to
};

/*
Approaches:
n = number of changes.
k = size of the string
1. sort, and append each replacement to the unchanged string: O(nlogn + n)
2. Insert changes into string, keeping track of the new offset of the index
based on the difference between the string before and the string afer. 
for each change = O( n )
	insert or remove the difference between before and after.
	d = difference
	insertion/removal ~ O( n )
	O( dn )

Total => O(n^2)
*/

std::string Replace( std::string s, std::vector<Replacement>& Replacements )
{
	std::sort( Replacements.begin(), Replacements.end(),
		[]( const Replacement& lhs, const Replacement& rhs ) { return lhs.index < rhs.index; } );

	//O nlogn
	std::string output;
	size_t index = 0;

	//~O(k) assuming before and after string are about the same size
	for ( const Replacement& r : Replacements )
	{
		//O( 1 ) * c chars = c
		output += s.substr( index, r.index - index );
		output += r.after;
		index = r.index + r.before.size();
	}
	output += s.substr( index, s.size() - index );

	return output;
}

void Problem15::RunTest()
{
	std::string input( "Please string replace me" );
	std::vector<Replacement> replacements;
	replacements.push_back( { 1,"leas","e" } );
	replacements.push_back( { 7, "str", "" } );
	replacements.push_back( { 16, "place", "aaaaaa" } );
	std::printf( "\nProblem15:\n");
	std::printf( "Replaced string: %s\n", Replace( input, replacements ).c_str() );
}
