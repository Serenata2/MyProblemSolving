#include <iostream>

#define MAX_NUM 1000

using namespace std;

int box[MAX_NUM + 1];
// D[i] : i번째 상자를 마지막으로 넣을 때, 최대 상자의 개수
int D[MAX_NUM + 1];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> box[i];
    }

    // 초기화
    D[1] = 1;

    for (int i = 2; i <= n; i++) {
        int max_box = 0;
        // 이전 상자 중에서 크기가 작은 것 중에서
        // 가장 큰 D배열 값을 가지는 것 선택
        for (int j = i - 1; j > 0; j--) {
            if (box[j] < box[i] && max_box < D[j]) {
                max_box = D[j];
            }
        }
        D[i] = max_box + 1;
    }

    // D배열에서 최대값이 정답
    int ans = D[1];
    for (int i = 2; i <= n; i++) {
        ans = max(ans, D[i]);
    }

    cout << ans;

    return 0;
}