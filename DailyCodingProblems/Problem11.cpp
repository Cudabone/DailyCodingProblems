#include "Problems.h"
#include <vector>

//This problem was asked by Google.
//
//Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.
//
//For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get : [10, 7, 8, 8], since :
//
//	10 = max( 10, 5, 2 )
//	7 = max( 5, 2, 7 )
//	8 = max( 2, 7, 8 )
//	8 = max( 7, 8, 7 )
//	Do this in O( n ) time and O( k ) space.You can modify the input array in - place and you do not need to store the results.
//	You can simply print them out as you compute them.
#include <deque>

void MaxOfSubarray( std::vector<int>& Nums, const size_t K )
{
	// 1: 0, k-1, 
	// 2: 1, k
	// 3: 2, k+1
	// [10 5 2 7 8] k = 3, [10 5 2] [5 2 7] [2 7 8]
	// [10 5 2]

	//O(subarray) * #subarrays; O(subarray) = k, max of the current and prev result. #subarrays = (n - k + 1)
	// O(k(n - k + 1) = O(kn)
	std::deque<int> q;
	int max = Nums[0];
	size_t i;
	for ( i = 0; i < K; ++i )
	{
		q.push_back( Nums[i] );
		if ( Nums[i] > max )
		{
			max = Nums[i];
		}
	}

	for ( ; i < Nums.size(); i++ )
	{
		q.pop_front();
		q.push_back( Nums[i] );
		max = q.front();
		for ( size_t j = 0; j < q.size(); j++ )
		{
			if ( q[j] > max )
			{
				max = q[j];
			}
		}
	}
}

void MaxOfSubarray2( std::vector<int> Nums, const size_t K )
{
	std::deque<size_t> q;
	size_t i;
	for ( i = 0; i < K; ++i )
	{
		//Remove any elements less than the current element from the list,
		//they will not be needed for comparison.
		while ( !q.empty() && Nums[i] >= Nums[q.back()] )
		{
			q.pop_back();
		}
		q.push_back( i );
	}

	for ( ; i < Nums.size(); ++i )
	{
		//remove any elements which arent in this subarray;
		//guarenteed to be in order from 0->N
		std::printf( "%d ", Nums[q.front()] );
		while ( !q.empty() && q.front() < i - K + 1)
		{
			q.pop_front();
		}

		while ( !q.empty() && Nums[i] >= Nums[q.back()] )
		{
			q.pop_back();
		}

		q.push_back( i );
	}
	std::printf( "%d\n", Nums[q.front()] );
}

//every element is at most added and removed once

void Problem11::RunTest()
{
	std::printf( "\nProblem11:\n" );
	std::printf( "Max of subarray [10, 5, 2, 7, 8, 7]: " );
	std::vector<int> nums = { 10,5,2,7,8,7 };
	MaxOfSubarray2( nums, 3 );
}
