#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

int main()
{
    vector<pair<int, int>> v;
    
    for (int i = 1; i <= 8; i++) {
        int point;
        cin >> point;
        v.push_back(make_pair(point, i));
    }

    // 점수를 기준으로 오름차순으로 정렬
    sort(v.begin(), v.end());

    // 문제 번호를 기준으로 오름차순으로 정렬
    sort(v.begin() + 3, v.end(), compare);

    // 합을 구하고 출력하기
    int sum = 0;
    for (int i = 3; i < 8; i++) {
        sum += v[i].first;
    }
    cout << sum << endl;

    // 각 문제 번호 출력
    for (int i = 3; i < 8; i++) {
        cout << v[i].second << " ";
    }

    return 0;
}
