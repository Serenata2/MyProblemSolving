#include <iostream>

#define MAX_NUM 499

using namespace std;

int N;
int sand_board[MAX_NUM][MAX_NUM];	// ����
int tornado[2];						// ����̵� ��ġ

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int ratio[4] = { 1, 2, 7, 10 };

int dz[4][2][4] = {
	{ { -1, 0, 1, 0 }, { 0, -1, 0, 1} },	// 1%
	{ { -2, 1, 2, -1 }, { -1, -2, 1, 2} },	// 2%
	{ { -1, 1, 1, -1 }, { -1, -1, 1, 1} },	// 7%
	{ { -1, 2, 1, -2 }, { -2, -1, 2, 1 }}	// 10%
};

// dir�� ¦���̸� x�� ��Ī
// dir�� Ȧ���̸� y�� ��Ī

bool inRange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

int move_tornado(int dir)
{
	int x = tornado[0], y = tornado[1];

	// ����̵� �̵�
	tornado[0] = x + dx[dir];
	tornado[1] = y + dy[dir];

	int sand = sand_board[tornado[0]][tornado[1]];	// ���ÿ��� y�� ��
	int outward_sand = 0;							// ������ ������ ���� ��
	int blown_sand_sum = 0;							// ������ ���� �̵��� ���� ��
	int nx, ny, blown_sand;

	// �� �̵�(1, 2, 7, 10% �𷡵�)
	for (int i = 0; i < 4; i++) {
		int k = 1;
		int l = 1;
		for (int j = 0; j < 2; j++) {
			nx = x + dz[i][0][dir] * k;
			ny = y + dz[i][1][dir] * l;

			blown_sand = (int)((ratio[i] * sand) / 100);	// �̵��ϴ� �𷡾�
			blown_sand_sum += blown_sand;

			if (inRange(nx, ny)) {
				sand_board[nx][ny] += blown_sand;
			}
			// ���� ������ ���� ���
			else {
				outward_sand += blown_sand;
			}

			if (dir % 2 == 0) {
				k = -1;
			}
			else{
				l = -1;
			}
		}
	}

	// 5% �� �̵�
	nx = x + 3 * dx[dir];
	ny = y + 3 * dy[dir];

	blown_sand = (int)((5 * sand) / 100);
	blown_sand_sum += blown_sand;

	if (inRange(nx, ny)) {
		sand_board[nx][ny] += blown_sand;
	}
	else {
		outward_sand += blown_sand;
	}

	// ���� ���
	int alpha = sand - blown_sand_sum;
	nx = x + 2 * dx[dir];
	ny = y + 2 * dy[dir];

	if (inRange(nx, ny)) {
		sand_board[nx][ny] += alpha;
	}
	else {
		outward_sand += alpha;
	}

	// y�ڸ��� �𷡸� ���ֱ�
	sand_board[tornado[0]][tornado[1]] = 0;

	return outward_sand;
}

int main(void)
{
	cin >> N;

	// ���� �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &sand_board[i][j]);
		}
	}

	// �߾ӿ� ����̵� ��ġ
	tornado[0] = (int)(N / 2);
	tornado[1] = (int)(N / 2);

	int ans = 0;		// ������ ������ ���� ���� ��
	int dir = 0;		// ����̵��� ����
	int move_num = 1;	// �ش� �������� ����̵��� �̵��ؾ��ϴ� ĭ

	while (1) {
		// �·� �̵�
		dir = 0;
		for (int i = 0; i < move_num && i < N - 1; i++) {
			ans += move_tornado(dir);
		}

		if (move_num >= N) {
			break;
		}

		// ��, ��, �� �̵�
		for (int i = 0, dir = 1; i < 3; i++, dir++) {
			if (i == 1) {
				move_num++;
			}

			for (int j = 0; j < move_num; j++) {
				ans += move_tornado(dir);
			}
		}
		move_num++;
	}

	cout << ans;
}
