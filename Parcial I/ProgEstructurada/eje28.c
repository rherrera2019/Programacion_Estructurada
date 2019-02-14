#include <stdio.h>
#include <ctype.h>

int main () 
{
	/* declaracion de variable */
	int var1 = 'k';
	/* proceso */
	if( isprint(var1) ) {
		printf("var1 = |%c| can be printed\n", var1 );
	} else {
		printf("var1 = |%c| can't be printed\n", var1 );
	}
	if( isalpha(var1) ) {
		printf("var1 = |%c| is an alphabet\n", var1 );
	} else {
		printf("var1 = |%c| is not an alphabet\n", var1 );
	}
	if( ispunct(var1) ) {
		printf("var1 = |%c| is a punctuation character\n", var1 );
	} else {
		printf("var1 = |%c| is not a punctuation character\n", var1 );
	}
	if( isdigit(var1) ) {
		printf("var1 = |%c| is a digit\n", var1 );
	} else {
		printf("var1 = |%c| is not a digit\n", var1 );
	}
}
