#include <iostream>

#define MAX_NUM 1000000

using namespace std;

// D[x].first : x���� 1�� ��������� �ּ����� Ƚ��
// D[x].second : x���� 1�� ���� �� ���� �ܰ�
pair<int, int> D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// D �迭 �ʱ�ȭ
	D[1].first = 0;
	D[1].second = 0;
	D[2].first = 1;
	D[2].second = 1;
	D[3].first = 1;
	D[3].second = 1;

	// i�� ���� �� �ִ� 3���� ��� �� ���� ���� ��� ã��
	for (int i = 4; i <= N; i++) {
		int min = D[i - 1].first;
		int pre = i - 1;

		if (i % 2 == 0 && D[i / 2].first < min) {
			min = D[i / 2].first;
			pre = i / 2;
		}
		if (i % 3 == 0 && D[i / 3].first < min) {
			min = D[i / 3].first;
			pre = i / 3;
		}
		D[i].first = min + 1;
		D[i].second = pre;
	}

	cout << D[N].first << endl;

	int i = D[N].second;	
	cout << N << " ";
	while (i > 0) {
		cout << i << " ";
		i = D[i].second;
	}

	return 0;
}