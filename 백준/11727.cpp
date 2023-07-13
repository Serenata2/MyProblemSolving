#include <iostream>

#define MAX_NUM 1000
#define DIVISION_NUM 10007

using namespace std;

long long D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// 초기화
	D[1] = 1;
	D[2] = 3;

	// 동적 계획법으로 풀기
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + 2 * D[i - 2]) % DIVISION_NUM;
	}

	cout << D[N];

	return 0;
}