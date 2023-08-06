#include <iostream>
#include <vector>

#define MAX_NUM 100000

using namespace std;

int g[MAX_NUM + 1][4];

int main() {
	int k = 1;
	while (1) {
		int N;
		cin >> N;

		// ���� ������ 0�̸� �����ϱ�
		if (N == 0) {
			break;
		}

		// �ﰢ �׷��� �Է� �ޱ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> g[i][j];
			}
		}

		// D[i][j] : i��, j ���� ������ �� �ּҺ��
		vector<vector<int>> D(N + 1, vector<int>(4, 0));

		// �ʱ�ȭ
		D[1][1] = 1001; // D[1][1] ���� ������ �ִ� ��뺸�� ũ�� ���� g[1][1]�� Ÿ�� ���� ���� ������ �Ѵ�
		D[1][2] = g[1][2];
		D[1][3] = g[1][2] + g[1][3];

		for (int i = 2; i <= N; i++) {
			D[i][1] = min(D[i - 1][1], D[i - 1][2]) + g[i][1];
			D[i][2] = min(min(min(D[i][1], D[i - 1][1]), D[i - 1][2]), D[i - 1][3]) + g[i][2];
			D[i][3] = min(min(D[i][2], D[i - 1][2]), D[i - 1][3]) + g[i][3];
		}

		cout << k << ". " << D[N][2] << endl;
		k++;
	}

	return 0;
}
