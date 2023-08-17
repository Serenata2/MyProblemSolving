#include <iostream>
#include <queue>
#include <vector>

#define MAX_NUM 100000

using namespace std;

// ��������Ʈ�� Ʈ�� ǥ���ϱ�
vector<pair<int, int> > g[MAX_NUM + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int node1, node2, edge;
        cin >> node1 >> node2 >> edge;

        g[node1].push_back(make_pair(node2, edge));
        g[node2].push_back(make_pair(node1, edge));
    }

    int max_dis = 0;
    // ��Ʈ ��忡������ BFS ����
    int max_node = 1;

    // ��Ʈ ��忡�� ���� ����ġ�� �� ��� x�� ã��
    // x��忡�� ���� ����ġ�� �� ��� y�� ã�´�.
    // x, y ��� ������ ����ġ���� Ʈ���� �����̴�.
    for (int i = 0; i < 2; i++) {
        max_dis = 0;
        queue<int> q;
        vector<bool> visited(MAX_NUM + 1, false);
        vector<int> distance(MAX_NUM + 1, 0);

        q.push(max_node);
        visited[max_node] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < g[node].size(); j++) {
                int active_node = g[node][j].first;

                if (visited[active_node] == false) {
                    q.push(active_node);
                    visited[active_node] = true;
                    distance[active_node] = distance[node] + g[node][j].second;

                    if (max_dis < distance[active_node]) {
                        max_dis = distance[active_node];
                        max_node = active_node;
                    }
                }
            }
        }
    }

    cout << max_dis << endl;
    
    return 0;
}