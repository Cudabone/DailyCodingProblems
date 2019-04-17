#include "Problem25.h"

//We can determine how "out of order" an array A is by counting the number of inversions it has.
//Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j.
//	That is, a smaller element appears after a larger element.
//
//	Given an array, count the number of inversions it has.Do this faster than O( N ^ 2 ) time.
//
//	You may assume each element in the array is distinct.
//
//	For example, a sorted list has zero inversions.
//	The array[2, 4, 1, 3, 5] has three inversions : (2, 1), (4, 1), and (4, 3).
//	The array[5, 4, 3, 2, 1] has ten inversions : every distinct pair forms an inversion.

//Original solution, was to create a binary tree where each node knows how many elements are in its left and right subtrees
// O(nlogn), Iterate over the array, inserting the element into the tree, if elt < root, inversions += 1 + root.right.count

//Other solution, is to count them when doing a merge sort. O(nlogn)

#include <vector>
#include <iostream>

void Problem25::RunTest()
{
	std::vector<int> test1{ 2,4,1,3,5 };
	std::vector<int> test2{ 5,4,3,2,1 };
	std::printf( "\nProblem25:\n" );
	Util::PrintContainer( test1 );
	std::printf( "Inversions: %zu\n", MergeSortInversions( test1.begin(), test1.end() ) );
	Util::PrintContainer( test2 );
	std::printf( "Inversions: %zu\n", MergeSortInversions( test2.begin(), test2.end() ) );
}
