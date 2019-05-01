#pragma once
#include "Util.h"
#include <vector>
#include <iterator>
DECLARE_PROBLEM( 25 );

template<typename Iterator>
size_t MergeInversions( const Iterator Begin, const Iterator Middle, const Iterator End )
{
	std::vector<typename Iterator::value_type> temp;
	Iterator LhsIt = Begin;
	const Iterator LhsEnd = Middle;
	Iterator RhsIt = Middle;
	const Iterator RhsEnd = End;

	size_t inversions = 0;

	//Merge the two sides
	while ( LhsIt != LhsEnd && RhsIt != RhsEnd )
	{
		if ( *LhsIt < *RhsIt )
		{
			temp.push_back( *LhsIt );
			LhsIt++;
		}
		else
		{
			inversions += std::distance( LhsIt, LhsEnd );
			temp.push_back( *RhsIt );
			RhsIt++;
		}
	}

	//Insert remaining elements from left or right side
	while ( LhsIt != LhsEnd )
	{
		temp.push_back( *LhsIt );
		LhsIt++;
	}
	while ( RhsIt != RhsEnd )
	{
		temp.push_back( *RhsIt );
		RhsIt++;
	}

	Iterator it = Begin;
	for ( std::size_t i = 0; i < temp.size(); ++i )
	{
		*(it++) = temp[i];
	}

	return inversions;
}

template<typename Iterator>
size_t MergeSortInversions( const Iterator begin, const Iterator end )
{
	typename std::iterator_traits<Iterator>::difference_type size = std::distance( begin, end );
	if ( size <= 1 )
	{
		return 0;
	}
	else
	{
		const std::size_t middle = static_cast<std::size_t>(size / 2);
		size_t inversions = MergeSortInversions( begin, begin + middle );
		inversions += MergeSortInversions( begin + middle, end );
		inversions += MergeInversions( begin, begin + middle, end );
		return inversions;
	}
}
