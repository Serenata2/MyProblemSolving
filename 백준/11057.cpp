#include <iostream>

#define MAX_NUM 1000
#define DIVSION_NUM 10007

using namespace std;

// D[i][j] : j로 끝나고 i 길이인 수 중에서 오름차순을 이루는 수의 개수
int D[MAX_NUM + 1][10];     

int main() {
    int N;
    cin >> N;

    // N = 1일 때 초기화
    for (int i = 0; i < 10; i++) {
        D[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        D[i][0] = 1;
        for (int j = 1; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                D[i][j] = (D[i][j] + D[i - 1][k]) % DIVSION_NUM;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + D[N][i]) % DIVSION_NUM;
    }
    
    cout << ans;

    return 0;
}
