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
}

void Problem15::RunTest()
{
	std::string a = "([])[]({})";
	std::string b = "([)]";
	std::printf( "\nProblem15:\n" );
	std::printf( "%s : %d", a.c_str(), Balanced( a ) );
	std::printf( "%s : %d", b.c_str(), Balanced( b ) );
}