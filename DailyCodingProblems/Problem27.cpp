#include "Problem27.h"

//Given a array of numbers representing the stock prices of a company in chronological order,
//write a function that calculates the maximum profit you could have made from buying and selling that stock once.You must buy before you can sell it.
//
//For example, given[9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

#include <vector>

size_t MaxProfit( std::vector<size_t> stocks )
{
	size_t maxprofit = 0;
	size_t max = 0;
	for ( std::vector<size_t>::const_reverse_iterator it = stocks.crbegin(); it != stocks.crend(); ++it )
	{
		if ( *it > max )
		{
			max = *it;
		}
		else if ( *it < max )
		{
			const size_t localprofit = max - *it;
			if ( localprofit > maxprofit )
			{
				maxprofit = localprofit;
			}
		}
	}
	return maxprofit;
}

void Problem27::RunTest()
{
	std::vector<size_t> test{ 9,11,8,5,7,10 };
	std::printf( "\nProblem27:\n" );
	Util::PrintContainer( test );
	std::printf( "Max profit: %zu\n", MaxProfit( test ) );
}