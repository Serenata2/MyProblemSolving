#include <iostream>

#define MAX_NUM 100000

using namespace std;

pair<int, int> stuff[101];
pair<int, int> D[MAX_NUM + 1];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> stuff[i].first >> stuff[i].second;
	}

	// 초기화
	for (int i = stuff[1].first; i <= K; i++) {
		D[i].first = stuff[1].first;
		D[i].second = stuff[1].second;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = K; j >= stuff[i].first + 1; j--) {
			// 공간이 충분한 경우
			if (j - D[j].first >= stuff[i].first) {
				D[j].first += stuff[i].first;
				D[j].second += stuff[i].second;
			}
			// 공간이 부족한 경우
			else{
				if (D[j].second < stuff[i].second + D[j - stuff[i].first].second) {
					D[j].first = stuff[i].first + D[j - stuff[i].first].first;
					D[j].second = stuff[i].second + D[j - stuff[i].first].second;
				}
			}
		}
		if (D[stuff[i].first].second < stuff[i].second) {
			D[stuff[i].first].first = stuff[i].first;
			D[stuff[i].first].second = stuff[i].second;
		}
	}

	cout << D[K].second;

	return 0;
}
