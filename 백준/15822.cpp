#include <iostream>
#include <cstdio>
#include <cmath>

#define MAX_N 2000
using namespace std;

int N; // 파형의 높이
int X[MAX_N + 1]; // 파형 X
int Y[MAX_N + 1]; // 파형 Y
int D[MAX_N + 1][MAX_N + 1];

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &X[i]);
	}
	scanf("%d", &Y[1]);
	// 초기화
	D[1][1] = (X[1] - Y[1]) * (X[1] - Y[1]);
	int set_sum = D[1][1];

	for (int i = 2; i <= N; i++) {
		scanf("%d", &Y[i]);
		set_sum += (X[1] - Y[i]) * (X[1] - Y[i]);
		D[1][i] = set_sum;
	}

	set_sum = D[1][1];
	for (int i = 2; i <= N; i++) {
		set_sum += (X[i] - Y[1]) * (X[i] - Y[1]);
		D[i][1] = set_sum;
	}

	// D[i][j] 구하기
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			int sum = (X[i] - Y[j]) * (X[i] - Y[j]);
			int min = sum + (D[i][j - 1] > D[i - 1][j - 1] ? D[i - 1][j - 1] : D[i][j - 1]);

			for (int k = 1; k <= i - 1; k++) {
				sum += (X[i - k] - Y[j]) * (X[i - k] - Y[j]);
				if (sum > min) {
					break;
				}
				if (min > (sum + D[i - k][j - 1]))
					min = (sum + D[i - k][j - 1]);
				if (k != i - 1 && min > (sum + D[i - k - 1][j - 1]))
					min = (sum + D[i - k - 1][j - 1]);

			}

			D[i][j] = min;
		}
	}

	cout << D[N][N];

	return 0;
}