#include<stdio.h>
#include <stdlib.h>
#include <time.h>


void khoiTaoMang2Chieu(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % (100 + 1);
		}
	}
}
void xuatMang2Chieu(int a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void tinhTongTungDong(int a[][100], int m, int n) {

	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		printf("Tong gia tri cua phan tu tai dong %d: %d\n", i, sum);
	}
}

void xuatGiaTriLonNhatMoiCot(int a[][100], int m, int n) {
	for (int j = 0; j < n; j++)
	{
		int max = a[0][j];
		for (int i = 0; i < m; i++) {
			if (max < a[i][j])
				max = a[i][j];
		}
		printf("Gia tri lon nhat tai cot %d la %d\n", j, max);
	}
}

void xuatPhanTuDuongBien(int a[][100], int m, int n) {
	printf("Cac phan tu thuoc duong bien cua ma tran la: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				printf("%5d", a[i][j]);
			}
			else {
				printf("     ");
			}
		}
		printf("\n");
	}
}


int timCucDai(int a[][100], int soDong, int soCot) {
	int max = a[0][0];

	for (int i = 0; i < soDong; i++) {
		for (int j = 0; j < soCot; j++) {
			int isCucDai = 1;

			if (i > 0 && a[i][j] < a[i - 1][j]) isCucDai = 0; 
			if (j < soCot - 1 && a[i][j] < a[i][j + 1]) isCucDai = 0; 
			if (i > 0 && j > 0 && a[i][j] < a[i - 1][j - 1]) isCucDai = 0; 
			if (i > 0 && j < soCot - 1 && a[i][j] < a[i - 1][j + 1]) isCucDai = 0; 
			if (i < soDong - 1 && j > 0 && a[i][j] < a[i + 1][j - 1]) isCucDai = 0; 
			if (i < soDong - 1 && j < soCot - 1 && a[i][j] < a[i + 1][j + 1]) isCucDai = 0; 
			if (isCucDai && a[i][j] > max) {
				max = a[i][j];
			}
		}
	}

	return max;
}


void xuatDongChiChuaSoChan(int a[][100], int m, int n) {
	printf("Cac dong chi chua so chan: \n");
	for (int i = 0; i < m; i++) {
		int isChan = 1;
		for (int j = 0; j < n; j++) {
			if (a[i][j] % 2 != 0) {
				isChan = 0;
				break;
			}
		}
		if (isChan) {
			for (int j = 0; j < n; j++) {
				printf("%5d", a[i][j]);
			}
			printf("\n");
		}
	}
}

void sapXepDongTangDan(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void sapXepDongTangDan(int a[][100], int m) {
	for (int i = 0; i < m; i++) {
		sapXepDongTangDan(a[i], m);
	}
}

void bai1() {
	srand(time(NULL));
	int m = 5;
	int n = 5;
	int a[100][100];

	khoiTaoMang2Chieu(a, m, n);

	printf("Mang 2 chieu duoc khoi tao ngau nhien: \n");
	xuatMang2Chieu(a, m, n);


	sapXepDongTangDan(a, m);
	printf("Mang sau khi sap xep cac dong tang dan: \n");
	xuatMang2Chieu(a, m, n);

	return;
}