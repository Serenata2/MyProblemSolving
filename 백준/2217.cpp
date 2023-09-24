#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_NUM 100000

using namespace std;

int rope[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        scanf("%d", &rope[i]);
    }

    // 각 로프가 버틸 수 있는 중량을 오름차순으로 정렬
    sort(rope, rope + N);

    int ans = 0;

    // 모든 케이스에 대해서 점검
    for (int i = 0; i < N; i++) {
        ans = max(ans, (N - i) * rope[i]);
    }

    cout << ans;

    return 0;
}