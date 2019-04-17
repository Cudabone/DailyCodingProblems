#include "Problem22.h"

//Given an unordered list of flights taken by someone, each represented as( origin, destination ) pairs, 
//and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. 
//If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.
//
//For example, given the list of flights[( 'SFO', 'HKO' ), ( 'YYZ', 'SFO' ), ( 'YUL', 'YYZ' ), ( 'HKO', 'ORD' )]
//and starting airport 'YUL', you should return the list['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].
//
//Given the list of flights[( 'SFO', 'COM' ), ( 'COM', 'YYZ' )] and starting airport 'COM', you should return null.
//
//Given the list of flights[( 'A', 'B' ), ( 'A', 'C' ), ( 'B', 'C' ), ( 'C', 'A' )] and starting airport 'A', 
//you should return the list['A', 'B', 'C', 'A', 'C'] even though['A', 'C', 'A', 'B', 'C'] is also a valid itinerary.However, the first one is lexicographically smaller.
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include "Util.h"
#include <stack>

using Flight = std::pair<std::string, std::string>;

std::ostream& operator<<( std::ostream& os, const Flight& f )
{
	os << "(" << f.first << "," << f.second << ")";
	return os;
}

bool ValidItinerary( const std::vector<Flight>& Flights, const std::string Start, std::deque<std::string>& Itinerary )
{
	//list of starting flights
	std::vector<Flight> departures;
	for ( const Flight& f : Flights )
	{
		if ( f.first == Start )
		{
			departures.push_back( f );
		}
	}

	for ( size_t i = 0; i < departures.size(); i++ )
	{
		//check if you can find a valid iternerary with this flight removed from the list
		std::vector<Flight> remainingFlights;
		for ( const Flight& f : Flights )
		{
			if ( f != departures[i] )
			{
				remainingFlights.push_back( f );
			}
		}

		//Last flight of the Itinerary
		if ( 1 == departures.size() && remainingFlights.empty() )
		{
			Itinerary.push_front( departures[i].second );
			Itinerary.push_front( departures[i].first );
			return true;
		}

		if ( ValidItinerary( remainingFlights, departures[i].second, Itinerary ) )
		{
			Itinerary.push_front( departures[i].first );
			return true;
		}
	}

	return false;
}



void Problem22::RunTest()
{
	std::printf( "\nProblem22:\n" );
	std::vector<Flight> flights{ {"SFO","HKO"}, {"YYZ","SFO"}, {"YUL","YYZ"}, {"HKO","ORD"} };
	std::deque<std::string> ItineraryOut;
	if ( ValidItinerary( flights, "YUL", ItineraryOut ) )
	{
		Util::PrintContainer(ItineraryOut);
	}
}