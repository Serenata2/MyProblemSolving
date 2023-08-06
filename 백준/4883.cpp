#include <iostream>
#include <vector>

#define MAX_NUM 100000

using namespace std;

int g[MAX_NUM + 1][4];

int main() {
	int k = 1;
	while (1) {
		int N;
		cin >> N;

		// 행의 개수가 0이면 종료하기
		if (N == 0) {
			break;
		}

		// 삼각 그래프 입력 받기
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> g[i][j];
			}
		}

		// D[i][j] : i행, j 열에 도달할 때 최소비용
		vector<vector<int>> D(N + 1, vector<int>(4, 0));

		// 초기화
		D[1][1] = 1001; // D[1][1] 값을 정점의 최대 비용보다 크게 만들어서 g[1][1]을 타고 가는 일이 없도록 한다
		D[1][2] = g[1][2];
		D[1][3] = g[1][2] + g[1][3];

		for (int i = 2; i <= N; i++) {
			D[i][1] = min(D[i - 1][1], D[i - 1][2]) + g[i][1];
			D[i][2] = min(min(min(D[i][1], D[i - 1][1]), D[i - 1][2]), D[i - 1][3]) + g[i][2];
			D[i][3] = min(min(D[i][2], D[i - 1][2]), D[i - 1][3]) + g[i][3];
		}

		cout << k << ". " << D[N][2] << endl;
		k++;
	}

	return 0;
}
