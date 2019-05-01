#include "Problem34.h"
#include "Tree.h"

//Suppose an arithmetic expression is given as a binary tree.Each leaf is an integer and each internal node is one of * + - /
//
//Given the root to such a tree, write a function to evaluate it.
//
//For example, given the following tree :
//    *
//   / \
//  +     +
//  /\    /\
// 3  2  4  5
//You should return 45, as it is( 3 + 2 ) * ( 4 + 5 ).

struct NumOrOperand
{
	union {
		int num;
		char operand;
	};
};

int ApplyOp( int lhs, int rhs, NumOrOperand op )
{
	switch ( op.operand )
	{
	default:
	case( '*' ): return lhs * rhs; break;
	case( '+' ): return lhs + rhs; break;
	case( '-' ): return lhs - rhs; break;
	case( '/' ): return (int)( lhs / rhs ); break;
	}
}

int TreeResult( const Tree<NumOrOperand>& root )
{
	if ( root.Left == nullptr && root.Right == nullptr )
	{
		return root.Data.num;
	}
	else
	{
		return ApplyOp( TreeResult( *root.Left ), TreeResult( *root.Right ), root.Data );
	}
}

void Problem34::RunTest()
{
	Tree<NumOrOperand> tree( { '*' } );
	Tree<NumOrOperand> sub1( { '+' } );
	Tree<NumOrOperand> sub2( { '+' } );
	Tree<NumOrOperand> leaf1( { 3 } );
	Tree<NumOrOperand> leaf2( { 2 } );
	Tree<NumOrOperand> leaf3( { 4 } );
	Tree<NumOrOperand> leaf4( { 5 } );

	tree.Left = &sub1;
	tree.Right = &sub2;
	sub1.Left = &leaf1;
	sub1.Right = &leaf2;
	sub2.Left = &leaf3;
	sub2.Right = &leaf4;

	std::printf( "\nProblem34:\n" );
	std::printf( "Result: %d\n", TreeResult( tree ) );
	
	tree.Left = nullptr;
	tree.Right = nullptr;
	sub1.Left = nullptr;
	sub1.Right = nullptr;
	sub2.Left = nullptr;
	sub2.Right = nullptr;
}
