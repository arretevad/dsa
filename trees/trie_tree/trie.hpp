#include <string>
#include <vector>

#define MAX_CHILDREN 26

using namespace std;

class trie_node 
{
public:

	trie_node *children[MAX_CHILDREN];
	bool is_word;
	string word;
	unsigned num_prefixes;
};

class trie_tree
{
public:

	trie_tree()
	{
		root = new trie_node();
	}

	~trie_tree()
	{
		//Free memory
	}

	void add_word( string word )
	{	
		trie_node *current = root;
		if( current == NULL || word.length() == 0 )
			return;

		for( unsigned i = 0; i < word.length(); i++ )
		{
			current->num_prefixes++;

			int index = word[i] - 'a';

			if( current->children[index] == NULL )
			{
				current->children[index] = new trie_node();
			}
			current = current->children[index];
		}
		current->is_word = true;
		current->word = word;
	}

	bool is_word( string word )
	{
		trie_node *n = get_node_at( word );
		if( n == NULL )
			return false;
		else
			return n->is_word;
	}

	unsigned get_num_prefixes( string prefix )
	{
		trie_node *n = get_node_at( prefix );
		if( n == NULL )
			return 0;
		else
			return n->num_prefixes;

	}

	bool get_words_with_prefix( vector<trie_node *> &v, string prefix )
	{
		trie_node *n = get_node_at( prefix );
		if( n == NULL || (n->num_prefixes == 0 && !n->is_word))
			return false;

		// Do a DFS
		vector<trie_node *> s;
		trie_node *current;
		s.push_back( n );
		while( s.size() != 0 )
		{
			current = s.back();
			s.pop_back();
			if( current->is_word )
				v.push_back( current );

			for( int j = 0; j < MAX_CHILDREN; j++ )
			{
				if( current->children[j] != NULL )
					s.push_back( current->children[j] );
			}
		}
		return true;
	}
		
private:
	
	trie_node * get_node_at (string word )
	{
		trie_node *current = root;
		if( current == NULL || word.length() == 0 )
			return NULL;

		for( unsigned i = 0; i < word.length(); i++ )
		{
			int index = word[i] - 'a';
			if( current->children[index] == NULL )
				return NULL;
			current = current->children[index];
		}

		return current;
	}

	trie_node *root;
};



