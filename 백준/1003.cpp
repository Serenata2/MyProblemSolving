#include <iostream>
#include <cstdio>

#define MAX_NUM 40

using namespace std;

pair<int, int> D[MAX_NUM + 1];

int main()
{
	int T;
	cin >> T;

	// 초기화
	D[0].first = 1;
	D[1].second = 1;

	// 피보나치 함수 호출 횟수를 계속 더해나간다.
	for (int i = 2; i <= MAX_NUM; i++) {
		D[i].first = D[i - 1].first + D[i - 2].first;
		D[i].second = D[i - 1].second + D[i - 2].second;
	}

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", D[n].first, D[n].second);
	}

	return 0;
}