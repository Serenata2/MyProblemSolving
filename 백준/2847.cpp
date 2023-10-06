#include <iostream>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

int point[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> point[i];
    }

    int ans = 0;
    for (int i = N - 1; i > 0; i--) {
        if (point[i] >=  point[i + 1]) {
            ans += (point[i] - point[i + 1]) + 1;
            point[i] = point[i + 1] - 1;
        }
    }

    cout << ans;

    return 0;
}