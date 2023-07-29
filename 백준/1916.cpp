#include <stdio.h>
#include <vector>
#include <queue>

#define INF 100001

using namespace std;

int node[1005][1005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
int value[1005];

int main() {
	int n, m;
	int u, v, w;
	int start, end;

	scanf("%d %d", &n, &m);

	// node간에 edge 초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			node[i][j] = INF;

	for (int i = 1; i <= n; i++) {
		node[i][i] = 0;
		value[i] = INF;
	}

	// node간의 edge 입력받기
	// 동일한 edge가 입력 시 더 경로가 작은 버스 이용
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if (node[u][v] > w)
			node[u][v] = w;
	}

	// 출발, 도착 도시 입력받기
	scanf("%d %d", &start, &end);

	value[start] = 0;
	pq.push(make_pair(0, start));

	// 다익스트리
	while (!pq.empty()) {
		int x = pq.top().first;
		int U = pq.top().second;
		pq.pop();

		for (int i = 1; i <= n; i++) {
			int V = i;
			int W = node[U][i];

			if (W == INF) continue;

			if (x + W < value[V]) {
				value[V] = x + W;
				pq.push(make_pair(x + W, V));
			}
		}
	}

	printf("%d", value[end]);

	return 0;
}