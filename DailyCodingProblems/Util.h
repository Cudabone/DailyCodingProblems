#pragma once
#include <iostream>
#include <vector>

namespace Util
{
	template<typename Container>
	void PrintContainer( const Container& c )
	{
		typename Container::const_iterator it = std::begin( c );
		typename Container::const_iterator end = std::end( c );
		std::cout << "[";
		if ( it != end )
		{
			std::cout << *it;
			it++;
		}
		while ( it != end )
		{
			std::cout << ", " << *it;
			++it;
		}
		std::cout << "]\n";
	}
}

