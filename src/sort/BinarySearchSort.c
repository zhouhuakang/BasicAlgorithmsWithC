/*
 * BinartSearchSort.c
 *
 *  Created on: 2016年5月31日
 *      Author: zhouhuakang
 */

void binarySearchSort(int a[], int n) {
	//a[0]作为哨兵,n为数组中实际存储的数据的个数，故数组总长度应该是n+1
	int low = 1;
	int high = 0;
	int mid = 0;
	int i = 0, j = 0, k = 0;

	printf("排序前:");
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	for (i = 2; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			high = i - 1;
			a[0] = a[i];
			//注意，“＝”时，也需要执行循环
			while (low <= high) {
				mid = (low + high) / 2;
				if (a[mid] > a[0]) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			for (j = i - 1; j >= high + 1; j--) {
				a[j + 1] = a[j];
			}
			a[high + 1] = a[0];
		}
		printf("第%d次排序后:[ ", i - 1);
		for (k = 1; k <= n; k++) {

			printf("%d ", a[k]);
			if (k == i) {
				printf("]");
			}
		}
		printf("\n");
	}

	printf("最终排序后:");
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

}
void testBinarySearchSort() {
//	int a[] = { 0, 1, 4, 7, 5 };
//	binarySearchSort(a, 4);

//	int a[] = { 0, 1, 7, 9, 10, 11, 18, 31, 3 };
//	binarySearchSort(a, 8);

	/**
	 * 有bug的序列，有时间再解决
	 */
//	int b[] = { 0, 31, 18, 11, 10, 7, 9, 1, 3, 2, 7 };
//	binarySearchSort(b, 10);
//	int b[] = { 0, 7, 9, 10, 11, 18, 31, 1 };
//	binarySearchSort(b, 7);
//	int b[] = { 0, 1, 2, 3, 7, 9, 10, 11, 18, 31, 7 };
//	binarySearchSort(b, 10);
}
