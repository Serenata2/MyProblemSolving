#include <iostream>

using namespace std;

int main(void)
{
	int count = 1; // �������� ���� ����
	int N = 0; // �Է� �޴� ���� N

	cin >> N;

	N -= 1;
	int i = 1;

	while (N > 0) {
		N -= 6 * i++; // ������ �Ѳ�Ǯ�� �賤��.
		count++;
	}

	cout << count;

	return 0;
}

