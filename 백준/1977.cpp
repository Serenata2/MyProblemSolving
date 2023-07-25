#include <iostream>

#define MAX_NUM 100

using namespace std;

int D[MAX_NUM + 1][MAX_NUM + 1];
int M[MAX_NUM + 1][MAX_NUM + 1];

int main() {
    int N, M;

    cin >> M >> N;

    int sum = 0;
    int min = -1;

    for (int i = 1; i <= 100; i++) {
        if (i * i <= N) {
            if (i * i >= M) {
                sum += i * i;
                if (min < 0) {
                    min = i * i;
                }
            }
        }
        else {
            break;
        }
    }

    if (min < 0) {
        cout << -1;
    }
    else {
        cout << sum << endl << min;
    }

    return 0;
}