//A simple binary search tree

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


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
	tree_node *n = malloc( sizeof( tree_node ) );
	n->val = value;
	n->left = NULL;
	n->right = NULL;

	tree_node *c = *root;
#if 1

	//while( *root != NULL )
	while( c = *root  )
	{
		if( value <= c->val )
		{
			printf("Left\n");
			root = &(c->left);
		}
		else
		{
			printf("Right\n");
			root = &(c->right);
		}
	}
	printf("k\n");
	*root = n;

#else
	while( c != NULL  )
	{
		if( value <= c->val )
		{
			printf("Left\n");
			root = &(c->left);
		}
		else
		{
			printf("Right\n");
			root = &(c->right);
		}
		c = *root;
	}

	*root = n;
#endif
}

int main( void )
{
	tree_node *root = NULL;
	int i;
//	insert( &root, 5 );
//	insert( &root, 2 );
	for( i = 0; i < 10; i++ )
	{
		int r = rand()%100;
		printf("%d\n", r);
		insert( &root, r );
	}
	print_tree( root );

	printf("DONE!\n");
	return 0;
}

