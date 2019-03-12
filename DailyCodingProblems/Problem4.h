#pragma once
#include <cassert>

template<typename T>
struct TNode
{
	TNode( const T& data ) :Data( data ) {}

	bool HasNext( const TNode<T>* previous ) const { return ( Both ^ reinterpret_cast<PointerType>(previous) ) != 0; }
	TNode<T>* GetNext( const TNode<T>* previous ) const { return reinterpret_cast<TNode<T>*>(Both ^ reinterpret_cast<PointerType>(previous)); }
	void SetNext( TNode<T>* next ) { Both ^= reinterpret_cast<PointerType>(next); }

	T Data;
private:
	using PointerType = intptr_t; //may need to be change depending on size of a pointer
	PointerType Both = 0; //xor of next and prev pointer
};

template<typename T>
class TXLinkedList
{
public:

	~TXLinkedList()
	{
		if ( Head == nullptr )
		{
			return;
		}
		else
		{
			TNode<T>* prev = 0;
			TNode<T>* curr = Head;
			while ( curr->HasNext( prev ) )
			{
				TNode<T>* temp = curr;
				curr = curr->GetNext( prev );
				prev = temp;
				delete temp;
			}
		}
	}

	void add( const T& data )
	{
		TNode<T>* node = new TNode<T>( data );
		if ( Head == nullptr )
		{
			Head = node;
		}
		else
		{
			TNode<T>* prev = 0;
			TNode<T>* curr = Head;
			while ( curr->HasNext( prev ) )
			{
				TNode<T>* temp = curr;
				curr = curr->GetNext( prev );
				prev = temp;
			}
			curr->SetNext( node );
			node->SetNext( curr );
		}
	}

	T& get( const unsigned int index )
	{
		assert( Head != nullptr );

		unsigned int i = 0;
		TNode<T>* prev = 0;
		TNode<T>* curr = Head;
		while ( curr->HasNext( prev ) && i < index )
		{
			TNode<T>* temp = curr;
			curr = curr->GetNext( prev );
			prev = temp;
			++i;
		}
		assert( i == index );
		return curr->Data;
	}

private:
	TNode<T>* Head = nullptr;
};

