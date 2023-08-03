#include <iostream>
#include <climits>
#include <set>

#define MAX_NUM 10000

using namespace std;

int arr[101];
set<int> s;
//D[i]: 지금까지 알고있는 동전들을 가지고 i원을 만들 수 있는 최소한의 동전개수
int D[MAX_NUM + 1];

int main()
{
	int N, K;

	cin >> N >> K;

	// 중복되지 않게 입력받기
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		if (s.find(num) == s.end()) {
			arr[cnt++] = num;
			s.insert(num);
		}
	}
	N = cnt - 1;

	// 첫 번째 동전을 가지고 만들 수 있는 모든 경우 초기화하기
	for (int i = 1; i <= K; i++) {
		D[i] = INT_MAX;
		if (arr[1] <= i && i % arr[1] == 0) {
			D[i] = i / arr[1];
		}
	}

	// 나머지 동전들을 차례대로 추가하면서 D배열 채우기
	for (int i = 2; i <= N; i++) {
		if (arr[i] <= MAX_NUM) {
			D[arr[i]] = 1;
		}
		for (int j = arr[i] + 1; j <= K; j++) {
			if (D[j - arr[i]] != INT_MAX) {
				D[j] = min(D[j], 1 + D[j - arr[i]]);
			}
		}
	}

	// K원을 못 만드는 경우
	if (D[K] == INT_MAX) {
		cout << -1;
	}
	// K원을 만들 수 있는 경우
	else {
		cout << D[K];
	}

	return 0;
}