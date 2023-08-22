#include <iostream>

using namespace std;

int main()
{
    int h, m, s;
    cin >> h >> m >> s;

    int oven_roating_time;
    cin >> oven_roating_time;
   
    // ������ ���� �����ϴ� �ð�, �� ������ �ٲٱ�
    int current_time = h * 3600 + m * 60 + s;

    // ���쿡 ���⸦ ��ġ�� �ð�, �� ������ �ٲٱ�
    int end_time = current_time + oven_roating_time;

    // �ð��� 24:00:00�� �Ѿ�� �ʱ�ȭ�ϱ�
    end_time %= 3600 * 24;

    cout << end_time / 3600 << " ";
    end_time %= 3600;

    cout << end_time / 60 << " ";
    end_time %= 60;

    cout << end_time;

    return 0;
}
