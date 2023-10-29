#include <iostream>
#include <set>

#define MAX_NUM 50
#define MAX_M 100

using namespace std;

int N, M;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int idx[4] = { 1, 3, 5, 7 };

int basket[MAX_NUM][MAX_NUM];
pair<int, int> cloud_power[MAX_M]; // 구름의 이동방향, 거리 저장 배열
set<int> clouds;

bool inRange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

// (x,y) -> N * x + y로 표현
int transform(int x, int y)
{
	return N * x + y;
}

int main(void)
{
	cin >> N >> M;

	// 바구니에 있는 물 입력받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> basket[i][j];
		}
	}

	// 구름의 방향, 거리 입력받기
	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		cloud_power[i].first = d - 1;
		cloud_power[i].second = s;
	}

	// 구름 넣기
	clouds.insert(transform(N - 1, 0));
	clouds.insert(transform(N - 1, 1));
	clouds.insert(transform(N - 2, 0));
	clouds.insert(transform(N - 2, 1));

	int m = 0;
	while (m < M) {
		// 모든 구름 이동
		set<int> temp_clouds;
		for (auto cloud : clouds) {
			int x = cloud / N, y = cloud % N;
			int dir = cloud_power[m].first, s = cloud_power[m].second;

			int nx = ((x + s * dx[dir]) % N + N) % N;
			int ny = ((y + s * dy[dir]) % N + N) % N;

			// 구름에서 비 내리기
			basket[nx][ny] += 1;

			// 물이 증가한 칸 저장하기
			temp_clouds.insert(transform(nx, ny));
		}

		// 구름 삭제
		clouds.clear();

		// 물이 증가한 칸에서 물 복사버그 발생
		for (auto cloud : temp_clouds) {
			int x = cloud / N, y = cloud % N;
			int copy_water = 0;		// 물 복사되는 양

			// 거리가 1인 대각선 방향에 대해서 검사
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[idx[i]], ny = y + dy[idx[i]];

				if (inRange(nx, ny)) {
					if (basket[nx][ny] > 0) {
						copy_water++;
					}
				}
			}

			basket[x][y] += copy_water;
		}

		// 바구니에 저장된 물의 양이 2 이상이면 구름 생성
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (basket[i][j] >= 2 && temp_clouds.find(transform(i, j)) == temp_clouds.end()) {
					basket[i][j] -= 2;
					clouds.insert(transform(i, j));
				}
			}
		}

		m++;
	}

	// M번의 이동 후 바구니에 들어있는 물의 양의 합 구하기
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += basket[i][j];
		}
	}

	cout << ans;

	return 0;
}
