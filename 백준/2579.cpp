#include <iostream>
#include <cstdio>

#define MAX_NUM 350

using namespace std;

// D[x][0] : xĭ� ���� ��, ������ ��ĭ �ö� ���
// D[x][1] : xĭ���� ���� ��, ������ ��ĭ �ö� ���
int D[MAX_NUM][2];

int point[MAX_NUM + 1];

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &point[i]);
	}

	// �ʱ�ȭ
	D[1][0] = D[1][1] = point[1];
	D[1][1] = -1; // �� ���� ���⿡ -1�� ����
	D[2][0] = point[1] + point[2];
	D[2][1] = point[2];

	for (int i = 3; i <= N; i++) {
		// i-2 ��ܱ��� �ö� �� �������� �� ���, �� ��� ���� ��� �� �� ������ ū ���� ����
		D[i][1] = ((D[i - 2][0] > D[i - 2][1]) ? D[i - 2][0] : D[i - 2][1]) + point[i];

		// �������� �ѹ��� �� ����� �ö� i-1 ��ܿ� ���� ��� ����
		D[i][0] = D[i - 1][1] + point[i];

	}

	// N ����� �ö� ��, �������� �� ���, �� ��� ���� ��� �� �� ������ ū ���� ����
	cout << ((D[N][0] > D[N][1]) ? D[N][0] : D[N][1]);

	return 0;
}