#include "bst.hpp"
#include <iostream> 

using namespace std;

template <typename T>
void print_if_found( binary_search_tree<T> &bst, const T &x )
{
	binary_node<T> *n = bst.find( x );
	if( n != NULL )
		cout << "Found: " << x << endl;
	else
		cout << "Not found: " << x << endl;

}

int main( int argc, char **argv )
{
	cout << "Hello BST" << endl;
	binary_search_tree<int> bst;

	bst.insert( 5 );
	bst.insert( 5 );
	cout << "Number of items: " << bst.count() << endl;

	for( int i = 0; i < 20; i++ )
	{
		int r = rand()%1000;
		cout << "Adding random: " << r << endl;
		bst.insert( r );
	}

	cout << "Number of items: " << bst.count() << endl;
	cout << "Max item is: " << bst.find_max()->element << endl;
	cout << "Min item is: " << bst.find_min()->element << endl;

	print_if_found<int>( bst, 5 );
	bst.remove( 5 );
	print_if_found<int>( bst, 5 );

	return 0;
}

