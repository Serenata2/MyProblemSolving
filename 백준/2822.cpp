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

    // ������ �������� ������������ ����
    sort(v.begin(), v.end());

    // ���� ��ȣ�� �������� ������������ ����
    sort(v.begin() + 3, v.end(), compare);

    // ���� ���ϰ� ����ϱ�
    int sum = 0;
    for (int i = 3; i < 8; i++) {
        sum += v[i].first;
    }
    cout << sum << endl;

    // �� ���� ��ȣ ���
    for (int i = 3; i < 8; i++) {
        cout << v[i].second << " ";
    }

    return 0;
}
