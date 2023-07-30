#include <iostream>
#include <vector>

#define MAX_NUM 10000

using namespace std;

int wine[MAX_NUM + 1];
// D[i][0] : i번째 포도주를 먹을 때 i-1번 포도주를 안 먹은 경우
// D[i][1] : i번째 포도주를 먹을 때 i-1번 포도주를 먹은 경우
// D[i][2] : D[i][0]과 D[i][1] 중 더 큰 값
int D[MAX_NUM + 1][3];

int main() {
	int N;
	cin >> N;

	// 입력 받기
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}

	// 초기화
	D[1][0] = wine[1];
	D[1][1] = wine[1];
	D[1][2] = wine[1];

	D[2][0] = wine[2];
	D[2][1] = wine[1] + wine[2];
	D[2][2] = D[2][1];

	D[3][0] = wine[1] + wine[3];
	D[3][1] = wine[2] + wine[3];
	D[3][2] = max(D[3][0], D[3][1]);

	for (int i = 4; i <= N; i++) {
		// i-1번 포도주를 마시지 않은 경우
		D[i][0] = max(D[i - 2][2], D[i - 3][2]) + wine[i];

		// i-1번 포도주를 마신 경우
		D[i][1] = D[i-1][0] + wine[i];

		D[i][2] = max(D[i][0], D[i][1]);
	}

	cout << max(D[N][2], D[N - 1][1]) << endl;

	return 0;
}
