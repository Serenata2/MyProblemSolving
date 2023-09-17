#include <iostream>

#define MAX_NUM 1000000

using namespace std;

int stocks[MAX_NUM + 1];

int main() 
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        // �̷��� �ְ��� �Է¹ޱ�
        for (int i = 1; i <= N; i++) {
            scanf("%d", &stocks[i]);
        }

        long long benefit = 0;      // �ִ� �̵�
        int max_stock = stocks[N];  // �̷��� ���� ���� �ְ� ����

        for (int i = N - 1; i > 0; i--) {
            // �̷��� ���� ���� �ְ� ���ݿ� �Ǵٰ� ����
            if (max_stock > stocks[i]) {
                benefit += (long long)(max_stock - stocks[i]);
            }
            // i�� �ְ��� i�� ���Ŀ� �ְ��麸�� ũ�Ƿ�
            // i�Ͽ� �ֽ��� ��� ��� ����
            // �׸��� max_stock ���� update
            else {
                max_stock = stocks[i];
            }
        }

        cout << benefit << endl;
    }

    return 0;
}