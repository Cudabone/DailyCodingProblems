#include "Problem14.h"

//Given an array of time intervals( start, end ) for classroom lectures( possibly overlapping ), find the minimum number of rooms required.
//
//For example, given[(30, 75), (0, 50), (60, 150)], you should return 2.

#include <vector>
#include <algorithm>
#include <cassert>

using Interval = std::pair<uint, uint>;

const size_t MinRooms( const std::vector<Interval>& times )
{
	std::vector<uint> arrivals;
	std::vector<uint> departures;
	for ( const Interval& time: times )
	{
		arrivals.push_back( time.first );
		departures.push_back( time.second );
	}

	std::sort( arrivals.begin(), arrivals.end() );
	std::sort( departures.begin(), departures.end() );

	size_t i = 0;
	size_t j = 0;
	size_t maxRooms = 0;
	size_t roomsNeeded = 0;
	while ( i < arrivals.size() )
	{
		if ( arrivals[i] < departures[j] )
		{
			roomsNeeded++;
			i++;
			if ( roomsNeeded > maxRooms )
			{
				maxRooms = roomsNeeded;
			}
		}
		else
		{
			roomsNeeded--;
			j++;
		}
	}

	// We can assume that at the end of the while loop, no more arrivals will be happening because
	// starting time < ending times and they are processed in order of time.
	// Also we no longer need to process departures since the number of rooms needed will only be decreasing

	assert( i == arrivals.size() );
	return maxRooms;
}

void Problem14::RunTest()
{
	std::vector<std::pair<uint,uint>> times = { {30,75}, {0,50}, {60,150} };
	std::printf( "\nProblem14:\n" );
	std::printf( "Min Rooms: %zu\n", MinRooms( times ) );
}
