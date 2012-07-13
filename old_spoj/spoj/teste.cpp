#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n= 1;
	for (int i= n; i--; )
		for (int j= n; j--;)
			for (int k= n; k--;  printf("%d %d %d\n", i, j, k));
}