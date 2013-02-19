#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double my_sqrt2( int n, int prec )
{
	double start = 0;
	double end   = n;
	int i = 0;
	prec = 3;

	if( n == 0 || n == 1 ) return n;

	double p = 1;
	while( prec-- )
		p /= 10;


	while( (end - start) > p )
	{
		double mid = (start+end)/2;
		double sqr = mid*mid;
		if( sqr == n ) return mid;
		else if( sqr < n ) start = mid;
		else end = mid;
//		printf("%d %.15f %.15f %.15f\n", n, sqr, mid, end-start );
//		sleep( 1 );
	}

	return (start+end)/2;
}

double my_sqrt( int n, int prec )
{

	double i = 0;
	double inc = 1;
	int j = 1;
	for( ; j <= prec; j++ )
	{
		for( ; i*i < n; i += inc )
		{
//			printf("%f\n", i);
		}
		if( i*i == n )
		{
			printf("exact found!\n");
			return i;			
		}
		i -= inc;
		inc /= 10;
	}
	return i;
}

int main( void )
{
	int i = 0;
	printf("%f %f\n", sqrt( 4 ), my_sqrt( 4, 2 ) );
	printf("%.10f %.10f\n", sqrt( 5 ), my_sqrt( 5, 10 ) );
	for( ; i < 10; i++ )
	{
		int n = rand()%100;
		double t = sqrt( n );
		double m = my_sqrt( n, 15 );
		double m2 = my_sqrt2( n, 15 );
		double diff = t -m ;
		printf("n=%d %.15f %.15f %.15f \n", n, t, m, m2  );
	}

	return 0;
}

