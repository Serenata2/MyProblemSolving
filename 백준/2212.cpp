#include <iostream>
#include <cstdio>	
#include <algorithm>

#define MAX_NUM 10000
using namespace std;

int sensor[MAX_NUM];
int dist[MAX_NUM];

int main(void)
{
	int N, K;
	int result = 0;

	cin >> N >> K;

	// 센서보다 지상국이 더 많거나 같으면 최소 길이 합은 0
	if (N > K) {
		// 센서 위치 입력 및 배열에 저장하기
		for (int i = 0; i < N; i++) {
			scanf("%d", &sensor[i]);
		}
		
		// 오름차순으로 정렬
		sort(sensor, sensor + N);

		// 센서 사이의 거리를 계산
		for (int i = 0; i < N - 1; i++) {
			dist[i] = sensor[i + 1] - sensor[i];
		}

		// 센서 사이의 거리를 오름차순으로 정렬
		sort(dist, dist + N - 1);

		// K개의 지상국이 생길 때까지 센서를 이어주기
		int i = 0;
		while (N > K) {
			result += dist[i++];
			N--;
		}

	}

	cout << result;

	return 0;
}