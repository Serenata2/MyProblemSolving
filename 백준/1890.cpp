#include <iostream>
#include <climits>
#include <set>

#define MAX_NUM 500

using namespace std;

int map[MAX_NUM + 1][MAX_NUM + 1];
long long D[MAX_NUM + 2][MAX_NUM + 2];

int main()
{
	// M: 세로 크기, N : 가로 크기
	int N;
	cin >> N;

	// 지도 입력 받기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// 초기화
	D[1][1] = map[1][1] > 0 ? 1 : 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// (i, j)의 값이 0이 아니거나, (i,j)에 갈 수 있다면
			// D배열 값 추가하기
			if (map[i][j] != 0 && D[i][j] != 0) {
				if (i + map[i][j] <= N) {
					D[i + map[i][j]][j] += D[i][j];
				}
				if (j + map[i][j] <= N) {
					D[i][j + map[i][j]] += D[i][j];
				}
			}
		}
	}

	cout << D[N][N];

	return 0;
}