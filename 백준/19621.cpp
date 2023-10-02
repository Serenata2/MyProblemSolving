#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_NUM 25

using namespace std;

int back(int meeting_num);

int N;
pair<int, int> meeting[MAX_NUM + 1];
int people[MAX_NUM + 1]; // �� ���ÿ� �����ϴ� �ο�

// D[i] : i�� ȸ�Ǹ� ó������ �������� �� �ִ� ���� �ο�
int D[MAX_NUM + 1];

int main() 
{
    cin >> N;

    // ȸ�� �ð�, ȸ�� ���� �ο� �Է¹ޱ�
    for (int i = 1; i <= N; i++) {
        cin >> meeting[i].first >> meeting[i].second >> people[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, back(i));
    }

    cout << ans;

    return 0;
}

int back(int n)
{
    if (D[n]) {
        return D[n];
    }
    
    int max_people = 0;
    for (int i = 1; i <= N; i++) {
        if (i != n && meeting[n].second <= meeting[i].first) {
            max_people = max(max_people, back(i));
        }
    }

    D[n] = people[n] + max_people;
    return D[n];
}