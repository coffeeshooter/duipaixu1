#include <stdio.h>
#include <stdlib.h>

void HeapAdjust(int* arr, int start, int end)
{
	int tmp = arr[start];
	for (int i = 2 * start + 1; i <= end; i = i * 2 + 1)
	{
		if (i < end && arr[i] < arr[i + 1])
		{
			i++;
		}
		if (arr[i] > tmp)
		{
			arr[start] = arr[i];
			start = i;
		}
		else
		{
			break;
		}
	}
	arr[start] = tmp;
}
void HeapSort(int* arr, int len)
{
	
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		HeapAdjust(arr, i, len - 1);
	}

	int tmp;
	for (int i = 0; i < len - 1; i++)
	{
		tmp = arr[0];
		arr[0] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
		HeapAdjust(arr, 0, len - 1 - i - 1);
	}
}
int main()
{
	int arr[] = { 1,7,6,3,5,3,1,0,25,10 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	printf("ÅÅĞòºóÎª:");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}