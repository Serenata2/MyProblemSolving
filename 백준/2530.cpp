#include <iostream>

using namespace std;

int main()
{
    int h, m, s;
    cin >> h >> m >> s;

    int oven_roating_time;
    cin >> oven_roating_time;
   
    // 오븐을 굽기 시작하는 시간, 초 단위로 바꾸기
    int current_time = h * 3600 + m * 60 + s;

    // 오븐에 굽기를 마치는 시간, 초 단위로 바꾸기
    int end_time = current_time + oven_roating_time;

    // 시간이 24:00:00을 넘어가면 초기화하기
    end_time %= 3600 * 24;

    cout << end_time / 3600 << " ";
    end_time %= 3600;

    cout << end_time / 60 << " ";
    end_time %= 60;

    cout << end_time;

    return 0;
}
