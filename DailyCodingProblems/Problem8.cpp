//There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.Given N, write a function that returns the number of unique ways you can climb the staircase.The order of the steps matters.
//
//For example, if N is 4, then there are 5 unique ways :
//
//1, 1, 1, 1
//2, 1, 1
//1, 2, 1
//1, 1, 2
//2, 2
//What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X ? For example, if X = { 1, 3, 5 }, you could climb 1, 3, or 5 steps at a time.
#include "Problem8.h"
#include "Util.h"
#include <cstdio>
#include <vector>
#include <iostream>

uint NumWaysRecurse( const uint NumStairs, uint Stair )
{
	if ( Stair >= NumStairs )
	{
		return 0;
	}
	else if ( Stair + 1 == NumStairs )
	{
		return 1;
	}
	else if ( Stair + 2 == NumStairs )
	{
		return 2;
	}
	else
	{
		return NumWaysRecurse( NumStairs, Stair + 1 ) + NumWaysRecurse( NumStairs, Stair + 2 );
	}
}

uint NumWaysRecurse( const uint NumStairs, const std::vector<uint>& Steps, uint Stair )
{
	uint ways = 0;
	if ( Stair >= NumStairs )
	{
		return 0;
	}

	for ( const uint step : Steps )
	{
		if ( step + Stair == NumStairs )
		{
			ways++;
		}
		else if ( step + Stair < NumStairs )
		{
			ways += NumWaysRecurse( NumStairs, Steps, Stair + step );
		}
	}
	return ways;
}

uint NumWays( const uint NumStairs, const std::vector<uint>& Steps )
{
	return NumWaysRecurse( NumStairs, Steps, 0 );
}

const uint NumWays( const uint NumStairs )
{
	return NumWaysRecurse( NumStairs, 0 );
}

void Problem8::RunTest()
{
	uint k = 4;
	std::vector<uint> steps = { 1,2 };
	std::printf( "\nProblem8:\n" );
	std::printf( "NumWays %u, Steps {1,2}: %u\n", k, NumWays( k, steps ) );
	steps = { 1,3,5 };
	std::printf( "NumWays %u, Steps {1,3,5}: %u\n", k, NumWays( k, steps ) );
	k = 5;
	std::printf( "NumWays %u: Steps {1,3,5}: %u\n", k, NumWays( k, steps ) );
}
