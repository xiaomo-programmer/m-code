#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


//��ӡ
void printfArray(int* a, int n);


//����
void swap(int* p, int* q);


// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);


//��������
void quicksort(int* a, int left, int right);



void QuickSortNonR(int* a, int left, int right);


void MergeSort(int* a, int n);