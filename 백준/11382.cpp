#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C;

	// ���� �ð�, ��, �ʿ� �ð� �Է¹ޱ�
	cin >> A >> B >> C;

	// 60 * 24�� ������ ���ϱ�
	int time = (60 * A + B + C) % (60 * 24);

	cout << (int)(time / 60) << " " << time % 60;

	return 0;
}

