#include "Problem29.h"
#include "Tree.h"
#include <algorithm>

//Given pre - order and in - order traversals of a binary tree, write a function to reconstruct the tree.
//
//For example, given the following preorder traversal :
//
//[a, b, d, e, c, f, g]
//
//And the following inorder traversal :
//
//[d, b, e, a, f, c, g]
//
//You should return the following tree :
//
//    a
//   / \
//  b   c
// / \ / \
//d  e f  g

template<typename T>
Tree<T>* Reconstruct( const std::vector<T>& preorder, const std::vector<T>& inorder)
{
	if ( preorder.size() == 0 )
	{
		return nullptr;
	}
	else if ( preorder.size() == 1 )
	{
		return new Tree<T>( preorder[0] );
	}
	else
	{
		typename std::vector<T>::const_iterator it = std::find( inorder.begin(), inorder.end(), preorder[0] ); //never will be inorder.end()
		Tree<T>* tree = new Tree<T>( preorder[0] );
		std::vector<T> inleft( inorder.begin(), it );
		std::vector<T> inright( it+1, inorder.end() );
		std::vector<T> preleft( preorder.begin() + 1, preorder.begin() + 1 + inleft.size() );
		std::vector<T> preright( preorder.begin() + 1 + inleft.size(), preorder.end() );
		tree->Left = Reconstruct( preleft, inleft );
		tree->Right = Reconstruct( preright, inright );
		return tree;
	}
}

void Problem29::RunTest()
{
	std::vector<char> preorder{ 'a', 'b', 'd', 'e', 'c', 'f', 'g' };
	std::vector<char> inorder{ 'd','b','e','a','f','c','g' };
	Tree<char>* tree = Reconstruct( preorder, inorder );
	std::printf( "\nProblem29:\n" );
	Util::PrintContainer( preorder );
	Util::PrintContainer( inorder );
	delete tree;
}
