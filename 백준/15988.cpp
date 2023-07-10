#include <iostream>

#define MAX_NUM 1000000
#define DIVISION_NUM 1000000009

using namespace std;


int main()
{
	long long D[MAX_NUM + 1];
	
	// �ʱ�ȭ
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;

	// D[i] : i�� 1, 2, 3�� ������ ��Ÿ���� ���
	for (int i = 4; i <= MAX_NUM; i++) {
		D[i] = (D[i - 1]  + D[i - 2] + D[i - 3]) % DIVISION_NUM;
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