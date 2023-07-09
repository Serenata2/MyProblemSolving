#include <iostream>

#define MAX_NUM 1000000

using namespace std;

// D[x] : x���� 1�� ��������� �ּ����� Ƚ��
int D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// D �迭 �ʱ�ȭ
	D[1] = 0;
	D[2] = 1;
	D[3] = 1;

	// i�� ���� �� �ִ� 3���� ��� �� ���� ���� ��� ã��
	for (int i = 4; i <= N; i++) {
		int min = D[i - 1];

		if (i % 2 == 0 && D[i / 2] < min) {
			min = D[i / 2];
		}
		if (i % 3 == 0 && D[i / 3] < min) {
			min = D[i / 3];
		}
		D[i] = min + 1;
	}

	cout << D[N];

	return 0;
}