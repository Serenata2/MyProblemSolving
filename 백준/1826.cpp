#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

// 주유소 최대 개수
#define MAX_NUM 10000

using namespace std;

pair<int, int> gas_station[MAX_NUM + 1];

priority_queue<int> pq;

int main(void)
{
	// N : 주유소 개수, L : 마을까지의 거리, P : 트럭에 있는 연료의 양
	int N, L, P;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int pos, fuel;
		scanf("%d %d", &gas_station[i].first, &gas_station[i].second);
	}

	sort(gas_station + 1, gas_station + N + 1);

	cin >> L >> P;

	// 남아있는 연료량
	int my_fuel = P;

	// 주유소에서 멈추는 횟수
	int stops = 0;

	// 방문하는 주유소의 번호
	int num = 1;

	while (my_fuel < L) {
		// 현재 연료를 가지고 방문할 수 있는 모든 주유소의 연료를 우선순위 큐에 넣기
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