//Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced( well - formed ).
//
//For example, given the string "([])[]({})", you should return true.
//
//Given the string "([)]" or "((()", you should return false.

#include "Problems.h"
#include <string>
#include <stack>

bool Balanced( std::string s )
{
	int numCurly = 0;
	int numBracket = 0;
	int numParen = 0;

	//stack of characters expected to close the sequence in order
	std::stack<char> closingChars;

	for ( size_t i = 0; i < s.size(); ++i )
	{
		switch ( s[i] )
		{
		case '(':
			closingChars.push(')');
			numParen++;
			break;
		case ')':
			numParen--;
			break;
		case '[':
			closingChars.push(']');
			numBracket++;
			break;
		case ']':
			numBracket--;
			break;
		case '{':
			closingChars.push('}');
			numCurly++;
			break;
		case '}':
			numCurly--;
			break;
		default:
			break;
		}

		if ( s[i] == ')' || s[i] == ']' || s[i] == '}' )
		{
			if ( closingChars.size() < 1 )
			{
				return false;
			}
			if ( s[i] != closingChars.top() )
			{
				return false;
			}
			closingChars.pop();
		}

		if ( numCurly < 0 || numBracket < 0 || numParen < 0 )
		{
			return false;
		}
	}
	return true;
}
void Problem16::RunTest()
{
	std::string a = "([])[]({})";
	std::string b = "([)]";
	std::printf( "\nProblem15:\n" );
	std::printf( "%s : %d\n", a.c_str(), Balanced( a ) );
	std::printf( "%s : %d\n", b.c_str(), Balanced( b ) );
}

