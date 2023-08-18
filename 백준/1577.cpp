#include <iostream>

#define MAX_NUM 100

using namespace std;

// D[i][j] : (0,0)에서 (i, j)까지 갈 수 있는 경우의 수
long long D[MAX_NUM + 1][MAX_NUM + 1];

// roadwork[i][j][0] : (i, j) ~ (i+1, j) 도로에서 공사가 진행중이면 true
// roadwork[i][j][1] : (i, j) ~ (i, j+1) 도로에서 공사가 진행중이면 true
bool roadwork[MAX_NUM + 1][MAX_NUM + 1][2];

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == c) {
            roadwork[a][min(b, d)][1] = true;
        }
        else {
            roadwork[min(a, c)][b][0] = true;
        }
    }

    // y = 0에서 x축으로만 이동할 때 경우의 수 초기화
    D[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        if (roadwork[i - 1][0][0] == true) {
            break;
        }
        D[i][0] = 1;
    }

    // 나머지 D배열 채우기
    for (int j = 1; j <= M; j++) {
        // x = 0에서 y축으로만 이동할 때 경우의 수 따로 초기화
        if (D[0][j - 1] == 0 || roadwork[0][j - 1][1] == true) {
            D[0][j] = 0;
        }
        else {
            D[0][j] = 1;
        }

        for (int i = 1; i <= N; i++) {
            if (roadwork[i-1][j][0] == false) {
                D[i][j] += D[i - 1][j];
            }

            if (roadwork[i][j-1][1] == false) {
                D[i][j] += D[i][j - 1];
            }
        }
    }

    cout << D[N][M];
    
    return 0;
}