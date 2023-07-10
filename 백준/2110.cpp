#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_NUM 2000000

using namespace std;

int home[MAX_NUM + 1];

int main()
{
	int N, C;
	cin >> N >> C;

	// ���� ��ǥ�� �ް�, ������������ ����
	for (int i = 1; i <= N; i++) {
		scanf("%d", &home[i]);
	}
	sort(home + 1, home + N + 1);

	// �ִ� �Ÿ��� �̺� Ž������ ã��
	int low = 1;
	int high = (home[N] - home[1]) / (C - 1);
	int result = 0;

	while (low <= high) {
		// ���� ������ �� ������ ������ �Ÿ��� mid�� ����
		int mid = (low + high) / 2;

		int sum = 0; // ������ ���� �Ÿ�
		int total_c = 1; // ������ ��ġ Ƚ��, �� ó�� ���� �̹� �����⸦ ��ġ�����Ƿ� 1�� �ʱ�ȭ

		for (int i = 2; i <= N; i++) {
			sum += home[i] - home[i - 1];
			// Ÿ��Ʈ�ϰ� ������ ������ �Ÿ��� mid���� ũ�� ������ ��ġ
			if (sum >= mid) {
				sum = 0;
				total_c++;
			}
			// �ִ������� �����⸦ ��ġ�� ��� �ݺ��� ������
			if (total_c >= C) {
				break;
			}
		}

		// ���� ������ �� ������ ������ �Ÿ��� mid�� �����ϴ� ���
		if (total_c >= C) {
			result = mid;
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