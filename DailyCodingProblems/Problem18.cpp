#include "Problem18.h"
#include <iostream>
#include <stack>
#include "Tree.h"

template<typename T>
struct Node
{
	Node(const T& Data)
		:data(Data)
	{}

	~Node()
	{
		if ( left != nullptr )
		{
			delete left;
		}
		if ( right != nullptr )
		{
			delete right;
		}
	}

	void Insert( const T& Data )
	{
		if ( Data > data)
		{
			if ( right != nullptr )
			{
				right->Insert( Data );
			}
			else
			{
				right = new Node( Data );
			}
		}
		else
		{
			if ( left != nullptr )
			{
				left->Insert( Data );
			}
			else
			{
				left = new Node( Data );
			}
		}
	}

	T data;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};

//Given the root to a binary search tree, find the second largest node in the tree.
template<typename T>
void SecondLargestUtil( Node<T>* root, int& visited )
{
	if ( root == nullptr || visited >= 2 )
	{
		return;
	}

	SecondLargestUtil( root->right, visited );
	visited++;
	
	if ( visited == 2 )
	{
		std::cout << root->data << std::endl;
	}
	SecondLargestUtil( root->left, visited );
}

template<typename T>
Node<T> SecondLargest( const Node<T>* root )
{
	int visited = 0;
	
	//want to visit in order: right root left
	std::stack<const Node<T>*> unvisited;
	const Node<T>* curr = root;
	while ( !unvisited.empty() || curr != nullptr ) // same as: !( unvisited.empty() && curr == nullptr )
	{
		// right root left
		if ( curr != nullptr )
		{
			unvisited.push( curr );
			curr = curr->right;
		}
		else
		{
			curr = unvisited.top();
			unvisited.pop();

			//visiting
			visited++;
			if ( visited == 2 )
			{
				return *curr;
			}

			//visit left
			curr = curr->left;
		}
	}
	return *root;
}

//want to visited the right node, then the left most, last the root.


void Problem18::RunTest()
{
	Node<int> tree( 5 );
	tree.Insert( 7 );
	tree.Insert( 4 );
	tree.Insert( 9 );
	tree.Insert( 6 );
	tree.Insert( 8 );
	tree.Insert( 12 );
	tree.Insert( 10 );
	std::printf( "\nProblem18:\n" );
	//SecondLargest( &tree );
	std::printf( "Second largest: %d\n", SecondLargest( &tree ).data );
}