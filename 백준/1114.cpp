#include <iostream>
#include <algorithm>

#define MAX_NUM 10000

using namespace std;

int cut_pos[MAX_NUM + 2];

int main() 
{
    // L : �볪���� ����
    // K : �볪���� �ڸ� �� �ִ� ��ġ�� ����
    // C : �볪���� �ڸ� �� �ִ� Ƚ��
    int L, K, C;
    cin >> L >> K >> C;

    // �볪���� �ڸ� �� �ִ� ��ġ �Է� �ޱ�
    for (int i = 1; i <= K; i++) {
        cin >> cut_pos[i];
    }
    cut_pos[K + 1] = L;

    // �ڸ� �� �ִ� ��ġ�� ������������ �����ϱ�
    sort(cut_pos + 1, cut_pos + K + 1);

    int longest_len;
    int first_cut;

    int left = 0;
    int right = 1000000000;

    // �̺�Ž�� ����
    while (left <= right) {
        // C�� ���Ϸ� �볪���� ¥���鼭 
        // ��� ���̰� mid ���Ϸ� ¥�� �� �ִ��� Ȯ��
        int mid = (left + right) / 2;

        int cut = 0; // ¥���� Ƚ��
        int log_len = 0; // ���� Ȯ�� ���� �볪�� ����
        int cutting = 0; // �������� �볪���� �ڸ� ��ġ
        int max_len = 0; // ���� ��� ¥�� �볪���� ����

        for (int i = K + 1; i > 0; i--) {
            int len = (cut_pos[i] - cut_pos[i - 1]);

            // �� ������ ���̰� mid���� ũ�� �ᱹ ����
            if (len > mid) {
                cut = C + 2;
                break;
            }

            // �� ������ �����ص� �Ǹ� �����ϱ�
            if (log_len + len <= mid) {
                log_len += len;
            }
            // mid ���̸� �Ѿ�� �볪�� ¥����
            else {
                max_len = max(max_len, log_len);
                cutting = cut_pos[i];
                log_len = len;
                cut++; 
            }
        }
        max_len = max(max_len, log_len);

        // ������ ���
        if (cut <= C) {
            right = mid - 1;
            longest_len = max_len;
            
            // �����Ӱ� �ڸ� ���(�Ʒ��� ����)
            // 10 4 2
            // 1 4 5 10
            if (cutting <= mid && cut < C) {
                first_cut = cut_pos[1];
            }
            else {
                first_cut = cutting;
            }
        }
        // ������ ���
        else {
            left = mid + 1;
        }
    }

    cout << longest_len << " " << first_cut;

    return 0;
}