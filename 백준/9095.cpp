#include <iostream>

#define MAX_NUM 11

using namespace std;

// D[x] : x�� 1, 2, 3�� ������ ��Ÿ���� ���
int D[MAX_NUM + 1];

int main()
{
	// D �迭 �ʱ�ȭ
	D[1] = 1;
	D[2] = 2; // "1 + 1", "2"
	D[3] = 4; // "1 + 1 + 1", "1 + 2", "2 + 1", "3" -> D[1] + D[2] + "3"

	// ���ʴ�� D[i] ���ϱ�
	for (int i = 4; i <= MAX_NUM; i++) {
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << D[n] << endl;
	}

	return 0;
}