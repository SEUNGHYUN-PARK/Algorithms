#include <iostream>
using namespace std;
// 0~9까지 숫자로 제한

unsigned int randmake(unsigned int _nextnum)
{
	_nextnum = (_nextnum * 1103515245) + 12345;
	return (unsigned)(_nextnum / 65536) % 10;
}

void FillArray(int *arr)
{
	unsigned int nextnum = 1;
	int temp[10] = {0,};
	int i = 0;
	while (i < 10)
	{
		int ret = randmake(nextnum);
		if (temp[ret] > 0)
		{
			nextnum++;
			continue;
		}
		else
		{
			arr[i] = ret;
			temp[ret]++;
			i++;
		}

	}
}

int choosepivot(int low, int high)
{
	return low + (high - low) / 2;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int low, int high)
{
	int pivotindex = choosepivot(low, high);
	int pivotvalue = arr[pivotindex];
	int storeindex = low;
	int i = low;
	swap(arr[pivotindex], arr[high]);
	for (i = low; i < high; i++)
	{
		if (arr[i] < pivotvalue)
		{
			swap(arr[i], arr[storeindex++]);
		}
	}
	swap(arr[storeindex], arr[high]);
	return storeindex;
}

void quicksort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr,low,high);
		quicksort(arr, 0, pivot-1);
		quicksort(arr, pivot + 1,high);
	}

}

void print(int *arr)
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void merge(int *arr, int low, int high)
{
	int *temp = new int[10];
	int mid = (low + high) / 2;
	int k = 0;
	int i = low, j = mid + 1;
	while (i <= mid&&j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while (j <= high)
	{
		temp[k++] = arr[j++];
	}
	k = 0;
	for (int i = low; i <= high; i++)
	{
		arr[i] = temp[k++];
	}
	delete temp;
}

void mergesort(int *arr, int low, int high)
{
	if (low == high)
	{
		return;
	}
	int mid = (low + high) / 2;
	mergesort(arr, 0, mid);
	mergesort(arr, mid + 1, high);
	merge(arr, low, high);

}

int main(void)
{
	int q[10] = { 0, };
	int m[10] = { 0, };
	FillArray(q);
	print(q);
	quicksort(q,0,9);
	print(q);

	FillArray(m);
	print(m);
	mergesort(m, 0, 9);
	print(m);
}
