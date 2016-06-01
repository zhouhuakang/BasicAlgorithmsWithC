/*
 * QuickSort.c
 *
 *  Created on: 2016年5月31日
 *      Author: zhouhuakang
 */

#include "QuickSort.h"
/**
 * 一趟分割,返回待排序序列的中间大小的值的坐标pivot，使左边的元素值都比它小，右边的都比它大
 */
int partition(int a[], int low, int high) {
	int pivot = low; //中间值选为第1个元素（其实中间值的位置应该是可以任选的）
	//a[0]暂存中间值，减少移动中间值的操作，因为只有当low=high,分割程序介绍之后，中间值才会最终确定其位置
	a[0] = a[pivot];
	while (low < high) {
		//high从后往前，逐个找寻元素与a[0](即中间值)作比较，若a[high]较大或相等
		//，则继续往前寻找，直至找到比a[0]小的元素，此时，结束往前探寻的行为，推出循环，准备将较小的值放到此时
		//low所指的位置，其实就是pivot中间值原先的位置，因为初始化时，我们让pivot=low
		while (low < high && a[high] >= a[0]) {
			--high; //一直从后往前探寻，直至找到比中间值小的值为止
		}
		// 找到一个比中间值小的值，此时high指向它
		//此时,high所指的位置已经空出来，可以为下次low所指的比中间值大的元素的移动腾出空间
		a[low] = a[high];

		while (low < high && a[low] <= a[0]) {
			low++; //一直从前往后探寻，直至找到比中间值大的值为止
		}
		// 找到一个比中间值大的值，此时low指向它
		//此时,由于上一次循环借宿后，high所指的位置已经空出来，low所指的元素可以直接赋值过去
		a[high] = a[low];

	}
	//最后，low或则high所指的位置即为中间值最终所在的位置
	a[low] = a[0];		//中间值最终归位

	return low;
}
void Qsort(int a[], int low, int high) {
	if (low < high) {
		int pivot = partition(a, low, high);
		Qsort(a, low, pivot - 1);
		Qsort(a, pivot + 1, high);
	}
}
void TestQsort() {

	int a[] = { 0, 3, 4, 2, 5, 6, 7, 11, 23, 45, 1, 2, 4, 5 };
	printArray(a, 13);
	Qsort(a, 1, 13);
	printArray(a, 13);

	int b[] = { 0, 30, 46, 12, 1, 6, 7, 11, 23, 45, 1, 2, 4, 5 };
	printArray(b, 13);
	Qsort(b, 1, 13);
	printArray(b, 13);
}
void tetsPartition() {
	int a[] = { 0, 3, 4, 2, 5, 6, 7 };
	partition(a, 1, 6);
}
void printArray(int a[], int n) {
	int i;
	for (i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
