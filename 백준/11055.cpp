#include <iostream>
#include <cstdio>

#define MAX_NUM 1000

using namespace std;

// D[i].first : 마지막으로 i번째 항이 포함되는 증가하는 부분 수열 중 가장 큰 합
// D[i].second : i번째 항의 값
pair<int, int> D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	cin >> D[1].first;
	D[1].second = D[1].first;

	for (int i = 2; i <= N; i++) {
		int num;
		scanf("%d", &num);

		// i 번째 항보다 작은 값으로 끝나는 증가하는 부분 수열 중에서
		// 가장 큰 값을 가지는 부분 수열 찾기
		int max = i;
		for (int j = i - 1; j > 0; j--) {
			if (D[j].second < num && D[j].first > D[max].first) {
				max = j;
			}
		}

		D[i].first = D[max].first + num;
		D[i].second = num;
	}

	int result = D[1].first;

	// 한바퀴 다시 돌면서 최대 부분 수열 찾기
	for (int i = 2; i <= N; i++) {
		if (D[i].first > result) {
			result = D[i].first;
		}
	}

	cout << result;

	return 0;
}