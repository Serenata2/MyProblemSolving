#include <iostream>

#define MAX_NUM 30

using namespace std;

// D[i][0] : i번째 벽까지 완벽하게 채우는 타일의 경우의 수
// D[i][1] : i번째 벽에서 위에서부터 2개의 2x1 크기의 타일이 칠해지는 경우
// D[i][2] : i번째 벽에서 아래부터 2개의 2x1 크기의 타일이 칠해지는 경우
int D[MAX_NUM + 1][3];

int main() {
    int N;
    cin >> N;

    // 초기화
    D[2][0] = 3;
    D[2][1] = 1;
    D[2][2] = 1;

    // 홀수번째는 채울 수 없기에 i를 2씩 증가시킨다.
    for (int i = 4; i <= N; i += 2) {
        D[i][0] = 3 * D[i - 2][0] + D[i - 2][1] + D[i - 2][2];
        D[i][1] = D[i - 2][0] + D[i - 2][1];
        D[i][2] = D[i - 2][0] + D[i - 2][2];
    }

    cout << D[N][0] << endl;

    return 0;
}