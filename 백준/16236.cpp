#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define MAX_NUM 20

using namespace std;

int N, ans;
int sea[MAX_NUM + 1][MAX_NUM + 1];
// �Ʊ� ����� x��ǥ, y��ǥ, ũ��, ���� Ƚ��
int baby_shark[4] = { 0, 0, 2, 0};


// bfs�� �ʿ��� ������ �Դϴ�.
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
        // queue���� ���� ���� ���� ���Ҹ� ���ϴ�.
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        // �ּҰŸ����� �� ���� �ִ� ��ġ�� ���
        if (min_time < steps[x][y]) {
            continue;
        }
        // ������ �ּҰŸ��� �ִ� ����⸦ ���� ���
        else if (min_time == steps[x][y] && sea[x][y] != 0 && sea[x][y] < baby_shark[2]) {
            fishes.push_back(make_pair(x, y));
            continue;
        }

        // �ּҰŸ��� �ִ� ����⸦ ó�� ���� ���
        if (min_time == INT_MAX && sea[x][y] != 0 && sea[x][y] < baby_shark[2]) {
            min_time = steps[x][y];
            fishes.push_back(make_pair(x, y));
            continue;
        }

        int dx[4] = { 0, -1, 1, 0 };
        int dy[4] = { 1, 0, 0, -1 };

        // queue���� �� ������ ��ġ�� �������� 4������ Ȯ���غ��ϴ�.
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
        // x���� ���� �����鼭�� y���� ���� ���� ����� ����
        sort(fishes.begin(), fishes.end());
        int x = fishes[0].first;
        int y = fishes[0].second;

        // ����� ���� Ƚ�� �ø���
        baby_shark[3]++;

        // �ڽ��� ũ��� ���� ���� ����⸦ ���� ���
        if (baby_shark[2] == baby_shark[3]) {
            baby_shark[3] = 0;
            baby_shark[2]++;
        }
        
        sea[x][y] = 0;      // ����� ���� �ڸ��� 0���� ä���
        baby_shark[0] = x;  // �Ʊ� ��� ��ġ ����
        baby_shark[1] = y;
        ans += min_time;    // ����� �ð� �����ֱ�

        return true;        // ����⸦ ���� ���
    }

    return false;           // �� �̻� ���� �� �ִ� ����Ⱑ ������ ���� ���
}

// BFS�� ���� �迭���� �ʱ�ȭ���ִ� �Լ�
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

    // �ٴ��� ���� �Է¹ޱ�
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> sea[i][j];

            // �Ʊ� ��� ó�� ��ġ �Է�
            if (sea[i][j] == 9) {
                baby_shark[0] = i;
                baby_shark[1] = j;
                sea[i][j] = 0;
            }
        }
    } 

    while (1) {
        // �Ʊ� ����� ó�� ��ġ�� ť�� �ֱ�
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