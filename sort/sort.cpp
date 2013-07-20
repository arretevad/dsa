
#include <iostream> 
#include <vector>
#include <cstdlib>

using namespace std;

template <class Comparable>
void print_list( vector<Comparable> &a )
{
	std::cout << "List: ";
	for( int i = 0; i < a.size(); i++ )
	{
		std::cout << a[i];
		if( i != a.size() )
			cout << ", ";
	}
	std::cout << std::endl;
}

template <class Comparable>
void insertion_sort( vector<Comparable> &a )
{
	int j; 
	for( int p = 1; p < a.size(); p++ )
	{
		Comparable tmp = a[p];
		for( j = p; j > 0 && tmp < a[j -1]; j-- )
		{
			a[j] = a[j-1];
		}
		a[j]=tmp;
	}
}

template <class Comparable>
void merge( vector<Comparable> &a, vector<Comparable> &b, int start, int end, int c )
{
	int k;
	//cout << "Merge! (" << start << "," << end << "," << c << ")" << endl;

	int x = start;
	int y = c+1;
	for( int i = start; i <= end; i++ )
	{
		if( x <= c && y <= end )
		{
			if( a[x] <= a[y] )
				b[i] = a[x++];
			else
				b[i] = a[y++];
		}
		else if( x <= c )
		{
			b[i] = a[x++];
		}
		else if( y <=end )
		{
			b[i] = a[y++];
		}
	}

	// Write the final sorted array to our original one
	for (k = start; k <= end; k++) {
		a[k] = b[k];
	}
}

template <class Comparable>
void merge_sort( vector<Comparable> &a, vector<Comparable> &b, int left, int right )
{
	//cout << "(" << left << "," << right << ")";
	if( left !=right )
	{
		//cout << "(" << left << "," << right << ")";
		int center = (left+right)/2;
		merge_sort( a, b, left, center );
		merge_sort( a, b, center+1, right );
		merge( a, b, left, right, center );
		//print_list( b );
	}
}

template <typename T> 
void swap( vector<T> &a, int i, int j )
{
	T t = a[i];
	a[i] = a[j];
	a[j] = t;
}

template <class T>
void quick_sort( vector<T> &a, int left, int right )
{
	if( left < right )
	{
		int n = right - left + 1;
		int pivot = left + (std::rand()%n);	

		T pv = a[pivot];
		swap( a, pivot, right );
		int j = left;
		for( int i = left; i < right; i ++ )
		{
			if( a[i] < pv )
				swap( a, i, j++ );
		}
		swap( a, j, right );
		pivot = j;

		quick_sort( a, left, j - 1 );
		quick_sort( a, j+1, right );
	}
}

int rando()
{
	return std::rand()%100; 
}

int main( int argc, char **argv )
{
	std::cout << "Hello World!" << std::endl;

	vector<int> v(20);
	vector<int> a(20);
	vector<int> b(20);
	std::generate( v.begin(), v.end(), rando );
	a = v;

	cout << endl << "Insertion Sort" << endl;
	a = v;
	print_list <int> ( v ) ;
	insertion_sort <int> (a);
	print_list <int> (a);

	cout << endl << "Merge Sort" << endl;
	a = v;
	print_list(a);
	merge_sort<int>( a, b, 0, a.size() - 1 );
	print_list<int>(b);

	cout << endl << "Quick sort" << endl;
	a = v; 
	print_list( a );
	quick_sort<int>( a, 0, a.size() - 1 );
	print_list( a );

	cout << endl;
	cout << "V" << endl;
	print_list( v ) ;

	return 0;
}
