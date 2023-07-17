#include <iostream>

#define MAX_NUM 100
#define DIVISION_NUM 1000000000

using namespace std;

long long D[MAX_NUM + 1][10];

int main()
{
	int N;
	cin >> N;

	// 초기화
	for (int i = 1; i <= 9; i++) {
		D[1][i] = 1;
	}

	// 동적 계획법
	for (int i = 2; i <= N; i++) {
		// 0과 9는 따로 예외처리
		D[i][0] = D[i - 1][1];
		D[i][9] = D[i - 1][8];

		for (int j = 1; j <= 8; j++) {
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % DIVISION_NUM;
		}
	}

	long long result = 0;
	for (int i = 0; i <= 9; i++) {
		result = (result + D[N][i]) % DIVISION_NUM;
	}

	cout << result;


	return 0;
}