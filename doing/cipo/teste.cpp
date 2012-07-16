#include <stdio.h>
#include <stdlib.h>

int main()
{
	int k=1;
	for (int i= 0; i<30; i++)
		printf( "%d,%d\n", k*=2,i );
	printf( "%d\n", 2*k-1);
}