#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main(void)
{
	// X, Y : �� ��ġ, W : �� ��� ���µ� �ɸ��� �ð�, S : �밢������ �� ����� ���������� �ð�
	long long X, Y, W, S;			
	
	cin >> X >> Y >> W >> S;

	long long result = 0;

	// �밢������ ���� �ͺ��� ������� �ι� ���°� �� ���� ���
	if (2 * W <= S) {
		result = (X + Y) * W;
	}
	// ������� �ι� ���� �ͺ��� �밢������ �ѹ� ���°� �� ���� ���
	else if (W <= S) {
		if (X < Y) {
			swap(X, Y);
		}
		// �ִ��� �밢������ �� ���Ŀ� ����� �̿�
		result = Y * S + (X - Y) * W;
	}
	// ��� �ѹ� ���°� �밢�� �ѹ� ���� �ͺ��� ���� ū ���
	else {
		if (X < Y) {
			swap(X, Y);
		}
		// �ִ��� �밢������ �� ����, ���� �Ÿ��� ���� �밢���� �̿��ؼ� �̵�
		result = Y * S + (long long)((X - Y) / 2) * 2 * S;
		// ���� ���� �Ÿ��� Ȧ���̸� ��� �ѹ� �̿�
		if ((X - Y) % 2 == 1) {
			result += W;
		}
	}

	cout << result;

	return 0;
}