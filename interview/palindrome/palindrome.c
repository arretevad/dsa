#include <stdio.h>
#include <string.h>


char to_lower( char a )
{
	if( a > 'A' && a < 'Z' )
		return 'a' + ( a - 'A' );
	return a;
}

int is_palindrome( char *s )
{
	
	char *e = s + strlen(s) - 1;

	while( s < e )
	{
		if( to_lower(*s) != to_lower(*e) )
			return 0;
		s++; 
		e--;
	}

	return 1; 
}


int main( void )
{	
	char *the_word;

	the_word = "WOw";
	printf("%s: %s\n", the_word, is_palindrome(the_word) ? "Yes" : "No" );
	the_word = "Dave";
	printf("%s: %s\n", the_word, is_palindrome(the_word) ? "Yes" : "No" );
	the_word = "Radar";
	printf("%s: %s\n", the_word, is_palindrome(the_word) ? "Yes" : "No" );
	the_word = "Madam";
	printf("%s: %s\n", the_word, is_palindrome(the_word) ? "Yes" : "No" );
	the_word = "aAAa";
	printf("%s: %s\n", the_word, is_palindrome(the_word) ? "Yes" : "No" );
	the_word = "aAZaAa";
	printf("%s: %s\n", the_word, is_palindrome(the_word) ? "Yes" : "No" );

	return 0;
}
