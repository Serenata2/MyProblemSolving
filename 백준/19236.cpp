#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define N 4

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

bool inRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

int eat_fish(int fishes[][4], int dir[][4])
{
    int temp_fish[4][4];        // ���簢��ĭ�� ����� ��ȣ ������ �迭
    int temp_dir[4][4];         // ���簢��ĭ�� ������ ��ȣ�� ������ �迭
    map<int, int > fish_num;    // key : ������ȣ, value : (x,y)��ǥ -> 4 * x + y

    // û�ҳ� ����� ��ġ
    int teen_shark[2] = {0, 0};

    // ���� ���簢��ĭ �迭 ����
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp_fish[i][j] = fishes[i][j];
            temp_dir[i][j] = dir[i][j];

            // ����Ⱑ �����ϸ� map�� ����
            if (fishes[i][j] > 0) {
                fish_num[fishes[i][j]] = 4 * i + j;
            }
            // ����� ���� û�ҳ� ����� ��ġ update
            else if (fishes[i][j] < 0) {
                teen_shark[0] = i;
                teen_shark[1] = j;
            }
        }
    }

    // ����� ��ȣ�� ���� �ͺ��� �����ؼ� ����� �̵� ����
    for (int i = 1; i <= 16; i++) {
        if (fish_num.find(i) != fish_num.end()) {
            int x = fish_num[i] / 4, y = fish_num[i] % 4;

            // �ݽð� �������� ���鼭 ��ġ�� ��ȯ�� ����� Ȥ�� ������ �ֳ� Ȯ��
            for (int j = 0; j < 8; j++) {
                int nx = x + dx[(temp_dir[x][y] + j) % 8];
                int ny = y + dy[(temp_dir[x][y] + j) % 8];

                if (inRange(nx, ny) && temp_fish[nx][ny] >= 0) {
                    // ���� ����Ⱑ �ִ� ĭ�� ���� ����
                    temp_dir[x][y] = (temp_dir[x][y] + j) % 8;

                    // ���� ���� ��ȯ
                    int temp = temp_dir[x][y];
                    temp_dir[x][y] = temp_dir[nx][ny];
                    temp_dir[nx][ny] = temp;

                    // ����� ��ġ ��ȯ
                    temp = temp_fish[x][y];
                    temp_fish[x][y] = temp_fish[nx][ny];
                    temp_fish[nx][ny] = temp;

                    // map ����
                    fish_num[temp] = 4 * nx + ny;

                    // �ٲ�� ����Ⳣ���� ��� �߰��� map ����
                    if (temp_fish[x][y] > 0) {
                        fish_num[temp_fish[x][y]] = 4 * x + y;
                    }
                    break;
                }
            }
        }
    }

    // û�ҳ� �� �̵��� �� �ִ� ĭ�� �ִ��� Ȯ��
    vector<int > possible_shark_pos;    // û�ҳ� �� �̵��� �� �ִ� (x,y) -> 4 * x + y
    for (int i = 3; i >= 1; i--) {
        int nx = teen_shark[0] + i * dx[temp_dir[teen_shark[0]][teen_shark[1]]];
        int ny = teen_shark[1] + i * dy[temp_dir[teen_shark[0]][teen_shark[1]]];

        if (inRange(nx, ny) && temp_fish[nx][ny] > 0) {
            possible_shark_pos.push_back(4 * nx + ny);
        }

    }

    // û�ҳ� �� �̵��� ĭ�� ���� ���
    if (possible_shark_pos.empty()) {
        return 0;
    }

    // �̵��� �� �ִ� ĭ �߿��� ����� ��ȣ ���� �ִ� ã��
    int max_fish = 0;   // �ִ� ����� ��ȣ ��
    temp_fish[teen_shark[0]][teen_shark[1]] = 0;    // ���� �� �ִ� �ڸ��� 0���� ä��
    for (auto pos : possible_shark_pos) {
        int temp = temp_fish[pos / 4][pos % 4];     // �̵��� �ڸ��� ���� �̸� ����
        temp_fish[pos / 4][pos % 4] = -1;           // �̵��� �ڸ��� ���� -1�� update
        max_fish = max(max_fish, eat_fish(temp_fish, temp_dir) + temp); // ����Լ� ȣ��
        temp_fish[pos / 4][pos % 4] = temp;         // �̵��� �ڸ��� �� ������� ����
    }

    // �ִ� ����� ��ȣ �� ��ȯ
    return max_fish;
}

int main() 
{
    int direction[N][N];            // ����
    int fishes[N][N];               // ����� ��ȣ
    int teen_shark[2] = { 1, 1 };   // û�ҳ� ����� ��ġ

    // ���� �Է¹ޱ�
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int fish_num, dir;
            cin >> fish_num >> dir;

            direction[i][j] = dir - 1;
            fishes[i][j] = fish_num;
        }
    }

    // ����� ��ġ�� (0,0)���� ����
    int ans = fishes[0][0];

    // ���簢�� �迭���� ����� ��ġ ���� -1�� �ʱ�ȭ
    fishes[0][0] = -1;

    // ����Լ� ȣ��
    ans = ans + eat_fish(fishes, direction);

    cout << ans;
    
    return 0;
}