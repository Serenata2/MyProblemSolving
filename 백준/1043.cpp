// https://hagisilecoding.tistory.com/133 �ڵ� ����

#include <iostream>
#include <vector>

#define MAX_NUM 50

using namespace std;

vector<int> v[MAX_NUM + 1];

// �ڽ��� �׷��� ��� �����ִ��� ����
int find_p(int parent[], int x) {
    if (x != parent[x])
        return parent[x] = find_p(parent, parent[x]);
    else
        return parent[x];
}

// x�� y�� ���� �׷����� �������
void mer(int parent[], int x, int y) {
    int px = find_p(parent, parent[x]);
    int py = find_p(parent, parent[y]);
    if (px != py) {
        if (px < py)
            parent[py] = parent[px];
        else
            parent[px] = parent[py];
    }
}

int main() {
    int n, m; // ��� ��, ��Ƽ ��
    cin >> n >> m;

    int know_tru; // ������ �ƴ� ��� ��
    cin >> know_tru;

    int parent[53]; // ��� �׷쿡 ���� �ִ��� 

    for (int i = 0; i <= n; i++)
        parent[i] = i; // ���� �ڽ��� �׷����� ���� �з�

    for (int i = 0; i < know_tru; i++) {
        int num;
        cin >> num;
        parent[num] = 0; // ������ �ƴ� ����� 0 �������� �з�
    }

    for (int i = 1; i <= m; i++) {
        // ��Ƽ�� ���� ��� ���� ù ��° ��� �Է� �ޱ�
        int n, persion_num;
        cin >> n >> persion_num;

        v[i].push_back(persion_num);

        // ù��° ����� �� ��� ȥ�� ���� ���̱� ������
        // �ٸ� ����� �׷��� ��ġ�� �ʾƵ� �ż� �з�
        for (int j = 2; j <= n; j++) {
            int num;
            cin >> num; // ��Ƽ�� ���� ��� ��ȣ
            v[i].push_back(num); // ��Ƽ�� ���� ��� ��ȣ ����
            mer(parent, v[i][0], num); // ��Ƽ�� ���� ��� �׷� ��ħ
        }
    }

    int answer = m; // ���� �������� �� ��� �� ���� ����

    // �� ��Ƽ���� ������ �ƴ� ����� �Ѹ��̶� ������ �������� �� �� ����
    // -> �ϳ� ����
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (find_p(parent, parent[v[i][j]]) == 0) {
                answer--;
                break;
            }
        }
    }

    cout << answer;
    return 0;
}
