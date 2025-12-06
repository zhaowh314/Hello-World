#include<iostream>
using namespace std;

void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}

//冒泡排序
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);

			}
		}
	} 
	return;
}

//快速排序
//双向交换版
#include <stdio.h>

// 添加swap函数声明
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int* arr, int n) {
    if (n <= 1) {
        return;
    }

    int left = 0;
    int right = n - 2;  // 修正：应该是 n-1，而不是 n-2
    int pivot = arr[n - 1];  // 选择最后一个元素作为基准

    // 分区操作
    do
    {
        for(;right>=left;left++) {
            if (arr[left] > pivot) break;
		}
        for (; right >= left; right--) {
            if (arr[right] < pivot) break;
        }
        if (right >= left)
        {
            swap(&arr[left], &arr[right]);
        }

    } while (right >= left);
    // 将基准元素放到正确位置
    swap(&arr[left], &arr[n - 1]);

    // 递归排序左右两部分
    quickSort(arr, left);  // 左半部分
    quickSort(&arr[left + 1], n - left - 1);  // 右半部分
}
//另一种实现形式
void sort(int array[], int low, int high) {
    if (low >= high) return;//首元素为基准元素

    int z = low, y = high, k = array[z];
    do {
        /// scan from right to left
        while ((z < y) && (array[y] > k)) y--;
        if (z < y) array[z++] = array[y];

        /// scan from left to right
        while ((z < y) && (array[z] <= k)) z++;
        if (z < y) array[y--] = array[z];
    } while (z != y);
    array[z] = k;

    sort(array, low, z - 1);
    sort(array, z + 1, high);
}

//选择排序
void select_sort(int A[], int n) {
    // 1. 检查递归是否中止
    if (n == 1) return;

    // 2. 查找最小元素
    int smallest = 0;
    for (int i = 1; i < n; i++)
        if (A[i] < A[smallest]) smallest = i;

    // 3. 将最小元素与A[0]交换（如果需要的话）
    if (smallest) {
        int tmp = A[0];
        A[0] = A[smallest];
        A[smallest] = tmp;
    }

    // 4. 对剩余数组继续使用选择排序
    select_sort(A + 1, n - 1);
}

//归并排序
void merge_sort(int A[], int start, int end) {
    /// 1. 递归中止条件
    if (start == end - 1) return;

    /// 2. 对两个子数组分开排序
    int mid = (end + start) / 2;
    merge_sort(A, start, mid);
    merge_sort(A, mid, end);

    /// 3. 合并有序子数组中的元素
    /// 3.1 分配临时空间存放合并元素
    int* tmp = new int[end - start];
    /// 3.2 依次取出子数组的元素，进行合并
    int left_idx = start, right_idx = mid, i = 0;
    while (left_idx < mid && right_idx < end) {
        if (A[left_idx] < A[right_idx])
            tmp[i++] = A[left_idx++];
        else
            tmp[i++] = A[right_idx++];
    }

    /// 3.3 如果有子数组元素没有取完，则全部并入临时空间
    while (left_idx < mid)  tmp[i++] = A[left_idx++]; /// 先左
    while (right_idx < end) tmp[i++] = A[right_idx++];/// 后右

    /// 3.4 从临时空间复制回返回数组中
    for (int i = 0, idx = start; i < end - start; i++, idx++)
        A[idx] = tmp[i];

        /// 3.5 释放临时空间
        delete[] tmp;
}
