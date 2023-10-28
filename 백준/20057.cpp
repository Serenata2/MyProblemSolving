#include <iostream>

#define MAX_NUM 499

using namespace std;

int N;
int sand_board[MAX_NUM][MAX_NUM];	// 모래판
int tornado[2];						// 토네이도 위치

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int ratio[4] = { 1, 2, 7, 10 };

int dz[4][2][4] = {
	{ { -1, 0, 1, 0 }, { 0, -1, 0, 1} },	// 1%
	{ { -2, 1, 2, -1 }, { -1, -2, 1, 2} },	// 2%
	{ { -1, 1, 1, -1 }, { -1, -1, 1, 1} },	// 7%
	{ { -1, 2, 1, -2 }, { -2, -1, 2, 1 }}	// 10%
};

// dir이 짝수이면 x를 대칭
// dir이 홀수이면 y를 대칭

bool inRange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

int move_tornado(int dir)
{
	int x = tornado[0], y = tornado[1];

	// 토네이도 이동
	tornado[0] = x + dx[dir];
	tornado[1] = y + dy[dir];

	int sand = sand_board[tornado[0]][tornado[1]];	// 예시에서 y의 모래
	int outward_sand = 0;							// 밖으로 나가는 모래의 양
	int blown_sand_sum = 0;							// 비율에 따라 이동한 모래의 양
	int nx, ny, blown_sand;

	// 모래 이동(1, 2, 7, 10% 모래들)
	for (int i = 0; i < 4; i++) {
		int k = 1;
		int l = 1;
		for (int j = 0; j < 2; j++) {
			nx = x + dz[i][0][dir] * k;
			ny = y + dz[i][1][dir] * l;

			blown_sand = (int)((ratio[i] * sand) / 100);	// 이동하는 모래양
			blown_sand_sum += blown_sand;

			if (inRange(nx, ny)) {
				sand_board[nx][ny] += blown_sand;
			}
			// 격자 밖으로 나간 경우
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

	// 5% 모래 이동
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

	// 알파 계산
	int alpha = sand - blown_sand_sum;
	nx = x + 2 * dx[dir];
	ny = y + 2 * dy[dir];

	if (inRange(nx, ny)) {
		sand_board[nx][ny] += alpha;
	}
	else {
		outward_sand += alpha;
	}

	// y자리의 모래를 없애기
	sand_board[tornado[0]][tornado[1]] = 0;

	return outward_sand;
}

int main(void)
{
	cin >> N;

	// 모래판 입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &sand_board[i][j]);
		}
	}

	// 중앙에 토네이도 배치
	tornado[0] = (int)(N / 2);
	tornado[1] = (int)(N / 2);

	int ans = 0;		// 격자의 밖으로 나간 모래의 양
	int dir = 0;		// 토네이도의 방향
	int move_num = 1;	// 해당 방향으로 토네이도가 이동해야하는 칸

	while (1) {
		// 좌로 이동
		dir = 0;
		for (int i = 0; i < move_num && i < N - 1; i++) {
			ans += move_tornado(dir);
		}

		if (move_num >= N) {
			break;
		}

		// 하, 우, 상 이동
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
