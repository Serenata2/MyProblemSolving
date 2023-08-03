#include <iostream>
#include <vector>

#define MAX_NUM 1000000
#define DIVISION_NUM 1000000000

using namespace std;

int D[MAX_NUM + 1];

int main()
{
	int N, M;
	while (1) {
		cin >> N >> M;

		if (N == 0) {
			break;
		}

		vector<vector<int>> D(N + 1, vector<int>(M + 1, 0));
		vector<vector<int>> v(N + 1, vector<int>(M + 1, 0));

		// 테스트 케이스 입력 받기
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> v[i][j];
			}
		}

		int max_size = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				// (i,j)가 1인 경우
				if (v[i][j] == 1) {
					if (i == 1 || j == 1) {
						D[i][j] = 1;
					}
					else {
						D[i][j] = min(D[i-1][j-1], min(D[i - 1][j], D[i][j - 1])) + 1;
					}
					max_size = max(max_size, D[i][j]);
				}
			}
		}

		cout << max_size << endl;
	}

	return 0;
}