#include <stdio.h>
#include <stdlib.h>

int main()
{
	int current, biggest_subsequence, subsequence_after_biggest, quantidade, secondary_subsequence;
	scanf("%d", &quantidade);
	while ( quantidade != 0 )
	{
		biggest_subsequence=0; subsequence_after_biggest= 0; secondary_subsequence= 0;
		for(int i= 0; i < quantidade; i++ )
		{
			scanf( "%d", &current);
			subsequence_after_biggest+= current;
			secondary_subsequence+= current;
			if ( secondary_subsequence < 0 )
				secondary_subsequence= 0;
			if ( subsequence_after_biggest > 0 )
			{
				biggest_subsequence+= subsequence_after_biggest;
				subsequence_after_biggest= 0;
				if ( secondary_subsequence < biggest_subsequence )
					secondary_subsequence= 0;
			}
			if ( secondary_subsequence > biggest_subsequence )
				biggest_subsequence= secondary_subsequence;
			//printf("%d, %d\n",biggest_subsequence, secondary_subsequence, subsequence_after_biggest );
		}
		if ( biggest_subsequence )
			printf("The maximum winning streak is %d.\n",biggest_subsequence);
		else
			printf("Losing streak.\n");
		scanf("%d", &quantidade);
	} 
}