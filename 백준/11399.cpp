#include <iostream>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

int P[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    sort(P + 1, P + 1 + N);

    int ans = 0;

    // 오름차순으로 정렬해서
    // 인출시간이 짧은 순서대로 돈을 인출하도록 한다.
    for (int i = 1; i <= N; i++) {
        ans += (N - i + 1) * P[i];
    }

    cout << ans;

    return 0;
}