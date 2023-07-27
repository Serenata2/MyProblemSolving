#include <iostream>

#define MAX_NUM 1000000
#define DIVISION_NUM 15746

using namespace std;

long long D[MAX_NUM + 1];

int main() {
    int N;
    cin >> N;

    // √ ±‚»≠
    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= N; i++) {
        D[i] = (D[i - 1] + D[i - 2]) % DIVISION_NUM;
    }

    cout << D[N];

    return 0;
}