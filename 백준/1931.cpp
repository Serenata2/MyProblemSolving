#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_NUM 100000

using namespace std;

pair<int, int> meeting[MAX_NUM + 1];

int main() 
{
    int N;
    cin >> N;

    // 회의 시간 입력받기
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &meeting[i].second, &meeting[i].first);
    }

    // 회의가 끝나는 시간 기준으로 정렬
    sort(meeting + 1, meeting + N + 1);

    int ans = 0; // 사용할 수 있는 회의 개수
    int meeting_end = -1; // 마지막으로 사용한 회의의 끝나는 시간

    for (int i = 1; i <= N; i++) {
        if (meeting_end <= meeting[i].second) {
            meeting_end = meeting[i].first;
            ans++;
        }
    }

    cout << ans;

    return 0;
}