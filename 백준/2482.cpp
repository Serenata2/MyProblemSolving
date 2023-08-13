#include <iostream>

#define MAX_NUM 1000
#define DIVSION_NUM 1000000003

using namespace std;

// D[i][j] : i개의 색깔에서 규칙을 지키면서 j번 칠할 경우
// i가 N보다 작은 경우, 고리 모양이 아닌 선형의 형태로 생각하자
long long D[MAX_NUM + 1][MAX_NUM + 1];

int main()
{
    int N, K;
    cin >> N >> K;

    // 초기화
    for (int i = 1; i <= N; i++) {
        D[i][1] = (long long)i;
    }

    for (int j = 2; j <= K; j++) {
        if (2 * j - 1 <= N) {
            D[2 * j - 1][j] = 1;
        }

        for (int i = 2 * j; i <= N - 1; i++) {
            D[i][j] = (D[i - 1][j] + D[i - 2][j - 1]) % DIVSION_NUM;
        }

        // D[N - 3][j - 1] : N번째 칸을 칠하는 경우 
        //                   -> 2 ~ N - 2칸까지  j -1 번 칠하는 경우 == 1 ~ N - 3칸까지 j - 1번 칠하는 경우
        // D[N - 1][j] : N번째 칸을 칠하지 안흔ㄴ 경우
        D[N][j] = (D[N - 3][j - 1] + D[N - 1][j]) % DIVSION_NUM;
    }


    cout << D[N][K];

    return 0;
}