//A simple binary search tree
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//Depth-first printing. Values should be printed in ascending order
void print_tree( tree_node *n )
{
	if( n->left )
		print_tree( n->left );
	printf( "%d\n", n->val );
	if( n->right )
		print_tree( n->right );
}

void insert( tree_node **root, int value )
{
	//Malloc the node initialize it
	tree_node *n = malloc( sizeof( tree_node ) );
	n->val = value;
	n->left = NULL;
	n->right = NULL;

	tree_node *c;

	// Generally I don't like using attributions in conditional statements like this
	//  ...but I'm doing it anyway
	while( c = *root  )
	{
		if( value <= c->val )
		{
			root = &(c->left);
		}
		else
		{
			root = &(c->right);
		}
	}

	*root = n;
}

int main( void )
{
	int i;
	tree_node *root = NULL;

	for( i = 0; i < 10; i++ )
	{
		int r = rand()%100;
		insert( &root, r );
	}

	print_tree( root );

	return 0;
}

