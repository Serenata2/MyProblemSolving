#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

bool InRange(int x, int y);

int N, M;
string treasure_map[50]; // 보물 지도
vector<pair<int, int> > land_arr; 

int main()
{
    cin >> N >> M;

    
    for (int i = 0; i < N; i++) {
        cin >> treasure_map[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (treasure_map[i][j] == 'L') {
                land_arr.push_back(make_pair(i, j));
            }
        }
    }

    int ans = -1;

    for (int i = 0; i < land_arr.size(); i++) {
        int max_step = 0;
        queue<pair<int, int> > q;
        vector<vector<bool> > visited(N, vector<bool>(M, 0));
        vector<vector<int> > step(N, vector<int>(M, 0));

        q.push(land_arr[i]);
        visited[land_arr[i].first][land_arr[i].second] = true;

        while (!q.empty()) {
            pair<int, int> curr_pos = q.front();
            int x = curr_pos.first;
            int y = curr_pos.second;
            q.pop();

            int dx[4] = { 1, -1, 0, 0 };
            int dy[4] = { 0, 0, 1, -1 };

            // 상하좌우 살펴보기
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (InRange(nx, ny) && treasure_map[nx][ny] == 'L' && !visited[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                    step[nx][ny] = step[x][y] + 1;
                    max_step = step[nx][ny];
                }
            }
        }

        ans = max(ans, max_step);
    }

    cout << ans;
    
    return 0;
}

bool InRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}