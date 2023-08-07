#include <iostream>
#include <string>

#define MAX_NUM 1000

using namespace std;

// D[i][j] : (i, j)�� ������ �Ʒ������� �ϴ� 
//           1�� �� ���� ū ���簢���� �� ���� ����
int D[MAX_NUM + 1][MAX_NUM + 1];

int main() {
	int n, m;
	cin >> n >> m;

	int ans = 0;
	// �迭 �Է¹ޱ�
	for (int i = 1; i <= n; i++) {
		string numbers;
		cin >> numbers;

		numbers.insert(0, "0");
		for (int j = 1; j <= m; j++) {

			if (numbers[j] == '1') {
				if (i == 1 || j == 1) {
					D[i][j] = 1;
				}
				else {
					D[i][j] = min(min(D[i - 1][j], D[i][j - 1]), D[i - 1][j - 1]) + 1;
				}

				ans = max(ans, D[i][j]);
			}
			else {
				D[i][j] = 0;
			}
		}
	}

	cout << ans * ans;

	return 0;
}
