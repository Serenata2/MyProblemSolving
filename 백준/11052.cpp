#include <iostream>

#define MAX_NUM 10000

using namespace std;

int D[MAX_NUM + 1];     // D[i] : i개의 카드를 갖기 위해 지불해야하는 금액의 최댓값
int card[MAX_NUM + 1];  // 카드팩의 가격

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> card[i];
    }

    // 초기화
    D[1] = card[1];

    for (int i = 2; i <= N; i++) {
        D[i] = card[i];
        for (int j = i - 1; j > 0; j--) {
            D[i] = max(D[i], D[j] + D[i - j]);
        }
    }

    cout << D[N];

    return 0;
}
