#include <iostream>
#include <vector>

#define MAX_NUM 20

using namespace std;

int coin[MAX_NUM + 1];

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		// 동전의 개수 입력받기
		for (int j = 1; j <= N; j++) {
			cin >> coin[j];
		}

		// 금액 입력받기
		int M;
		cin >> M;

		vector<int> D(M + 1, 0);

		// 초기화
		for (int j = 1; j <= M; j++) {
			if (j % coin[1] == 0) {
				D[j] = 1;
			}
		}
		
		for (int j = 2; j <= N; j++) {
			if (coin[j] <= M) {
				D[coin[j]] += 1;
			}
			for (int k = coin[j] + 1; k <= M; k++) {
				D[k] = D[k] + D[k - coin[j]];
			}
		}

		cout << D[M] << endl;
	}



	return 0;
}
