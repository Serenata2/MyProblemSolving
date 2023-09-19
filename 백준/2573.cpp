#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

#define MAX_NUM 300

using namespace std;

int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int iceberg[MAX_NUM + 1][MAX_NUM + 1];
int cpy_iceberg[MAX_NUM + 1][MAX_NUM + 1];
vector<vector<bool> > visited(MAX_NUM + 1, vector<bool>(MAX_NUM + 1, false));

void BFS(int x, int y) 
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        pair<int, int> source = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = source.first + dx[dir];
            int ny = source.second + dy[dir];

            // 빙산이 존재하는 경우 이동하기
            if (iceberg[nx][ny] > 0 && !visited[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

void melt()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // 빙산인 경우
            if (iceberg[i][j] > 0) {
                int melt_num = 0;

                // 4 방향에 대해서 바닷물이 있는 지 검사
                for (int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];

                    if (iceberg[x][y] == 0) {
                        melt_num++;
                    }
                }

                if (iceberg[i][j] - melt_num < 0) {
                    cpy_iceberg[i][j] = 0;
                }
                else {
                    cpy_iceberg[i][j] = iceberg[i][j] - melt_num;
                }
            }
        }
    }

    // 녹인 빙산이 적용된 cpy_iceberg를 iceberg로 복사
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            iceberg[i][j] = cpy_iceberg[i][j];
        }
    }
}
int main() 
{
    cin >> N >> M;

    // 빙산 입력 받기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &iceberg[i][j]);
        }
    }

    int ans = 0;
    while (true) {
        int count = 0;

        // visited 배열 false로 다시 채워 넣기
        fill(visited.begin(), visited.end(), vector<bool>(MAX_NUM + 1, false));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (iceberg[i][j] && !visited[i][j]) {
                    count++;
                    if (count >= 2) {
                        break;
                    }
                    BFS(i, j);
                }
            }
        }

        if (count >= 2) {
            break;
        }
        if (count == 0) {
            ans = 0;
            break;
        }

        melt();
        ans++;
    }

    cout << ans;

    return 0;
}