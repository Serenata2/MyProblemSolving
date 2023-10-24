#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define MAX_NUM 20

using namespace std;

int N, ans;
int sea[MAX_NUM + 1][MAX_NUM + 1];
// 아기 상어의 x좌표, y좌표, 크기, 먹은 횟수
int baby_shark[4] = { 0, 0, 2, 0};


// bfs에 필요한 변수들 입니다.
queue<pair<int, int> > q;
bool visited[MAX_NUM + 1][MAX_NUM + 1];
int steps[MAX_NUM + 1][MAX_NUM + 1];

bool inRange(int x, int y) 
{
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

bool BFS() 
{
    int min_time = INT_MAX;
    vector<pair<int, int>> fishes;

    while (!q.empty()) {
        // queue에서 가장 먼저 들어온 원소를 뺍니다.
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        // 최소거리보다 먼 곳에 있는 위치의 경우
        if (min_time < steps[x][y]) {
            continue;
        }
        // 동일한 최소거리에 있는 물고기를 구한 경우
        else if (min_time == steps[x][y] && sea[x][y] != 0 && sea[x][y] < baby_shark[2]) {
            fishes.push_back(make_pair(x, y));
            continue;
        }

        // 최소거리에 있는 물고기를 처음 구한 경우
        if (min_time == INT_MAX && sea[x][y] != 0 && sea[x][y] < baby_shark[2]) {
            min_time = steps[x][y];
            fishes.push_back(make_pair(x, y));
            continue;
        }

        int dx[4] = { 0, -1, 1, 0 };
        int dy[4] = { 1, 0, 0, -1 };

        // queue에서 뺀 원소의 위치를 기준으로 4방향을 확인해봅니다.
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (inRange(nx, ny) && !visited[nx][ny] && sea[nx][ny] <= baby_shark[2]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                steps[nx][ny] = steps[x][y] + 1;
            }
        }
    }

    if (min_time != INT_MAX) {
        // x값이 가장 작으면서도 y값이 가장 작은 물고기 선택
        sort(fishes.begin(), fishes.end());
        int x = fishes[0].first;
        int y = fishes[0].second;

        // 물고기 먹은 횟수 늘리기
        baby_shark[3]++;

        // 자신의 크기와 같은 수의 물고기를 먹은 경우
        if (baby_shark[2] == baby_shark[3]) {
            baby_shark[3] = 0;
            baby_shark[2]++;
        }
        
        sea[x][y] = 0;      // 물고기 먹은 자리를 0으로 채우기
        baby_shark[0] = x;  // 아기 상어 위치 변경
        baby_shark[1] = y;
        ans += min_time;    // 흘려간 시간 더해주기

        return true;        // 물고기를 먹은 경우
    }

    return false;           // 더 이상 먹을 수 있는 물고기가 공간에 없는 경우
}

// BFS를 위한 배열들을 초기화해주는 함수
void reset_arr()
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = false;
            steps[i][j] = 0;
        }
    }
}

int main() 
{
    cin >> N;

    // 바다의 공간 입력받기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> sea[i][j];

            // 아기 상어 처음 위치 입력
            if (sea[i][j] == 9) {
                baby_shark[0] = i;
                baby_shark[1] = j;
                sea[i][j] = 0;
            }
        }
    } 

    while (1) {
        // 아기 상어의 처음 위치를 큐에 넣기
        q.push(make_pair(baby_shark[0], baby_shark[1]));
        visited[baby_shark[0]][baby_shark[1]] = true;

        if (BFS()) {
            reset_arr();
        }
        else {
            break;
        }
    }

    cout << ans;

    return 0;
}