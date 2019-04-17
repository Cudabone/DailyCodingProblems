#include "Problem26.h"
#include <array>

#include <iostream>
//You have an N by N board.Write a function that, given N, 
//returns the number of possible arrangements of the board
//where N queens can be placed on the board without threatening each other,
//i.e.no two queens share the same row, column, or diagonal.

//standard chess board is 8x8
using Board = std::array<std::array<bool, 8>, 8>;

bool CanAttack( const Board& b, size_t row, size_t col )
{
	//row collision
	for ( size_t j = 0; j < b[row].size(); ++j )
	{
		if ( j != col && b[row][j] )
		{
			return true;
		}
	}
	//col collision
	for ( size_t i = 0; i < b.size(); ++i )
	{
		if ( i != row && b[i][col] )
		{
			return true;
		}
	}

	//diagonal
	size_t i = row;
	size_t j = col;
	//top left
	while ( i > 0 && j > 0 )
	{
		--i; --j;
	}
	//major diagonal
	while ( i < b.size() && j < b[i].size() )
	{
		if ( i != row && j != col && b[i][j] )
		{
			return true;
		}
		++i; ++j;
	}
	
	//bottom-left diagonal
	i = row; j = col;
	while ( i < b.size() - 1 && j > 0 )
	{
		++i; --j;
		if ( b[i][j] )
		{
			return true;
		}
	}

	//top-right diagonal
	i = row; j = col;
	while ( i > 0 && j < b.size() - 1 )
	{
		--i; ++j;
		if ( b[i][j] )
		{
			return true;
		}
	}

	return false;
}

bool NQueensR( Board& b, size_t N, size_t placed, size_t row, size_t& validboards )
{
	if ( placed == N )
	{
		++validboards;
		//for ( std::array<bool, 8> arr : b )
		//{
		//	Util::PrintContainer( arr );
		//}
		//std::printf( "\n" );
		return true;
	}
	if ( row >= b.size() )
	{
		return false;
	}
	for ( size_t j = 0; j < b[row].size(); ++j )
	{
		if ( !CanAttack( b, row, j ) )
		{
			b[row][j] = true;
			NQueensR( b, N, placed + 1, row + 1, validboards );
			b[row][j] = false;
		}
	}
	return false;
}

//can make more efficient by skiping to the next row when you place a queen
size_t NQueens(size_t N)
{
	Board b;
	for ( size_t i = 0; i < b.size(); ++i )
	{
		for ( size_t j = 0; j < b[i].size(); ++j )
		{
			b[i][j] = false;
		}
	}

	size_t validboards = 0;
	NQueensR( b, N, 0, 0, validboards );
	return validboards;
}

void Problem26::RunTest()
{
	Board b;
	for ( size_t i = 0; i < b.size(); ++i )
	{
		for ( size_t j = 0; j < b[i].size(); ++j )
		{
			b[i][j] = false;
		}
	}
	std::printf( "\nProblem26\n" );
	size_t N = 8;
	std::printf( "Number of %zu Queen arrangements: %zu\n", N, NQueens( N ) );
}
