#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using uint = unsigned int;

#define DECLARE_PROBLEM(num) \
struct Problem##num \
{ \
	static void RunTest(); \
};

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
//
//struct TestFunc
//{
//	std::function<void()> Func;
//	size_t ProblemNumber;
//};
//
//class TestBench
//{
//public:
//	TestBench( size_t Problems )
//	{
//
//	}
//	void RunTests()
//	{
//		std::sort( TestFunctions.begin(), TestFunctions.end(), []( const TestFunc& lhs, const TestFunc& rhs ) { return lhs.ProblemNumber < rhs.ProblemNumber; } );
//		for( const TestFunc& f : TestFunctions )
//		{
//			f.Func();
//		}
//	}
//	static std::vector<TestFunc> TestFunctions;
//};
//
//static TestBench GTestBench;

