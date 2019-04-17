#include "Problem24.h"

void Problem24::RunTest()
{
	std::printf( "\nProblem24:\n" );
	Stack<int> stack;
	stack.push( 5 );
	stack.push( 3 );
	stack.push( 6 );
	stack.push( 8 );
	stack.push( 7 );
	Util::PrintContainer( stack );
	std::printf( "Max: %d\n", stack.max() );
	stack.pop();
	Util::PrintContainer( stack );
	std::printf( "Max: %d\n", stack.max() );
	stack.pop();
	Util::PrintContainer( stack );
	std::printf( "Max: %d\n", stack.max() );
	stack.pop();
	Util::PrintContainer( stack );
	std::printf( "Max: %d\n", stack.max() );
	stack.pop();
	Util::PrintContainer( stack );
	std::printf( "Max: %d\n", stack.max() );
	stack.pop();
}
