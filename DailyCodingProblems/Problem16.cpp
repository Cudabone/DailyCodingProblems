<<<<<<< HEAD
//Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced( well - formed ).
//
//For example, given the string "([])[]({})", you should return true.
//
//Given the string "([)]" or "((()", you should return false.

#include "Problems.h"
#include <string>

bool Balanced( std::string s )
{
	int numCurly = 0;
	int numBracket = 0;
	int numParen = 0;
	for ( size_t i = 0; i < s.size(); ++i )
	{
		switch ( s[i] )
		{
			case '(':
				numParen++;
				break;
			case ')':
				numParen--;
				break;
			case '[':
				numBracket++;
				break;
			case ']':
				numBracket--;
				break;
			case '{':
				numCurly++;
				break;
			case '}':
				numCurly--;
				break;
			default:
				break;
		}
	}
	return true;
=======
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
>>>>>>> 5c8ffc5bd788279acd2466f156611e4fb464b52c
}

void Problem15::RunTest()
{
<<<<<<< HEAD
	std::string a = "([])[]({})";
	std::string b = "([)]";
	std::printf( "\nProblem15:\n" );
	std::printf( "%s : %d", a.c_str(), Balanced( a ) );
	std::printf( "%s : %d", b.c_str(), Balanced( b ) );
}
=======
	std::string input( "Please string replace me" );
	std::vector<Replacement> replacements;
	replacements.push_back( { 1,"leas","e" } );
	replacements.push_back( { 7, "str", "" } );
	replacements.push_back( { 16, "place", "aaaaaa" } );
	std::printf( "\nProblem15:\n");
	std::printf( "Replaced string: %s\n", Replace( input, replacements ).c_str() );
}
>>>>>>> 5c8ffc5bd788279acd2466f156611e4fb464b52c
