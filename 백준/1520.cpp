#include <iostream>

#define MAX_NUM 500

using namespace std;

int N, M;
int arr[MAX_NUM + 1][MAX_NUM + 1]; // ���� ����

// D[i][j] : (i,j)���� (N,M)���� �� �� �ִ� ����� ��
long long D[MAX_NUM + 1][MAX_NUM + 1];

// (i, j) ��ǥ �������� Ž���� ��� visited[i][j] = true
bool visited[MAX_NUM + 1][MAX_NUM + 1];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

long long DFS(int i, int j);
bool In_Range(int i, int j);

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    // ����Լ��� ���� DFS
    DFS(1, 1);

    cout << D[1][1];

    return 0;
}

long long DFS(int i, int j)
{
    // �������� ���
    if (i == N && j == M) {
        return 1;
    }

    // �湮�� ���� ���� ���
    // 4���� ���⿡ ���ؼ� �� �� �ִ� ��� DFS ������
    if (!visited[i][j]) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = i + dx[dir];
            int ny = j + dy[dir];

            if (In_Range(nx, ny) && (arr[i][j] > arr[nx][ny])) {
                D[i][j] += DFS(nx, ny);
            }
        }

        visited[i][j] = true;
    }

    return D[i][j];
}

bool In_Range(int i, int j)
{
    return i >= 1 && i <= N && j >= 1 && j <= M;
}