#include <iostream>

using namespace std;

int main() {
	long long N;
	cin >> N;

	// i번째 돌을 받을 때 이길 수 있으면 1, 아니면 0
	// 이때 이기거나 지는 경우는 규칙적으로 계속 반복된다.
	int D[7] = { 1, 0, 1, 1, 1, 1, 0 };

	if (D[(N - 1) % 7]) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	cout << endl;

	return 0;
}
