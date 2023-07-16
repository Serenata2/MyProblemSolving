#include <iostream>
#include <cstdio>

#define MAX_NUM 1000

using namespace std;
int arr[MAX_NUM + 1];
// D[i] : i ��° ������ ���ҷ� ������ �κ� ���� �߿��� ���� �� �����ϴ� �κ� ������ ����
int D[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	// ���� �Է� �ޱ�
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	// �ʱ�ȭ
	D[1] = 1;

	// ���� ��ȹ��
	for (int i = 2; i <= N; i++) {
		int max = i;
		for (int j = i - 1; j > 0; j--) {
			if (arr[i] > arr[j] && D[j] > D[max]) {
				max = j;
			}
		}

		D[i] = D[max] + 1;
	}

	// ��� D �迭 ���Ҹ� ���鼭 �ִ� ã��
	int result = D[1];

	for (int i = 2; i <= N; i++) {
		if (D[i] > result) {
			result = D[i];
		}
	}

	cout << result;

	return 0;
}