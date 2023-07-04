#include <iostream>

using namespace std;
int D[1000001];

int main(void)
{
	int N;
	int number = 1;
	int count = 0;

	// �̸� ��� ����� �� ���س���
	while (count < 1000000) {
		int n = number;
		int num = 0;
		while (n > 0) {
			// 0000 0000 10 -> ���� 1�� �̹� ���� ���
			if ((num & (1 << (n % 10))) != 0) {
				break;
			}
			else {
				num |= 1 << (n % 10);
			}
			n /= 10;
		}

		if (n == 0) {
			count++;
			D[count] = number;
		}
		number++;
	}

	// 0�� �Է��� ������ �̸� ���� ���� ����ϱ�
	while (1) {
		cin >> N;
		if (N == 0) {
			break;
		}
		cout << D[N] << endl;
	}
	return 0;
}