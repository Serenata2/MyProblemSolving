#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define MAX_NUM 20

using namespace std;

// 위, 아래, 왼쪽, 오른쪽
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, K;
int smell[MAX_NUM][MAX_NUM][2]; // smell[i][j][0] : 상어의 번호, sea[i][j][1] : 냄새의 남은 시간 
int sharks[MAX_NUM][MAX_NUM];   // 바다 속 상어의 위치 배열
int shark_move[MAX_NUM * MAX_NUM + 1][4][4];    // 상어의 움직임의 우선순위
int shark_heading[MAX_NUM * MAX_NUM + 1];       // 현재 상어의 진행방향

bool inRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() 
{
    int h;
    // N : 격자의 길이, M : 상어 수, K : 냄새의 remain 초
    cin >> N >> M >> K;

    // 바다 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sharks[i][j];

            // 상어인 경우 냄새 남기기
            if (sharks[i][j] > 0) {
                smell[i][j][0] = sharks[i][j];
                smell[i][j][1] = K;
            }
        }
    }

    // 상어의 방향 입력 받기
    for (int i = 1; i <= M; i++) {
        cin >> h;
        shark_heading[i] = h - 1;
    }

    // 각 상어의 우선순위 입력 받기
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> h;
                shark_move[i][j][k] = h - 1;
            }
        }
    }

    int ans = 0;
    while(M > 1){
        // 1000초를 넘긴 경우
        if (ans >= 1000) {
            ans = -1;
            break;
        }

        // 상어가 동시에 이동했을 때의 바다 상태를 저장할 배열
        // 상어만 저장
        vector<vector<int> > temp_sharks(N, vector<int> (N, 0));

        // 바다를 둘러보면서 상어들 이동시키기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 상어의 경우
                if (sharks[i][j] > 0) {
                    int shark_num = sharks[i][j];           // 상어 번호
                    int heading = shark_heading[shark_num]; // 현재 상어가 보는 방향
                    int x = 0, y = 0;                       // 최종적으로 이동할 위치
                    bool flag = true;           // 처음 자신의 냄새를 뿌린 칸을 찾는 변수

                    // 현재 바라보는 방향에서의 우선순위에 따라 이동할 수 있는지 보기
                    for (int k = 0; k < 4; k++) {
                        int dir = shark_move[shark_num][heading][k];
                        int nx = i + dx[dir], ny = j + dy[dir];

                        if (inRange(nx, ny)) {
                            // 자신의 냄새인 경우
                            if (smell[nx][ny][0] == shark_num && flag) {
                                shark_heading[shark_num] = dir;
                                x = nx, y = ny;
                                flag = false;
                            }
                            // 갈 수 있는 경우
                            else if (smell[nx][ny][1] == 0) {
                                shark_heading[shark_num] = dir;
                                x = nx, y = ny;
                                break;
                            }
                        }
                    }

                    // 상어가 이미 존재하는 경우
                    if (temp_sharks[x][y] > 0) {
                        // 강한 상어가 살아남기
                        temp_sharks[x][y] = min(temp_sharks[x][y], shark_num);
                        M--;
                    }
                    else {
                        temp_sharks[x][y] = shark_num;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sharks[i][j] = temp_sharks[i][j];

                // 상어가 있는 경우
                if (sharks[i][j] > 0) {
                    smell[i][j][0] = sharks[i][j];
                    smell[i][j][1] = K;
                }
                // 냄새의 남은 시간 줄이기
                else if(smell[i][j][1] > 0){
                    smell[i][j][1] -= 1;
                    if (smell[i][j][1] == 0) {
                        smell[i][j][0] = 0;
                    }
                }
            }
        }

        ans++;
    }

    
    cout << ans;

    return 0;
}