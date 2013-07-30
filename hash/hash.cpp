#include <iostream> 
#include <functional>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
//usinig namespace std;

///template <typename T>
///struct hash;

template < class T >
struct hash
{
	std::size_t operator()( const T &t ) const
	{
		return 55;
	}
};


template <>
struct hash< char *>
{
	std::size_t operator()(const char *t) const 
	{
		return 5;
	}
};

template <>
struct hash< std::string >
{
	std::size_t operator()(const std::string &s ) const
	{
		size_t ret = 0xAAAAaaaa;
		for( int i = 0; i < s.size(); i++ )
		{
			ret ^= s[i];
			ret = ret << 7;
		}
		return ret;
	}

};

template <typename key, typename value, typename Hash = hash<key> >
class hash_map
{
	public:

	hash_map( int size = 128 ) : 
		v( size ),
		ts( size )
	{
	}

	void init()
	{
		//v = vector<value>( ts );
		//v(ts);// = vector<value>( ts );
	}

	void add( key k , value const v1 )
	{
		int index = h(k) % ts;
		if( v[ index ] )
		{
			cout << "Collision?" << endl;
		}
		v[index] = v1;
	}

	value get( key k )
	{
		int index = h(k) % ts;
		return v[index];
	}

	void hash( key k )
	{
		cout << h( k ) << endl;
	}

	Hash h;
	vector<value > v;
	int ts;
};

class A
{
public: 
	void set( int n )
	{
		m = n;
	}
	
	int get( ) 
	{ 
		return m;
	}

	int m;
};

int main( int argc, char **argv)
{
	cout << "Hello World!" << endl;
	hash_map<std::string, int> hm1;
	hash_map<int, int> hm2;
	hm1.hash( "hey" );
	hm1.hash( "hey1" );
	hm1.hash( "hey" );

	cout << "Hey test" << endl;
	cout << hm1.get( "hey" ) << endl;
	hm1.add( "hey", 42 );
	cout << hm1.get( "hey" ) << endl;
	hm1.add( "hey", 43 );
	cout << hm1.get( "hey" ) << endl;
	int a = 9;
	hm1.add( "asdf", a );
	cout << hm1.get( "asdf" ) << endl;
	a = 10;
	cout << hm1.get( "asdf" ) << endl;
	

	vector <A> mv(5);
	A b;
	b.set(3);
	mv[0] = b;
	cout << mv[0].get() << endl;
	mv[0].set( 10 );
	if( mv[0] )
	b.set( 5);
	cout << mv[0].get() << endl;


//	hash_map< std::string, std::string> hms;
//	hms.add( "hey", "hey" );
//	cout << hms.get("hey") << endl;

//	hash_map< std::string, A> hm3;
//	A b;
//	b.set( 3 );
//	hm3.add( "hey", b);
//	cout << hm3.get("hey").get() << endl;
}
