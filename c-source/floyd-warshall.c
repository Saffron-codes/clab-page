#include <stdio.h>
void floyd(int a[4][4], int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] > a[i][k] + a[k][j])
				{
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	printf("All Pairs Shortest Path is :\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int cost[4][4] = {{0, 2, 10, 999}, {999, 0, 3, 6}, {8, 999, 0, 4}, {7, 999, 999, 0}};
	int n = 4;

	floyd(cost, n);
}
