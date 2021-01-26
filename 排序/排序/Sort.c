

#include"Sort.h"


void swap(int* p, int* q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

//≤Â»Î≈≈–Ú
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}



// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}



////—°‘Ò
//void SelectSort(int* a, int n)
//{
//	int k;
//	for (int i = 0; i <= n - 2; i++)
//	{
//		 k = i;
//		for (int j = i+1; j < n ; j++)
//		{
//
//			if (a[j] < a[k])
//
//			{
//				k = j;
//			}
//			
//
//		}
//			if (k != i)
//
//			{
//				int temp = a[i];
//				a[i] = a[k];
//				a[k] = temp;
//			}
//		
//	}
//}



//—°‘Ò2
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	
	while (begin < end)
	{
		int maxi, mini;
		maxi = mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i]>a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}






// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child],&a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}
// √∞≈›≈≈–Ú
void BubbleSort(int* a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				swap(&a[i], &a[j]);

			}
		}
	}
}




//»°÷–
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin]>a[end])
			return begin;
		else
			return end;
	}
	else //a[begin] > a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}













//øÏÀŸ≈≈–Ú  ◊Û”“÷∏’Î∑®
int QuickSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[midIndex], &a[end]);

	int keyindex = end;
	while (begin < end)
	{
		// begin’“¥Û
		while (begin < end && a[begin] <= a[keyindex])
		{
			++begin;
		}

		// end’“–°
		while (begin < end && a[end] >= a[keyindex])
		{
			--end;
		}

		swap(&a[begin], &a[end]);
	}

	swap(&a[begin], &a[keyindex]);

	return begin;
}

//Õ⁄ø”∑®
int QuickSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[midIndex], &a[end]);
	int key = a[end];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
		{
			begin++;
		}
		a[end] = a[begin];
		while (begin < end&& a[end] >= key)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}

//«∞∫Û÷∏’Î∑®
int QuickSort3(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	swap(&a[midIndex], &a[end]);

	int keyindex = end;
	int prev = begin - 1;
	int cur = begin;
	while (cur < end)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
		
			swap(&a[prev], &a[cur]);
			cur++;
		
		
		
	}
	swap(&a[++prev], &a[keyindex]);
	return prev;
}


//øÏ≈≈
void quicksort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;


	int div = QuickSort3(a, left, right);

	
	
	quicksort(a, left, div - 1);
	quicksort(a, div+1, right);

	
}


