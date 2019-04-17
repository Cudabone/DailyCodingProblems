#include "Problem12.h"

//A builder is looking to build a row of N houses that can be of K different colors.
//He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.
//
//Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color,
//return the minimum cost which achieves this goal.
#include <algorithm>

template<size_t rows, size_t cols>
int MinColoring( int (&M)[rows][cols] )
{
	//Set up the first row of the temporary matrix to accumulate the minimum cost
	//The cost of the first row is simply the cost of painting the house.
	int Cost[rows][cols];
	for ( size_t j = 0; j < cols; ++j )
	{
		Cost[0][j] = M[0][j];
	}

	for ( size_t i = 1; i < rows; ++i )
	{
		for ( size_t j = 0; j < cols; ++j )
		{
			//Find the minimum cost of the previous row excluding this column
			int PrevRowMin = j == 0 ? M[i - 1][1] : M[i - 1][0];
			for ( size_t k = 0; k < cols; ++k )
			{
				if ( k != j && Cost[i - 1][k] < PrevRowMin )
				{
					PrevRowMin = Cost[i - 1][k];
				}
			}

			//cost of this choice is the cost to paint the house
			//plus the minimum cost of the previous row excluding this color
			Cost[i][j] = M[i][j] + PrevRowMin;
		}
	}

	return *std::min_element( std::begin(Cost[rows-1]), std::end(Cost[rows-1]) );
}

//O( NK^2 )
void Problem12::RunTest()
{
	std::printf( "\nProblem12:\n" );
	int M[3][3] = { {1,2,3}, {3,0,1}, {6,4,0} };
	std::printf( "Min Cost is: %d\n", MinColoring( M ) );
}