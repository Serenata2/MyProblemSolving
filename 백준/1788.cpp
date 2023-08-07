#include <iostream>
#include <vector>

#define MAX_NUM 1000000
#define DIVISION_NUM 1000000000

using namespace std;

// D[i] : F( |i| )의 값
int D[MAX_NUM + 1];

int main() {
	int N;
	cin >> N;

	// F(1) = F(-1) = 1로 초기화
	D[1] = 1;

	// N이 양수인 경우
	if (N > 0) {
		for (int i = 2; i <= N; i++) {
			D[i] = (D[i - 1] + D[i - 2]) % DIVISION_NUM;
		}
	}
	// N이 음수인 경우
	else {
		N = -1 * N;
		for (int i = 2; i <= N; i++) {
			D[i] = (D[i - 2] - D[i - 1]) % DIVISION_NUM;
		}
	}

	if (D[N] > 0) {
		cout << 1 << endl;
		cout << D[N];
	}
	else if (D[N] < 0) {
		cout << -1 << endl;
		cout << abs(D[N]);
	}
	else {
		cout << 0 << endl << 0;
	}

	return 0;
}
