#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

// ������ �ִ� ����
#define MAX_NUM 10000

using namespace std;

pair<int, int> gas_station[MAX_NUM + 1];

priority_queue<int> pq;

int main(void)
{
	// N : ������ ����, L : ���������� �Ÿ�, P : Ʈ���� �ִ� ������ ��
	int N, L, P;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int pos, fuel;
		scanf("%d %d", &gas_station[i].first, &gas_station[i].second);
	}

	sort(gas_station + 1, gas_station + N + 1);

	cin >> L >> P;

	// �����ִ� ���ᷮ
	int my_fuel = P;

	// �����ҿ��� ���ߴ� Ƚ��
	int stops = 0;

	// �湮�ϴ� �������� ��ȣ
	int num = 1;

	while (my_fuel < L) {
		// ���� ���Ḧ ������ �湮�� �� �ִ� ��� �������� ���Ḧ �켱���� ť�� �ֱ�
		while (num <= N && my_fuel >= gas_station[num].first) {
			pq.push(gas_station[num].second);
			num++;
		}

		if (pq.empty()) {
			stops = -1;
			break;
		}

		my_fuel += pq.top();
		pq.pop();
		stops++;
	}

	cout << stops;

	return 0;
}