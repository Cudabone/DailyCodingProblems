#include "Problems.h"

//Given an array of time intervals( start, end ) for classroom lectures( possibly overlapping ), find the minimum number of rooms required.
//
//For example, given[(30, 75), (0, 50), (60, 150)], you should return 2.

#include <vector>
#include <algorithm>

using Interval = std::pair<uint, uint>;
using Intervals = std::vector<Interval>;

//bool fits( const Interval& time, const Intervals& slotsAvailable )
//{
//	for ( const Interval& i : slotsAvailable )
//	{
//		if ( time.first >= i.first && time.second <= i.second )
//		{
//			return true;
//		}
//	}
//	return false;
//}

size_t MinRooms( Intervals& times )
{
	std::vector<Intervals> rooms;
	std::sort( times.begin(), times.end(), []( const Interval& lhs, const Interval& rhs ) { return lhs.first < rhs.first; } );
	rooms.emplace_back();
	for ( const Interval& time : times )
	{
		bool foundRoom = false;
		for ( Intervals& room : rooms )
		{
			bool fits = true;
			for ( const Interval& i : room )
			{
				if ( time.first >= i.first && time.first <= i.second
					|| time.second >= i.first && time.second <= i.second )
				{
					fits = false;
				}
			}
			if ( fits )
			{
				room.push_back( time );
				foundRoom = true;
				break;
			}
		}
		if ( !foundRoom )
		{
			rooms.emplace_back( 1, time );
		}
	}
	return rooms.size();
}

size_t MinRooms2( const Intervals& times )
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
	size_t overlap = 0;
	while ( true )
	{
		if( arrivals[i] < departures[i] )
	}
}

void Problem14::RunTest()
{
	std::vector<std::pair<uint,uint>> times = { {30,75}, {0,50}, {60,150} };
	std::printf( "\nProblem14:\n" );
	std::printf( "Min Rooms: %zu\n", MinRooms( times ) );
}
