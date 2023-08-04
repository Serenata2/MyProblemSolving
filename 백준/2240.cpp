#include <iostream>

#define MAX_NUM 1000

using namespace std;

// D[i][j] : i초까지 j번 움직였을 때 받을 수 있는 최대 자두의 수
int D[MAX_NUM + 1][31];
int drop[MAX_NUM + 1];

int main() {
    int T, W;
    cin >> T >> W;
    
    for (int i = 1; i <= T; i++) {
        cin >> drop[i];

        // 자리를 움직이지 않았을 때의 값(D[i][0]) 초기화
        D[i][0] = D[i - 1][0] + drop[i] % 2;
    }

    for (int i = 1; i <= T; i++) {

        for (int j = 1; j <= W && j <= i; j++) {
            // i초에 나무 1에서 자두가 떨어지는 경우
            if (drop[i] == 1) {
                // j번 이동했을 때 나무 1에 위치한 경우
                if (j % 2 == 0) {            
                    // 두 값 중 더 큰 것을 선택
                    // 1. i-1초에서 j번 이동했을 때 최대 자두 수 + 1
                    // 2. i-1초에서 j-1번 이동했고, i초에서 이동했을 때 + 1
                    D[i][j] = max(D[i - 1][j], D[i-1][j-1]) + 1;
                }
                // j번 이동했을 떄 나무 2에 위치한 경우
                else {           
                    // i초에서는 결국 자두를 못 받기에 D[i-1][j]로 할당
                    D[i][j] = D[i - 1][j];
                }
            }
            // i초에 나무 2에서 자두가 떨어지는 경우
            else {
                if (j % 2 == 0) {
                    D[i][j] = D[i - 1][j];
                }
                else {
                    D[i][j] = max(D[i - 1][j], D[i - 1][j - 1]) + 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, D[T][i]);
    }

    cout << ans;

    return 0;
}