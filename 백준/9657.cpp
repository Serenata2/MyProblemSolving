#include <iostream>

#define MAX_NUM 1000

using namespace std;

// D[i] : i개의 돌을 받았을 때 이길 수 있으면 true, 아니면 false
bool D[MAX_NUM + 1];

int main() {
	int N;
	cin >> N;

	// 초기화
	D[1] = true;
	D[3] = true;
	D[4] = true;

	for (int i = 5; i <= N; i++) {
		if (!D[i - 1] || !D[i - 3] || !D[i - 4]) {
			D[i] = true;
		}
	}

	if (D[N]) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}
