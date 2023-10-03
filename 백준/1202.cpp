#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <unordered_map>

#define MAX_NUM 300000

using namespace std;

pair<int, int> jewels[MAX_NUM];
unordered_map<int, int> bag_num; // <������ ����, ����>
set<int> bags; // ���� ������ �ִ� ������ ���Ե��� ���� ����

int main() 
{
    int N, K;
    cin >> N >> K;

    // ���� ���� �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jewels[i].second, &jewels[i].first);
    }

    // ������ ��ġ������ ������������ �����ϱ�
    sort(jewels, jewels + N);

    // �賶�� ������ �Է¹ޱ�
    int c;
    for (int i = 0; i < K; i++) {
        scanf("%d", &c);
        bags.insert(c);
        if (bag_num.find(c) == bag_num.end()) {
            bag_num[c] = 1;
        }
        else {
            bag_num[c]++;
        }
    }

    int i = N - 1;
    long long ans = 0;
    while (i >= 0 && !bags.empty()) {
        // M : ������ ����, V : ������ ��ġ
        int M = jewels[i].second, V = jewels[i].first;

        // ��ġ�� ���� ���� �������
        // �ִ��� �����ؼ� �賶�� ���
        if (bags.lower_bound(M) != bags.end()) {
            // ������ ������� ������ ����
            int bag_M = *bags.lower_bound(M);

            ans += (long long)V;
            if (bag_num[bag_M] > 1) {
                bag_num[bag_M]--;
            }
            else {
                bags.erase(bag_M);
            }
        }
        i--;
    }

    cout << ans;

    return 0;
}