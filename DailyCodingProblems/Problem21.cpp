#include "Problem21.h"

//You are given an array of non - negative integers that represents a two - dimensional elevation map where each element is unit - width wall and the integer is the height.Suppose it will rain and all spots between two walls get filled up.
//
//Compute how many units of water remain trapped on the map in O( N ) time and O( 1 ) space.
//
//For example, given the input[2, 1, 2], we can hold 1 unit of water in the middle.
//
//Given the input[3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index( we cannot hold 5 since it would run off to the left ), so we can trap 8 units of water.

#include <iostream>
#include <vector>

size_t WaterHeld( std::vector<size_t> walls )
{
	size_t totalwater = 0;
	size_t currentwater = 0;
	size_t wallsum = 0; // space that water can't be held in for the current area
	size_t height = 0; //starting wall
	size_t startidx = 0;
	for ( size_t i = 0; i < walls.size(); ++i )
	{
		if ( walls[i] > height )
		{
			//add the water accumulated so far
			totalwater += ( ( i - ( startidx + 1 ) ) * height ) - wallsum;

			//start a new area
			height = walls[i];
			startidx = i;
			wallsum = 0;
			currentwater = 0;
		}
		else
		{
			//calculate the water held up to this point
			currentwater = ( ( i - ( startidx + 1 ) ) * walls[i] ) - wallsum;
			wallsum += walls[i];
		}
	}

	return totalwater + currentwater;
}

void Problem21::RunTest()
{
	std::vector<size_t> water{ 3, 0, 1, 3, 0, 5 };
	std::vector<size_t> water2{ 2, 1, 2 };
	std::printf( "\nProblem21:\n" );
	std::printf( "Total Water Held: %zu\n", WaterHeld( water ) );
	std::printf( "Total Water Held: %zu\n", WaterHeld( water2 ) );
}