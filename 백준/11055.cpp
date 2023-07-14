#include <iostream>
#include <cstdio>

#define MAX_NUM 1000

using namespace std;

// D[i].first : ���������� i��° ���� ���ԵǴ� �����ϴ� �κ� ���� �� ���� ū ��
// D[i].second : i��° ���� ��
pair<int, int> D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	cin >> D[1].first;
	D[1].second = D[1].first;

	for (int i = 2; i <= N; i++) {
		int num;
		scanf("%d", &num);

		// i ��° �׺��� ���� ������ ������ �����ϴ� �κ� ���� �߿���
		// ���� ū ���� ������ �κ� ���� ã��
		int max = i;
		for (int j = i - 1; j > 0; j--) {
			if (D[j].second < num && D[j].first > D[max].first) {
				max = j;
			}
		}

		D[i].first = D[max].first + num;
		D[i].second = num;
	}

	int result = D[1].first;

	// �ѹ��� �ٽ� ���鼭 �ִ� �κ� ���� ã��
	for (int i = 2; i <= N; i++) {
		if (D[i].first > result) {
			result = D[i].first;
		}
	}

	cout << result;

	return 0;
}