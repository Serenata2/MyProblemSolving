#include <iostream>
#include <cstdio>

#define MAX_NUM 100000

using namespace std;

// �������� ������ ����
int map[MAX_NUM + 1][3];

// ������ ���
// D[N][i][0] : N����, i���� ������ �� �ִ� ����
// D[N][i][1] : N����, i���� ������ �� �ּ� ����
// ������ �޸� ���ѿ� ���� 3������ ũ�⸦ 2�� �ߴ�.
int D[2][3][2];

int main() 
{
    int N;
    cin >> N;

    // ���� �Է� �ޱ�
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int idx = 0;

    // D�迭 �ʱ�ȭ
    for (int i = 0; i < 3; i++) {
        D[idx][i][0] = map[1][i];
        D[idx][i][1] = map[1][i];
    }

    for (int i = 2; i <= N; i++, idx = (idx + 1) % 2) {
        // ������ �ʱ�ȭ�ؾ� �� idx ���ϱ�
        int next_idx = (idx + 1) % 2;

        D[next_idx][0][0] = max(D[idx][0][0], D[idx][1][0]);
        D[next_idx][0][1] = min(D[idx][0][1], D[idx][1][1]);

        D[next_idx][2][0] = max(D[idx][1][0], D[idx][2][0]);
        D[next_idx][2][1] = min(D[idx][1][1], D[idx][2][1]);

        D[next_idx][1][0] = max(D[next_idx][0][0], D[next_idx][2][0]);
        D[next_idx][1][1] = min(D[next_idx][0][1], D[next_idx][2][1]);

        for (int j = 0; j < 3; j++) {
            D[next_idx][j][0] += map[i][j];
            D[next_idx][j][1] += map[i][j];
        }
    } 

    cout << max(D[idx][0][0], max(D[idx][1][0], D[idx][2][0])) << " ";
    cout << min(D[idx][0][1], min(D[idx][1][1], D[idx][2][1]));

    return 0;
}