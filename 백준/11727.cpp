#include <iostream>

#define MAX_NUM 1000
#define DIVISION_NUM 10007

using namespace std;

long long D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// �ʱ�ȭ
	D[1] = 1;
	D[2] = 3;

	// ���� ��ȹ������ Ǯ��
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + 2 * D[i - 2]) % DIVISION_NUM;
	}

	cout << D[N];

	return 0;
}