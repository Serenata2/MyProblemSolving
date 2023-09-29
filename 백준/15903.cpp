#include <iostream>
#include <queue>

using namespace std;

// ������������ ���ĵǵ��� �켱���� ť�� �����.
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() 
{
    int N, M;
    cin >> N >> M;

    // �������� �Է¹ް� pq�� �ִ´�
    for (int i = 0; i < N; i++) {
        long long point;
        cin >> point;

        pq.push(point);
    }

    // m������ ���� ���� ���� 2���� �̾Ƽ� ��ü�Ѵ�.
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

    // ī���� �� ���ϱ�
    for (int i = 0; i < size; i++) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;

    return 0;
}