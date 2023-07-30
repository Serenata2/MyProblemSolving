#include <iostream>
#include <vector>

#define MAX_NUM 10000

using namespace std;

int wine[MAX_NUM + 1];
int D[MAX_NUM + 1];

int main() {
	int N;
	cin >> N;

	// 입력 받기
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}

	// 초기화
	D[1] = wine[1];
	D[2] = wine[1] + wine[2];
	D[3] = max(D[2], max(wine[1] + wine[3], wine[2] + wine[3]));

	for (int i = 4; i <= N; i++) {
		D[i] = max(wine[i] + D[i - 2], max(wine[i] + wine[i - 1] + D[i - 3], D[i - 1]));
	}

	cout << D[N];

	return 0;
}
