#include <iostream>

#define MAX_NUM 90

using namespace std;

long long D[MAX_NUM + 1][2];

int main()
{
	int N;
	cin >> N;

	// �ʱ�ȭ
	D[1][1] = 1;
	
	// ������ȹ������ Ǯ��
	for (int i = 2; i <= N; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}

	cout << D[N][0] + D[N][1];

	return 0;
}