#include <iostream>

using namespace std;

int main() {
	long long N;
	cin >> N;

	// i��° ���� ���� �� �̱� �� ������ 1, �ƴϸ� 0
	// �̶� �̱�ų� ���� ���� ��Ģ������ ��� �ݺ��ȴ�.
	int D[7] = { 1, 0, 1, 1, 1, 1, 0 };

	if (D[(N - 1) % 7]) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	cout << endl;

	return 0;
}
