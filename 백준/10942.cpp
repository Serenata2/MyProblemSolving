#include <iostream>
#include <cstdio>

#define MAX_NUM 2000

using namespace std;

int arr[MAX_NUM + 1];
// D[s][e] : s번째 수부터 e번째 까지 수가 팬리드룸을 이루면 1, 아니면 0
int D[MAX_NUM + 1][MAX_NUM + 1];

int main()
{
    int N, M;
    cin >> N;
    
    // 수열 입력 받기 및 D배열 초기화
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        D[i][i] = 1;
    }

    for (int i = N - 1; i > 0; i--) {
        // i, i+1번째 수가 같은 경우에는 i ~ i+1 수는 팰린드룸
        if (arr[i] == arr[i + 1]) {
            D[i][i + 1] = 1;
        }

        for (int j = i + 2; j <= N; j++) {
            // i, j번째 수가 같으면 i+1 ~ j-1 수가 팰린드룸을 이루는지 확인한다.
            if (arr[i] == arr[j]) {
                D[i][j] = D[i + 1][j - 1];
            }
            // i, j번째 수가 같지 않으면 i ~ j 수는 팰린드룸을 이루지 않는다.
            else {
                D[i][j] = 0;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", D[s][e]);
    }

    return 0;
}