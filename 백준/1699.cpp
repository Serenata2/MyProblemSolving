#include <iostream>
#include <climits>
#include <cmath>

#define MAX_NUM 100000

using namespace std;

// D[i] : i를 제곱수들의 합으로 표현할 때 그 항의 최소개수
int D[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= N; i++) {
        D[i] = INT_MAX;
        // root변수는 i보다 작은 제곱수 중 가장 큰 것
        int root = (int)sqrt((double)(i));

        // 이후 i를 표현할 때 가장 적은 항의 개수를 찾기
        for (int j = root; j > root / 2; j--) {
            int pow_n = (int)pow((double)j, 2);
            D[i] = min(D[i], D[i - pow_n] + 1);
        }
    }

    cout << D[N];

    return 0;
}
