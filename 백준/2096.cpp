#include <iostream>
#include <cstdio>

#define MAX_NUM 100000

using namespace std;

// 내려가기 게임의 지도
int map[MAX_NUM + 1][3];

// 원래의 경우
// D[N][i][0] : N번줄, i열에 도착할 때 최대 점수
// D[N][i][1] : N번줄, i열에 도착할 때 최소 점수
// 하지만 메모리 제한에 따라 3차원의 크기를 2로 했다.
int D[2][3][2];

int main() 
{
    int N;
    cin >> N;

    // 지도 입력 받기
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int idx = 0;

    // D배열 초기화
    for (int i = 0; i < 3; i++) {
        D[idx][i][0] = map[1][i];
        D[idx][i][1] = map[1][i];
    }

    for (int i = 2; i <= N; i++, idx = (idx + 1) % 2) {
        // 다음에 초기화해야 할 idx 구하기
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