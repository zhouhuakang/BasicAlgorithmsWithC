/*
 * DirectInsortSort.c
 *
 *  Created on: 2016年5月31日
 *      Author: zhouhuakang
 */
void directInsertSort(int a[], int n) {

	//a[0]作为哨兵,n为数组中实际存储的数据的个数，故数组总长度应该是n+1
	int i = 0, j = 0;

	printf("排序前:");
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	for (i = 2; i <= n; ++i) {
		if (a[i] < a[i - 1]) {
			a[0] = a[i];
			for (j = i - 1; a[j] > a[0]; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}

	}

	printf("排序后:");
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}

}
void testDirectInsertSort() {
	int a[] = { 0, 31, 18, 11, 10, 7, 9, 1, 3, 2, 7 };
	directInsertSort(a, 10);
}
//int main(void) {
//	testDirectInsertSort();
//	return 0;
//}

