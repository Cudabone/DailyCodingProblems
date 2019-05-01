#pragma once
#include <iostream>
#include <vector>
#include <iterator>

using uint = unsigned int;

#define DECLARE_PROBLEM(num) \
namespace Problem##num \
{ \
	void RunTest(); \
}

namespace Util
{
	template<typename Container>
	void PrintContainer( const Container& c )
	{
		auto it = std::cbegin( c );
		auto end = std::cend( c );
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

