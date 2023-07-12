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

	// �� ����� ���� �ϴ� �迭�� ���� �ִ´�.
	int first;
	cin >> first;
	D[1].push_back(first);

	// D[x][y] : x������ y+1��°�� ������ �� �ִ밪
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

	// �� �Ʒ������� �ִ밪�� ã�´�.
	int result = D[n][0];
	for (int i = 1; i < n; i++) {
		if (D[n][i] > result) {
			result = D[n][i];
		}
	}

	cout << result;

	return 0;
}