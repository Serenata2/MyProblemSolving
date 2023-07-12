#include <iostream>
#include <vector>
#include <cstdio>

#define MAX_NUM 500

using namespace std;

vector<int> D[MAX_NUM + 1];

int main()
{
	int n;
	cin >> n;

	// 맨 꼭대기 값을 일단 배열에 집어 넣는다.
	int first;
	cin >> first;
	D[1].push_back(first);

	// D[x][y] : x층에서 y+1번째에 도달할 때 최대값
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			int num;
			scanf("%d", &num);

			if (j == 0) {
				D[i].push_back(D[i - 1][j] + num);
			}
			else if (j == i - 1) {
				D[i].push_back(D[i - 1][j - 1] + num);
			}
			else {
				D[i].push_back(max(D[i - 1][j - 1], D[i - 1][j]) + num);
			}
		}
	}

	// 맨 아래층에서 최대값을 찾는다.
	int result = D[n][0];
	for (int i = 1; i < n; i++) {
		if (D[n][i] > result) {
			result = D[n][i];
		}
	}

	cout << result;

	return 0;
}