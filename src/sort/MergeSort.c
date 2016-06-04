/*
 * MergeSort.c
 *
 *  Created on: 2016年6月4日
 *      Author: zhouhuakang
 */

/**
 * 一趟归并，将两有序表source[low...mid],source[mid+1...high]
 * 归并到target[low....high]中
 */
void Merge(int source[], int target[], int low, int mid, int high) {
	//k1,k2分别为source[low...mid],source[mid+1...high]中的工作“指针”
	//k为target[low....high]中的工作“指针”
	int k, k1, k2;
	int j;
	for (k = k1 = low, k2 = mid + 1; k1 <= mid && k2 <= high; k++) {
		if (source[k1] < source[k2]) {
			target[k] = source[k1];
			k1++;
		} else {
			target[k] = source[k2];
			k2++;
		}
	}
	if (k1 < mid) {	//代表source[low..mid]有序表中还有剩余的元素没有移动到target数组中
		for (j = k1; j <= mid; j++, k++) {
			target[k] = source[j];
		}
	}
	if (k2 < high) {	//代表source[mid..high]有序表中还有剩余的元素没有移动到target数组中
		for (j = k2; k2 <= high; j++, k++) {
			target[k] = source[j];
		}
	}
	for (j = low; j <= high; j++) {
		printf("%d   ", target[j]);
	}
}
void testMerge() {
	// source[0]不存有效数据
	//1,3,7,13为第一个有序子表
	//5,15,19,21为第二个有序子表
	int source[] = { 0, 1, 3, 7, 13, 5, 15, 19, 21 };
	int target[10];
	Merge(source, target, 1, 4, 8);
}
