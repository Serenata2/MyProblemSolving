#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define N 4

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

bool inRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

int eat_fish(int fishes[][4], int dir[][4])
{
    int temp_fish[4][4];        // 정사각형칸에 물고기 번호 저장한 배열
    int temp_dir[4][4];         // 정사각형칸에 방향의 번호를 저장한 배열
    map<int, int > fish_num;    // key : 물고기번호, value : (x,y)좌표 -> 4 * x + y

    // 청소년 상어의 위치
    int teen_shark[2] = {0, 0};

    // 먼저 정사각형칸 배열 복사
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp_fish[i][j] = fishes[i][j];
            temp_dir[i][j] = dir[i][j];

            // 물고기가 존재하면 map에 저장
            if (fishes[i][j] > 0) {
                fish_num[fishes[i][j]] = 4 * i + j;
            }
            // 상어인 경우로 청소년 상어의 위치 update
            else if (fishes[i][j] < 0) {
                teen_shark[0] = i;
                teen_shark[1] = j;
            }
        }
    }

    // 물고기 번호가 작은 것부터 시작해서 물고기 이동 시작
    for (int i = 1; i <= 16; i++) {
        if (fish_num.find(i) != fish_num.end()) {
            int x = fish_num[i] / 4, y = fish_num[i] % 4;

            // 반시계 방향으로 돌면서 위치를 교환할 물고기 혹은 공간이 있나 확인
            for (int j = 0; j < 8; j++) {
                int nx = x + dx[(temp_dir[x][y] + j) % 8];
                int ny = y + dy[(temp_dir[x][y] + j) % 8];

                if (inRange(nx, ny) && temp_fish[nx][ny] >= 0) {
                    // 현재 물고기가 있는 칸의 방향 변경
                    temp_dir[x][y] = (temp_dir[x][y] + j) % 8;

                    // 방향 서로 교환
                    int temp = temp_dir[x][y];
                    temp_dir[x][y] = temp_dir[nx][ny];
                    temp_dir[nx][ny] = temp;

                    // 물고기 위치 교환
                    temp = temp_fish[x][y];
                    temp_fish[x][y] = temp_fish[nx][ny];
                    temp_fish[nx][ny] = temp;

                    // map 갱신
                    fish_num[temp] = 4 * nx + ny;

                    // 바뀐게 물고기끼리인 경우 추가로 map 갱신
                    if (temp_fish[x][y] > 0) {
                        fish_num[temp_fish[x][y]] = 4 * x + y;
                    }
                    break;
                }
            }
        }
    }

    // 청소년 상어가 이동할 수 있는 칸이 있는지 확인
    vector<int > possible_shark_pos;    // 청소년 상어가 이동할 수 있는 (x,y) -> 4 * x + y
    for (int i = 3; i >= 1; i--) {
        int nx = teen_shark[0] + i * dx[temp_dir[teen_shark[0]][teen_shark[1]]];
        int ny = teen_shark[1] + i * dy[temp_dir[teen_shark[0]][teen_shark[1]]];

        if (inRange(nx, ny) && temp_fish[nx][ny] > 0) {
            possible_shark_pos.push_back(4 * nx + ny);
        }

    }

    // 청소년 상어가 이동할 칸이 없는 경우
    if (possible_shark_pos.empty()) {
        return 0;
    }

    // 이동할 수 있는 칸 중에서 물고기 번호 합의 최댓값 찾기
    int max_fish = 0;   // 최대 물고기 번호 합
    temp_fish[teen_shark[0]][teen_shark[1]] = 0;    // 현재 상어가 있는 자리를 0으로 채움
    for (auto pos : possible_shark_pos) {
        int temp = temp_fish[pos / 4][pos % 4];     // 이동할 자리의 값을 미리 저장
        temp_fish[pos / 4][pos % 4] = -1;           // 이동할 자리의 값을 -1로 update
        max_fish = max(max_fish, eat_fish(temp_fish, temp_dir) + temp); // 재귀함수 호출
        temp_fish[pos / 4][pos % 4] = temp;         // 이동한 자리의 값 원래대로 복구
    }

    // 최대 물고기 번호 합 반환
    return max_fish;
}

int main() 
{
    int direction[N][N];            // 방향
    int fishes[N][N];               // 물고기 번호
    int teen_shark[2] = { 1, 1 };   // 청소년 상어의 위치

    // 공간 입력받기
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int fish_num, dir;
            cin >> fish_num >> dir;

            direction[i][j] = dir - 1;
            fishes[i][j] = fish_num;
        }
    }

    // 상어의 위치를 (0,0)으로 가정
    int ans = fishes[0][0];

    // 정사각판 배열에서 상어의 위치 값을 -1로 초기화
    fishes[0][0] = -1;

    // 재귀함수 호출
    ans = ans + eat_fish(fishes, direction);

    cout << ans;
    
    return 0;
}