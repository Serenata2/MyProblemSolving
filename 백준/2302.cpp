#include <iostream>
#include <vector>
#include <unordered_set>

#define MAX_NUM 40

using namespace std;

int D[MAX_NUM + 1];
unordered_set<int> vip;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        vip.insert(num);
    }

    // �ʱ�ȭ
    D[0] = 1;
    D[1] = 1;

    // DP
    for (int i = 2; i <= N; i++) {
        // vip���̶��
        if (vip.find(i) != vip.end()) {
            D[i] = D[i - 1];
        }
        else {
            // ���� ���� vip���̿��ٸ�
            if (vip.find(i - 1) != vip.end()) {
                D[i] = D[i - 1];
            }
            else {
                D[i] = D[i - 1] + D[i - 2];
            }
        }
    }

    cout << D[N];


    return 0;
}