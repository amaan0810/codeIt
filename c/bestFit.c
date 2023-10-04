
#include<stdio.h>
#include<conio.h>

// Method to allocate memory to blocks as per Best fit algorithm
void bestFit(int blockSize[], int m, int processSize[], int n)
{
	// Stores block id of the block allocated to a process
	int allocation[n];

	// Initially no block is assigned to any process
	for (int i = 0; i < n; i++)
		allocation[i] = -1;

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (int i = 0; i < n; i++)
	{
		// Find the best fit block for current process
		int bestIdx = -1;
		for (int j = 0; j < m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (bestIdx == -1)
					bestIdx = j;
				else if (blockSize[bestIdx] > blockSize[j])
					bestIdx = j;
			}
		}

		// If we could find a block for current process
		if (bestIdx != -1)
		{
			// allocate block j to p[i] process
			allocation[i] = bestIdx;

			// Reduce available memory in this block.
			blockSize[bestIdx] -= processSize[i];
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		// printf( " " << i+1 << "\t\t" << processSize[i] << "\t\t");
		printf( " %d\t\t%d\t\t",i+1,processSize[i]);
		if (allocation[i] != -1)
			printf("%d",allocation[i] + 1);
		else
			printf("Not Allocated") ;
    printf("\n");
	}
}

int main()
{
    int m,n;

    printf("\nEnter number of Process : ");
    scanf("%d",&m);
    printf("\nEnter memory sizes for processes :");
    int processSize[m];
    for(int i=0;i<m;i++){
        scanf("%d",&processSize[i]);
    }
    printf("\nEnter number of Blocks : ");
    scanf("%d",&n);
    printf("\nEnter memory sizes for Blocks :");
    int blockSize[n];
    for(int i=0;i<n;i++){
        scanf("%d",&blockSize[i]);
    }

	bestFit(blockSize, n, processSize, m);
}
