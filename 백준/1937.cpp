#include <iostream>

#define MAX_NUM 500

using namespace std;

int N;
int bamboo_forest[MAX_NUM + 1][MAX_NUM + 1];

// D[i][j] : (i,j)칸에서 판다가 최대한 많이 이동할 수 있는 칸의 수
int D[MAX_NUM + 1][MAX_NUM + 1];

int Find_D(int i, int j);
bool In_Range(int i, int j);

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> bamboo_forest[i][j];
        }
    }

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans = max(Find_D(i, j), ans);
        }
    }

    cout << ans;

    return 0;
}

int Find_D(int i, int j)
{
    // 이미 (i,j)칸에서 이동할 수 있는 칸의 수를 구한 경우
    if (D[i][j] > 0) {
        return D[i][j];
    }

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    // 상,하,좌,우 중 가장 많이 이동할 수 있는 경우를 찾는다
    for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if (In_Range(nx, ny) && bamboo_forest[nx][ny] > bamboo_forest[i][j]) {
            D[i][j] = max(Find_D(nx, ny), D[i][j]);
        }
    }

    // (i,j)칸에서 시작하므로 +1을 한다.
    D[i][j] += 1;

    return D[i][j];
}

bool In_Range(int i, int j)
{
    return 1 <= i && i <= N && 1 <= j && j <= N;
}