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

    temp_m[nx][ny][0] += m; // 질량 plus
    temp_m[nx][ny][1] += s; // 속도 plus
    temp_m[nx][ny][2] = dir;

    // 파이어볼이 첫 번째로 간 공간인 경우
    if (temp_m[nx][ny][3] == 0) {
        // dir_sum[nx][ny][1]에 파이어볼의 방향이 짝수이면 0, 홀수이면 1 넣기
        temp_dir_sum[nx][ny][1] = dir % 2;
    }
    else {
        // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 짝수가 아닌 경우
        if (temp_dir_sum[nx][ny][0] == 0 && temp_dir_sum[nx][ny][1] != dir % 2) {
            temp_dir_sum[nx][ny][0] = 1;
        }
    }
    temp_m[nx][ny][3]++;
}

int main() 
{
    // N : 격자 크기, M : 파이어볼 개수, K : 영창 횟수
    cin >> N >> M >> K;


    // 파이어볼 입력받기
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;

        map[r-1][c-1][0] = m;   // 질랑
        map[r-1][c-1][1] = s;   // 속도
        map[r-1][c-1][2] = d;   // 방향
        map[r-1][c-1][3] = 1;   // 파이어볼 개수
    }


    // K번 파이어볼 영창하기
    while (K > 0) {

        // 모든 파이어볼 이동
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                
                int m = map[i][j][0], s = map[i][j][1], d = map[i][j][2];
                int counts = map[i][j][3];

                // 파이어볼의 경우
                if (m > 0) {
                    // 하나의 파이어볼인 경우
                    if (counts == 1) {
                        move(i, j, m, s, d);
                    }
                    // 2개 이상 뭉쳐진 파이어볼
                    else {
                        m = (int)(m / 5);   // 질량
                        
                        // 질량이 0으로 된 파이어볼인 경우
                        if (m <= 0) {
                            continue;
                        }

                        s = (int)(s / map[i][j][3]);    // 속도

                        int idx = 0;    
                        // 합쳐지는 파이어볼의 방향이 다 홀수, 짝수가 아닌 경우
                        if (dir_sum[i][j][0] == 1) {
                            idx = 1;
                        }
                        
                        // 나누어진 4개의 파이어볼 이동
                        for (int k = 0; k < 4; k++) {
                            move(i, j, m, s, direction[idx][k]);
                        }
                    }
                }   
            }
        }

        
        // 배열 복사
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

            // 파이어볼인 경우
            if (m > 0) {
                // 하나의 파이어볼인 경우
                if (counts == 1) {
                    ans += m;
                }
                // 두개 이상의 파이어볼인 경우
                else {
                    ans += (int)(m / 5) * 4;
                }
            }
        }
    }

    cout << ans;

    return 0;
}