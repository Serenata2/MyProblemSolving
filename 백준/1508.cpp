#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_NUM 50

using namespace std;

int pos[MAX_NUM + 1];

int main()
{
	// N : ���̽� ����, M : ������ ��, K : ������ ��ġ��ų �� �ִ� ��ġ�� ��
	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 1; i <= K; i++) {
		scanf("%d", &pos[i]);
	}

	// �̺� Ž�� ����
	int low = 1;
	int high = (pos[K] - pos[1]) / (M - 1);
	string result;

	while (low <= high) {
		// ���� ����� �� ������ �Ÿ��� mid�� ����
		int mid = (low + high) / 2;
		// ���� ������ �Ÿ�
		int sum = 0;
		// ���� ��ġ Ƚ��
		// ���� Ư���� �� ó�� ������ ��ġ�� ������ ��ġ�ϴ°� ���������� ó���� ���� ��ġ
		int total_m = 1;
		string str = "1";

		for (int i = 2; i <= K; i++) {
			// ������ �� ��ġ������ ���ڿ��� 0 �߰�
			if (total_m >= M) {
				str.append("0");
				continue;
			}

			sum += pos[i] - pos[i - 1];
			// Ÿ��Ʈ�ϰ� ���� ������ �Ÿ��� mid���� ũ�� ���� ��ġ
			if (sum >= mid) {
				sum = 0;
				total_m++;
				str.append("1");
			}
			else {
				str.append("0");
			}
		}

		// ���� ����� �� ���� ������ �Ÿ��� mid�� �����ϴ� ���
		if (total_m >= M) {
			result.assign(str);
			low = mid + 1;
		}
		// �������� ���ϴ� ���
		else {
			high = mid - 1;
		}
	}

	cout << result;


	return 0;
}