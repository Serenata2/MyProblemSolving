#include <iostream>
#include <vector>
#include <cstdio>

#define MAX_NUM 50

using namespace std;

int N, M, K;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int direction[2][4] = { { 0, 2, 4, 6 }, { 1, 3, 5, 7 } };

int map[MAX_NUM][MAX_NUM][4];
int temp_m[MAX_NUM][MAX_NUM][4];

int dir_sum[MAX_NUM][MAX_NUM][2];
int temp_dir_sum[MAX_NUM][MAX_NUM][2];

void move(int x, int y, int m, int s, int dir)
{
    int nx = ((x + s * dx[dir]) % N + N) % N;
    int ny = ((y + s * dy[dir]) % N + N) % N;

    temp_m[nx][ny][0] += m; // ���� plus
    temp_m[nx][ny][1] += s; // �ӵ� plus
    temp_m[nx][ny][2] = dir;

    // ���̾�� ù ��°�� �� ������ ���
    if (temp_m[nx][ny][3] == 0) {
        // dir_sum[nx][ny][1]�� ���̾�� ������ ¦���̸� 0, Ȧ���̸� 1 �ֱ�
        temp_dir_sum[nx][ny][1] = dir % 2;
    }
    else {
        // �������� ���̾�� ������ ��� Ȧ���̰ų� ¦���� �ƴ� ���
        if (temp_dir_sum[nx][ny][0] == 0 && temp_dir_sum[nx][ny][1] != dir % 2) {
            temp_dir_sum[nx][ny][0] = 1;
        }
    }
    temp_m[nx][ny][3]++;
}

int main() 
{
    // N : ���� ũ��, M : ���̾ ����, K : ��â Ƚ��
    cin >> N >> M >> K;


    // ���̾ �Է¹ޱ�
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;

        map[r-1][c-1][0] = m;   // ����
        map[r-1][c-1][1] = s;   // �ӵ�
        map[r-1][c-1][2] = d;   // ����
        map[r-1][c-1][3] = 1;   // ���̾ ����
    }


    // K�� ���̾ ��â�ϱ�
    while (K > 0) {

        // ��� ���̾ �̵�
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                
                int m = map[i][j][0], s = map[i][j][1], d = map[i][j][2];
                int counts = map[i][j][3];

                // ���̾�� ���
                if (m > 0) {
                    // �ϳ��� ���̾�� ���
                    if (counts == 1) {
                        move(i, j, m, s, d);
                    }
                    // 2�� �̻� ������ ���̾
                    else {
                        m = (int)(m / 5);   // ����
                        
                        // ������ 0���� �� ���̾�� ���
                        if (m <= 0) {
                            continue;
                        }

                        s = (int)(s / map[i][j][3]);    // �ӵ�

                        int idx = 0;    
                        // �������� ���̾�� ������ �� Ȧ��, ¦���� �ƴ� ���
                        if (dir_sum[i][j][0] == 1) {
                            idx = 1;
                        }
                        
                        // �������� 4���� ���̾ �̵�
                        for (int k = 0; k < 4; k++) {
                            move(i, j, m, s, direction[idx][k]);
                        }
                    }
                }   
            }
        }

        
        // �迭 ����
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 2; k++) {
                    dir_sum[i][j][k] = temp_dir_sum[i][j][k];
                    temp_dir_sum[i][j][k] = 0;
                }

                for (int k = 0; k < 4; k++) {
                    map[i][j][k] = temp_m[i][j][k];
                    temp_m[i][j][k] = 0;
                }
            }
        }

        K--;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int m = map[i][j][0], s = map[i][j][1], d = map[i][j][2];
            int counts = map[i][j][3];

            // ���̾�� ���
            if (m > 0) {
                // �ϳ��� ���̾�� ���
                if (counts == 1) {
                    ans += m;
                }
                // �ΰ� �̻��� ���̾�� ���
                else {
                    ans += (int)(m / 5) * 4;
                }
            }
        }
    }

    cout << ans;

    return 0;
}