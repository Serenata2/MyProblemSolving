#include <iostream>

#define MAX_NUM 90

using namespace std;

long long D[MAX_NUM + 1][2];

int main()
{
	int N;
	cin >> N;

	// 초기화
	D[1][1] = 1;
	
	// 동적계획법으로 풀기
	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}

	cout << D[N][0] + D[N][1];

	return 0;
}