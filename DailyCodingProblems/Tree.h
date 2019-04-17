#pragma once

#include <vector>

template<typename T>
class Tree
{
public:
	using value_type = T;

	Tree( const T& data ) : Data( data ) {}
	~Tree()
	{
		if ( Left != nullptr )
		{
			delete Left;
		}
		if ( Right != nullptr )
		{
			delete Right;
		}
	}

	void Add( const T& data )
	{
		Tree<T>** tree = (data < Data) ? &Left : &Right;
		while ( *tree != nullptr )
		{
			tree = (data < (*tree)->Data) ? &(*tree)->Left : &(*tree)->Right;
		}
		*tree = new Tree<T>( data );
	}

	bool FindDFSRecursive( const T& val ) const
	{
		if ( Data == val )
		{
			return true;
		}
		else
		{
			if ( Left != nullptr && Left.Find( val ) )
			{
				return true;
			}
			else if ( Right != nullptr && Right.Find( val ) )
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	bool FindBFS( const T& val ) const
	{
		if ( Data == val )
		{
			return true;
		}
		else
		{
			std::vector<Tree<T>*> trees;
			EnqueueChildren( trees );

			for ( int i = 0; i < trees.size(); ++i )
			{
				if ( trees[i].Data == val )
				{
					return true;
				}
				else
				{
					EnqueueChildren( trees );
				}
			}
			return false;
		}
	}

private:
	inline void EnqueueChildren( std::vector<Tree<T>*> trees ) const
	{
		if ( Left != nullptr )
		{
			trees.push_back( Left );
		}
		if ( Right != nullptr )
		{
			trees.push_back( Right );
		}
	}

public:
	T Data;
	Tree<T>* Left = nullptr;
	Tree<T>* Right = nullptr;
};
