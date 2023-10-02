#include <iostream>
#include <algorithm>

#define MAX_NUM 100000

using namespace std;

int N;
pair<int, int> meeting[MAX_NUM + 1];
int people[MAX_NUM + 1]; // 각 미팅에 참여하는 인원

// D[i] : i ~ N번 회의까지 고려해서 최대 참여인원
int D[MAX_NUM + 2];

int main() 
{
    cin >> N;

    // 회의 시간, 회의 참여 인원 입력받기
    for (int i = 1; i <= N; i++) {
        cin >> meeting[i].first >> meeting[i].second >> people[i];
    }

    // sort(meeting + 1, meeting + N + 1);
    D[N] = people[N];

    for (int i = N - 1; i > 0; i--) {
        if (meeting[i + 1].first < meeting[i].second) {
            D[i] = max(people[i] + D[i + 2], D[i+1]);
        }
        else {
            D[i] = people[i] + D[i + 1];
        }
    }

    cout << D[1];

    return 0;
}