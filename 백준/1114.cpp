#include <iostream>
#include <algorithm>

#define MAX_NUM 10000

using namespace std;

int cut_pos[MAX_NUM + 2];

int main() 
{
    // L : 통나무의 길이
    // K : 통나무를 자를 수 있는 위치의 개수
    // C : 통나무를 자를 수 있는 횟수
    int L, K, C;
    cin >> L >> K >> C;

    // 통나무를 자를 수 있는 위치 입력 받기
    for (int i = 1; i <= K; i++) {
        cin >> cut_pos[i];
    }
    cut_pos[K + 1] = L;

    // 자를 수 있는 위치를 오름차순으로 정렬하기
    sort(cut_pos + 1, cut_pos + K + 1);

    int longest_len;
    int first_cut;

    int left = 0;
    int right = 1000000000;

    // 이분탐색 시작
    while (left <= right) {
        // C번 이하로 통나무를 짜르면서 
        // 모두 길이가 mid 이하로 짜를 수 있는지 확인
        int mid = (left + right) / 2;

        int cut = 0; // 짜르는 횟수
        int log_len = 0; // 현재 확인 중인 통나무 길이
        int cutting = 0; // 마지막을 통나무를 자른 위치
        int max_len = 0; // 가장 길게 짜른 통나무의 길이

        for (int i = K + 1; i > 0; i--) {
            int len = (cut_pos[i] - cut_pos[i - 1]);

            // 한 구간의 길이가 mid보다 크면 결국 실패
            if (len > mid) {
                cut = C + 2;
                break;
            }

            // 한 구간을 포함해도 되면 포함하기
            if (log_len + len <= mid) {
                log_len += len;
            }
            // mid 길이를 넘어가면 통나무 짜르기
            else {
                max_len = max(max_len, log_len);
                cutting = cut_pos[i];
                log_len = len;
                cut++; 
            }
        }
        max_len = max(max_len, log_len);

        // 성공한 경우
        if (cut <= C) {
            right = mid - 1;
            longest_len = max_len;
            
            // 여유롭게 자른 경우(아래는 예시)
            // 10 4 2
            // 1 4 5 10
            if (cutting <= mid && cut < C) {
                first_cut = cut_pos[1];
            }
            else {
                first_cut = cutting;
            }
        }
        // 실패한 경우
        else {
            left = mid + 1;
        }
    }

    cout << longest_len << " " << first_cut;

    return 0;
}