#include <iostream>
#include <cstdio>

#define MAX_NUM 1000

using namespace std;

int rgb[MAX_NUM + 1][3];
int D[MAX_NUM + 1][3];

int main()
{
	int N;
	cin >> N;

	// 각 집을 칠하는데 드는 비용을 입력 받는다.
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
	}

	// 초기화
	D[1][0] = rgb[1][0];
	D[1][1] = rgb[1][1];
	D[1][2] = rgb[1][2];

	// D[i][j] : i 번째집을 j로 칠할 때 최소비용
	// j = 0 : R, j = 1 : G, j = 2 : B
	for (int i = 2; i <= N; i++) {
		D[i][0] = min(D[i - 1][1], D[i - 1][2]) + rgb[i][0];
		D[i][1] = min(D[i - 1][0], D[i - 1][2]) + rgb[i][1];
		D[i][2] = min(D[i - 1][0], D[i - 1][1]) + rgb[i][2];
	}

	cout << min(min(D[N][0], D[N][1]), D[N][2]);

	return 0;
}