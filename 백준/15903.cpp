#include <iostream>
#include <queue>

using namespace std;

// 오름차순으로 정렬되도록 우선순위 큐를 만든다.
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() 
{
    int N, M;
    cin >> N >> M;

    // 점수들을 입력받고 pq에 넣는다
    for (int i = 0; i < N; i++) {
        long long point;
        cin >> point;

        pq.push(point);
    }

    // m번동안 가장 낮은 점수 2개를 뽑아서 합체한다.
    for (int i = 0; i < M; i++) {
        long long x, y;

        x = pq.top();
        pq.pop();

        y = pq.top();
        pq.pop();

        pq.push(x + y);
        pq.push(x + y);
    }

    long long ans = 0;
    int size = pq.size();

    // 카드의 합 구하기
    for (int i = 0; i < size; i++) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;

    return 0;
}