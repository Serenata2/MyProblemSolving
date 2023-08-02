#include <iostream>

#define MAX_NUM 1000

using namespace std;

bool D[MAX_NUM + 1];

int main() {
    int N;
    cin >> N;

    D[1] = true;
    D[3] = true;

    for (int i = 4; i <= N; i++) {
        D[i] = (!D[i - 1] || !D[i - 3]);
    }

    if (D[N]) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }

    return 0;
}