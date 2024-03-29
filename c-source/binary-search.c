#include <stdio.h>
int BinarySearch(int *array, int n, int key)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (array[mid] < key)
		{
			low = mid + 1;
		}
		else if (array[mid] == key)
		{
			return mid;
		}
		else if (array[mid] > key)
		{
			high = mid - 1;
		}
	}
	return -1;
}
int main()
{
	int n = 5;
	int array[n];
	int i, key, index;
	printf("\nEnter the 5 elements");
	// scanf("%d",&n);
	printf("\nEnter the elements");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	for (i = 1; i < n; i++)
	{
		if (array[i] < array[i - 1])
		{
			printf("Given input is not sorted\n");
			return 0;
		}
	}
	printf("Enter the key to be searched");
	scanf("%d", &key);
	index = BinarySearch(array, n, key);
	if (index == -1)
	{
		printf("Element not found\n");
	}
	else
	{
		printf("Element is at index %d\n", index);
	}
	return 0;
}
