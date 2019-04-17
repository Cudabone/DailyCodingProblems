#pragma once
#include "Util.h"
#include <vector>
#include <cassert>
namespace Problem24
{
	void RunTest();
}

//Implement a stack that has the following methods :
//
//push( val ), which pushes an element onto the stack
//pop(), which pops off and returns the topmost element of the stack.If there are no elements in the stack, then it should throw an error or return null.
//max(), which returns the maximum value in the stack currently.If there are no elements in the stack, then it should throw an error or return null.
//Each method should run in constant time.

//Using an auxillary max heap costs all methods to be logn except for max()
//if we keep track of how to get to the next max from the current one. were done.
//ex. push 1. 1 is now max.
//ex. push 3. 3 is now max.
// push 2.

//pop num. If num is less than max. do nothing.
//pop num. If num is max. Pop the value to subtrack from the max to get to the previous max.

template<typename T>
class Stack
{
public:
	using const_iterator = typename std::vector<T>::const_iterator;

	typename std::vector<T>::const_iterator begin() const { return stack.cbegin(); }
	typename std::vector<T>::const_iterator end() const { return stack.cend(); }

	void push( const T& val )
	{
		stack.push_back( val );

		if ( maxstack.size() == 0 || val >= maxstack.back() )
		{
			maxstack.push_back( val );
		}
	}

	T pop()
	{
		assert( stack.size() > 0 );
		T val = stack.back();
		stack.pop_back();

		if ( maxstack.size() > 0 && val == maxstack.back() )
		{
			maxstack.pop_back();
		}
		return val;
	}

	T top()
	{
		return stack.back();
	}

	T max()
	{
		assert( stack.size() > 0 );
		return maxstack.back();
	}

private:
	//holds order of max values as they were inserted
	std::vector<T> maxstack;
	std::vector<T> stack;
};
