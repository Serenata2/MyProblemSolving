#include <iostream>
#include <vector>
#include <cstdio>

#define MAX_NUM 1500000

using namespace std;

int D[MAX_NUM + 1];
vector<int> arr[MAX_NUM + 1];
pair<int, int> meeting[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// 입력받기
	for (int i = 1; i <= N; i++) {
		int T, P;
		scanf("%d %d", &T, &P);
		meeting[i].first = T;
		meeting[i].second = P;

		if (i + T - 1 <= N) {
			arr[i + T - 1].push_back(i);
		}
	}

	// D[i] : i일까지 일할 수 있을 때 최대 상담시간
	// i일까지 상담하는게 있는지 확인하고 그게 j일의 상담이면
	// D[i-j] + "j일에 상담해서 받는 보수"와 D[i-1]을 비교해서 더 큰 것을 선택
	for (int i = 1; i <= N; i++) {
		int max = D[i - 1];
		for (auto t : arr[i]) {
			if (D[t - 1] + meeting[t].second > max) {
				max = D[t - 1] + meeting[t].second;
			}
		}
		D[i] = max;
	}

	cout << D[N];

	return 0;
}