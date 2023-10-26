#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define MAX_NUM 20

using namespace std;

// ��, �Ʒ�, ����, ������
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, K;
int smell[MAX_NUM][MAX_NUM][2]; // smell[i][j][0] : ����� ��ȣ, sea[i][j][1] : ������ ���� �ð� 
int sharks[MAX_NUM][MAX_NUM];   // �ٴ� �� ����� ��ġ �迭
int shark_move[MAX_NUM * MAX_NUM + 1][4][4];    // ����� �������� �켱����
int shark_heading[MAX_NUM * MAX_NUM + 1];       // ���� ����� �������

bool inRange(int x, int y)
{
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() 
{
    int h;
    // N : ������ ����, M : ��� ��, K : ������ remain ��
    cin >> N >> M >> K;

    // �ٴ� �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sharks[i][j];

            // ����� ��� ���� �����
            if (sharks[i][j] > 0) {
                smell[i][j][0] = sharks[i][j];
                smell[i][j][1] = K;
            }
        }
    }

    // ����� ���� �Է� �ޱ�
    for (int i = 1; i <= M; i++) {
        cin >> h;
        shark_heading[i] = h - 1;
    }

    // �� ����� �켱���� �Է� �ޱ�
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> h;
                shark_move[i][j][k] = h - 1;
            }
        }
    }

    int ans = 0;
    while(M > 1){
        // 1000�ʸ� �ѱ� ���
        if (ans >= 1000) {
            ans = -1;
            break;
        }

        // �� ���ÿ� �̵����� ���� �ٴ� ���¸� ������ �迭
        // �� ����
        vector<vector<int> > temp_sharks(N, vector<int> (N, 0));

        // �ٴٸ� �ѷ����鼭 ���� �̵���Ű��
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // ����� ���
                if (sharks[i][j] > 0) {
                    int shark_num = sharks[i][j];           // ��� ��ȣ
                    int heading = shark_heading[shark_num]; // ���� �� ���� ����
                    int x = 0, y = 0;                       // ���������� �̵��� ��ġ
                    bool flag = true;           // ó�� �ڽ��� ������ �Ѹ� ĭ�� ã�� ����

                    // ���� �ٶ󺸴� ���⿡���� �켱������ ���� �̵��� �� �ִ��� ����
                    for (int k = 0; k < 4; k++) {
                        int dir = shark_move[shark_num][heading][k];
                        int nx = i + dx[dir], ny = j + dy[dir];

                        if (inRange(nx, ny)) {
                            // �ڽ��� ������ ���
                            if (smell[nx][ny][0] == shark_num && flag) {
                                shark_heading[shark_num] = dir;
                                x = nx, y = ny;
                                flag = false;
                            }
                            // �� �� �ִ� ���
                            else if (smell[nx][ny][1] == 0) {
                                shark_heading[shark_num] = dir;
                                x = nx, y = ny;
                                break;
                            }
                        }
                    }

                    // �� �̹� �����ϴ� ���
                    if (temp_sharks[x][y] > 0) {
                        // ���� �� ��Ƴ���
                        temp_sharks[x][y] = min(temp_sharks[x][y], shark_num);
                        M--;
                    }
                    else {
                        temp_sharks[x][y] = shark_num;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sharks[i][j] = temp_sharks[i][j];

                // �� �ִ� ���
                if (sharks[i][j] > 0) {
                    smell[i][j][0] = sharks[i][j];
                    smell[i][j][1] = K;
                }
                // ������ ���� �ð� ���̱�
                else if(smell[i][j][1] > 0){
                    smell[i][j][1] -= 1;
                    if (smell[i][j][1] == 0) {
                        smell[i][j][0] = 0;
                    }
                }
            }
        }

        ans++;
    }

    
    cout << ans;

    return 0;
}