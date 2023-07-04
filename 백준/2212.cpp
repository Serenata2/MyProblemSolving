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

	// �������� ������ �� ���ų� ������ �ּ� ���� ���� 0
	if (N > K) {
		// ���� ��ġ �Է� �� �迭�� �����ϱ�
		for (int i = 0; i < N; i++) {
			scanf("%d", &sensor[i]);
		}
		
		// ������������ ����
		sort(sensor, sensor + N);

		// ���� ������ �Ÿ��� ���
		for (int i = 0; i < N - 1; i++) {
			dist[i] = sensor[i + 1] - sensor[i];
		}

		// ���� ������ �Ÿ��� ������������ ����
		sort(dist, dist + N - 1);

		// K���� ������ ���� ������ ������ �̾��ֱ�
		int i = 0;
		while (N > K) {
			result += dist[i++];
			N--;
		}

	}

	cout << result;

	return 0;
}