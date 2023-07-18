#include <iostream>

#define MAX_NUM 10000

using namespace std;

int arr[101];
int D[MAX_NUM + 1];

int main()
{
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// �ʱ�ȭ
	// ù��° �������� k���� ���� �� �ִ��� Ȯ��
	for (int i = 1; i <= K; i++) {
		if (arr[1] <= i && i % arr[1] == 0) {
			D[i] = 1;
		}
	}

	// �Է¹��� ��� �������� ����� �� �ִ� ���� ������ �ϳ��� �߰��ϴ� �������
	// ���� ��ȹ�� �̿�
	for (int i = 2; i <= N; i++) {
		// ������ ��ġ�� k ������ Ŭ �� �ֱ⿡ ���� ó��
		if (arr[i] <= MAX_NUM) {
			D[arr[i]] += 1;
		}
		// D[i] : ���ݱ��� ����� �� �ִ� ���� �������� i ���� ���� �� �ִ� ����� ��
		for (int j = arr[i] + 1; j <= K; j++) {
			D[j] += D[j - arr[i]];
		}
	}

	cout << D[K];

	return 0;
}