#include <iostream>

#define MAX_NUM 1000
#define DIVSION_NUM 1000000003

using namespace std;

// D[i][j] : i번 색까지 고려해서 규칙을 지키면서 j번 칠할 경우
long long D[MAX_NUM + 1][MAX_NUM + 1];

int main()
{
    int N, K;
    cin >> N >> K;

    // 1번 색칠할 때 D 배열 초기화
    for (int i = 1; i <= N; i++) {
        D[i][1] = (long long)i;
    }

    for (int j = 2; j <= K; j++) {
        // j번 칠하기 위해서는 최소한 2 * j - 1개의 색이 필요하다
        if (2 * j - 1 <= N) {
            D[2 * j - 1][j] = 1;
        }

        // i(2*j <= i <= N - 1)번 색까지 고려해서 j번 칠하는 경우
        for (int i = 2 * j; i <= N - 1; i++) {
            D[i][j] = (D[i - 1][j] + D[i - 2][j - 1]) % DIVSION_NUM;
        }

        // N번 색까지 고려해서 j번 칠하는 경우
        D[N][j] = (D[N - 1][j] + D[N - 3][j - 1]) % DIVSION_NUM;
    }

    cout << D[N][K];

    return 0;
}