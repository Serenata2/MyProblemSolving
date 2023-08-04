#include <iostream>

#define MAX_NUM 100000
#define DIVISION_NUM 9901

using namespace std;

// D[i][0] : i번째 세로줄에서 사자를 배치않은 경우의 수
// D[i][1] : i번째 세로줄에 하나의 사자를 배치하는 경우의 수
int D[MAX_NUM + 1][2];

int main() {
    int N;
    cin >> N;

    // 초기화
    D[1][0] = 1;
    D[1][1] = 2;

    for (int i = 2; i <= N; i++) {
        D[i][0] = (D[i - 1][0] + D[i - 1][1]) % DIVISION_NUM;
        D[i][1] = (2 * D[i - 1][0] + D[i - 1][1]) % DIVISION_NUM;
    }

    cout << (D[N][0] + D[N][1]) % DIVISION_NUM;

    return 0;
}