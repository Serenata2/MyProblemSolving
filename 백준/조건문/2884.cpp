#include <iostream>

using namespace std;

int main(void)
{
	int H, M;

	// �ð�, �� �Է¹ޱ�
	cin >> H >> M;

	// �Է��� 24�ð��� ǥ���� �� ������ ǥ���ϰ� 45���� ����.
	int time = (60 * H + M) - 45;

	time = (time < 0) ? (60 * 24 + time) : time;

	cout << (int)(time / 60) << " " << time % 60;

	return 0;
}

