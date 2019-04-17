#include "Problem30.h"
#include <queue>
//Compute the running median of a sequence of numbers.That is, given a stream of numbers, print out the median of the list so far on each new element.
//
//Recall that the median of an even - numbered list is the average of the two middle numbers.
//
//For example, given the sequence[2, 1, 5, 7, 2, 0, 5], your algorithm should print out :
//
//2
//1.5
//2
//3.5
//2
//2
//2

void RunningMedian( const std::vector<int>& stream )
{
	std::priority_queue<int> lhs;
	std::priority_queue<int, std::vector<int>, std::greater<int>> rhs;
	
	for ( const int number : stream )
	{
		float median = 0.0f;
		if ( lhs.size() > rhs.size() )
		{
			//previous median
			if ( number > lhs.top() )
			{
				rhs.push( number );
			}
			else
			{
				rhs.push( lhs.top() );
				lhs.pop();
				lhs.push( number );
			}
			median = (lhs.top() + rhs.top()) / 2.0f;
		}
		else if ( rhs.size() > lhs.size() )
		{
			if ( number < rhs.top() )
			{
				lhs.push( number );
			}
			else
			{
				lhs.push( rhs.top() );
				rhs.pop();
				rhs.push( number );
			}
			median = (lhs.top() + rhs.top()) / 2.0f;
		}
		else
		{
			if ( lhs.size() == 0 || number < lhs.top() )
			{
				lhs.push( number );
				median = static_cast<float>(lhs.top());
			}
			else
			{
				rhs.push( number );
				median = static_cast<float>(rhs.top());
			}
		}
		std::cout << "Median: " << median << std::endl;
	}
}

void Problem30::RunTest()
{
	std::vector<int> test{ 2,1,5,7,2,0,5 };
	std::printf( "\nProblem30:\n" );
	RunningMedian( test );
}