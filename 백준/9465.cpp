#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, num;
		cin >> N;

		vector<int> points[2];
		// D[i][j] : ���ʺ��� ���ʴ�� i+1 �࿡�� j+1 ���� �ִ� ��ƼĿ�� ���������� �� ��
		//           ���� ��ƼĿ�� ������ ũ�� �� �� �ִ� ��
		vector<int> D[2];

		// ���� �Է¹ޱ�
		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			points[0].push_back(num);
		}

		for (int j = 0; j < N; j++) {
			scanf("%d", &num);
			points[1].push_back(num);
		}

		// �ʱ�ȭ
		D[0].push_back(points[0][0]);
		D[1].push_back(points[1][0]);

		D[0].push_back(points[1][0] + points[0][1]);
		D[1].push_back(points[0][0] + points[1][1]);

		// ���� ��ȹ��
		for (int j = 2; j < N; j++) {
			D[0].push_back(max(D[1][j-1], D[1][j-2]) + points[0][j]);
			D[1].push_back(max(D[0][j-1], D[0][j-2]) + points[1][j]);
		}

		cout << max(D[0][N - 1], D[1][N - 1]) << endl;
	}
	

	return 0;
}