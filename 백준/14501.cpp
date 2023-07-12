#include <iostream>

#define MAX_NUM 15

using namespace std;

int D[MAX_NUM + 1];
pair<int, int> meeting[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// �Է¹ޱ�
	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;
		meeting[i].first = T;
		meeting[i].second = P;
	}

	// D[i] : i�ϱ��� ���� �� ���� �� �ִ� ���ð�
	// i�ϱ��� ����ϴ°� �ִ��� Ȯ���ϰ� �װ� j���� ����̸�
	// D[i-j] + "j�Ͽ� ����ؼ� �޴� ����"�� D[i-1]�� ���ؼ� �� ū ���� ����
	for (int i = 1; i <= N; i++) {
		int max = D[i - 1];
		for (int j = i; j > 0; j--) {
			if (j + meeting[j].first - 1 == i) {
				if (D[j - 1] + meeting[j].second > max) {
					max = D[j - 1] + meeting[j].second;
				}
			}
		}
		D[i] = max;
	}

	cout << D[N];

	return 0;
}