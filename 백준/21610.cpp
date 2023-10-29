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
pair<int, int> cloud_power[MAX_M]; // ������ �̵�����, �Ÿ� ���� �迭
set<int> clouds;

bool inRange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

// (x,y) -> N * x + y�� ǥ��
int transform(int x, int y)
{
	return N * x + y;
}

int main(void)
{
	cin >> N >> M;

	// �ٱ��Ͽ� �ִ� �� �Է¹ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> basket[i][j];
		}
	}

	// ������ ����, �Ÿ� �Է¹ޱ�
	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		cloud_power[i].first = d - 1;
		cloud_power[i].second = s;
	}

	// ���� �ֱ�
	clouds.insert(transform(N - 1, 0));
	clouds.insert(transform(N - 1, 1));
	clouds.insert(transform(N - 2, 0));
	clouds.insert(transform(N - 2, 1));

	int m = 0;
	while (m < M) {
		// ��� ���� �̵�
		set<int> temp_clouds;
		for (auto cloud : clouds) {
			int x = cloud / N, y = cloud % N;
			int dir = cloud_power[m].first, s = cloud_power[m].second;

			int nx = ((x + s * dx[dir]) % N + N) % N;
			int ny = ((y + s * dy[dir]) % N + N) % N;

			// �������� �� ������
			basket[nx][ny] += 1;

			// ���� ������ ĭ �����ϱ�
			temp_clouds.insert(transform(nx, ny));
		}

		// ���� ����
		clouds.clear();

		// ���� ������ ĭ���� �� ������� �߻�
		for (auto cloud : temp_clouds) {
			int x = cloud / N, y = cloud % N;
			int copy_water = 0;		// �� ����Ǵ� ��

			// �Ÿ��� 1�� �밢�� ���⿡ ���ؼ� �˻�
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

		// �ٱ��Ͽ� ����� ���� ���� 2 �̻��̸� ���� ����
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

	// M���� �̵� �� �ٱ��Ͽ� ����ִ� ���� ���� �� ���ϱ�
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += basket[i][j];
		}
	}

	cout << ans;

	return 0;
}
