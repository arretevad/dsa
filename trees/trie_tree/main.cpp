#include "trie.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_if_word( trie_tree &t, string word )
{
	cout << word << " ";
	if( t.is_word( word ) )
		cout << "is a word" << endl;
	else
		cout << "is not a word" << endl;
}

void print_prefix( trie_tree &t, string word )
{
	cout << word << " has " << t.get_num_prefixes( word ) << " prefixe(s)" << endl;
}

void print_words_with_prefix( trie_tree &t, string prefix )
{
	vector<trie_node *> v;
	t.get_words_with_prefix(v,prefix);
	cout << "Word with prefix " << prefix << ":";
	if( v.size() == 0 )
	{
		cout << "None" << endl;
		return;
	}

	cout << endl;
	for( unsigned i = 0; i < v.size(); i++ )
	{
		cout << "\t" << v[i]->word << endl;
	}
}


int main( int argc, char **argv)
{
	cout << "Hello Trie" << endl;

	trie_tree t;
	t.add_word( "hello" );
	t.add_word( "help" );
	t.add_word( "a" );

	print_if_word( t, "hello" );
	print_if_word( t, "hell" );
	print_if_word( t, "help" );
	print_if_word( t, "a" );

	print_prefix( t, "hel" );
	print_prefix( t, "hell" );
	print_prefix( t, "bat" );

	print_words_with_prefix( t, "hel" );
	print_words_with_prefix( t, "a" );

	return 0;
}
