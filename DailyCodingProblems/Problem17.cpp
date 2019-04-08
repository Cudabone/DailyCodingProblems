//Good morning!
//Here's your coding interview problem for today.
//
//This problem was asked by Google.
//
//Given an array of strictly the characters 'R', 'G', and 'B', 
//segregate the values of the array so that all the Rs come first, 
//the Gs come second, and the Bs come last.You can only swap elements of the array.
//
//Do this in linear time and in - place.
//
//For example, given the array['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become['R', 'R', 'R', 'G', 'G', 'B', 'B'].

#include "Problems.h"
#include <string>

void RGBSort( std::string& input )
{
	size_t ridx = 0;
	for ( size_t i = 0; i < input.size(); ++i )
	{
		if ( input[i] == 'R' )
		{
			std::swap( input[i], input[ridx] );
			++ridx;
		}
	}
	size_t gidx = ridx;
	for ( size_t i = gidx; i < input.size(); ++i )
	{
		if ( input[i] == 'G' )
		{
			std::swap( input[i], input[gidx] );
			++gidx;
		}
	}
}


void Problem17::RunTest()
{
	std::string input = "GBRRBRG";
	std::printf( "\nProblem17:\n" );
	RGBSort( input );
	std::printf( "%s\n", input.c_str() );
}