#include <string>
#include <iostream>

using namespace std;

template <typename T> 
class binary_node 
{
public:
	binary_node( const T &e ) : element( e )
	{
	}

	binary_node( ) : left( NULL), 
		right( NULL )
	{
	}

	T element;
	binary_node *left;
	binary_node *right;
};

template <typename T>
class binary_search_tree
{
public:
	
	binary_search_tree() : 
		root( NULL ), 
		m_count( 0 )
	{
		//Nothing	
	}

	binary_node<T> *find( const T &x )
	{
		binary_node<T> *current = root;
		while( current != NULL )
		{
			if( x < current->element )
				current = current->left; 
			else if( x > current->element )
				current = current->right;
			else 
				break;
		}
		return current;

	}

	void insert( const T &x )
	{
		insert( x, root );
	}

	binary_node<T> *find_max(  )
	{
		return find_max( root );
	}

	binary_node<T> *find_min(  )
	{
		return find_min( root );
	}

	bool remove( const T &x )
	{
		return remove( x, root ) ;
	}

	unsigned count()
	{
		return m_count;
	}

private:
	binary_node<T> *find_max( binary_node<T> * &n )
	{
		if( n == NULL || n->right == NULL )
			return n;
		return find_max( n->right );
	}
	
	binary_node<T> *find_min( binary_node<T> * &n  )
	{
		if( n == NULL || n->left == NULL )
			return n;
		return find_max( n->left );
	}

	bool remove( const T &x, binary_node<T> * &n )
	{
		if( n == NULL )
		{
			return true;
		}
		else if( x < n->element )
			remove( x, n->left );
		else if( x > n->element )
			remove( x, n->right );
		else if( n->left != NULL && n->right != NULL )
		{
			n->element = find_min( n->right )->element;
			remove( x, n->right );
		}
		else
		{
			binary_node<T> *temp = n;
			if( n->left != NULL )
				n = n->left;
			else
				n = n->right;
			delete temp;
		}
		return true;
	}


	void insert( const T &x, binary_node<T> * &n )
	{
		if( n == NULL )
		{
			m_count++;
			n = new binary_node<T>(x);
		}
		else if( x < n->element )
			insert( x, n->left );
		else if( x > n->element )
			insert( x, n->right );
		else
			return;
	}

	binary_node<T> *root;
	unsigned m_count;
	
};

