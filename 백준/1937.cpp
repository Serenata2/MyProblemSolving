#include <iostream>

#define MAX_NUM 500

using namespace std;

int N;
int bamboo_forest[MAX_NUM + 1][MAX_NUM + 1];

// D[i][j] : (i,j)ĭ���� �Ǵٰ� �ִ��� ���� �̵��� �� �ִ� ĭ�� ��
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
    // �̹� (i,j)ĭ���� �̵��� �� �ִ� ĭ�� ���� ���� ���
    if (D[i][j] > 0) {
        return D[i][j];
    }

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    // ��,��,��,�� �� ���� ���� �̵��� �� �ִ� ��츦 ã�´�
    for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if (In_Range(nx, ny) && bamboo_forest[nx][ny] > bamboo_forest[i][j]) {
            D[i][j] = max(Find_D(nx, ny), D[i][j]);
        }
    }

    // (i,j)ĭ���� �����ϹǷ� +1�� �Ѵ�.
    D[i][j] += 1;

    return D[i][j];
}

bool In_Range(int i, int j)
{
    return 1 <= i && i <= N && 1 <= j && j <= N;
}