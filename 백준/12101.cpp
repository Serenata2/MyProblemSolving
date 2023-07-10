#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 11

using namespace std;


int main()
{
	int N, K;
	cin >> N >> K;

	vector<string> D[MAX_NUM + 1];

	// 초기화
	D[1].push_back("1");

	D[2].push_back("11");
	D[2].push_back("2");

	D[3].push_back("111");
	D[3].push_back("12");
	D[3].push_back("21");
	D[3].push_back("3");

	// 브루트포스로 모든 경우의 수를 구한다.
	for (int i = 4; i <= N; i++) {
		for (auto str: D[i - 1]) {
			D[i].push_back(str.append("1"));
		}
		for (auto str : D[i - 2]) {
			D[i].push_back(str.append("2"));
		}
		for (auto str : D[i - 3]) {
			D[i].push_back(str.append("3"));
		}
	}

	if (D[N].size() < K) {
		cout << -1;
	}
	else {
		// 사전 순으로 정렬
		sort(D[N].begin(), D[N].end());
		// 출력
		for (int i = 0; i < D[N][K-1].length(); i++) {
			cout << D[N][K - 1][i];
			if (i != D[N][K - 1].length() - 1) {
				cout << "+";
			}
		}
	}

	return 0;
}