#include <iostream>

#define MAX_NUM 100

using namespace std;

long long D[MAX_NUM + 1];

// 파도반 수열
int main() 
{
    D[1] = 1;
    D[2] = 1;
    D[3] = 1;

    for (int i = 4; i <= 100; i++) {
        D[i] = D[i - 2] + D[i - 3];
    }

    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << D[N] << endl;
    }

    return 0;
}