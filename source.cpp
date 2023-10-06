#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s;
    cin >> s;

    int count[2] = { 0, 0 };
    char flag = s[0];

    for (int i = 0; i < s.size(); i++) {
        if (flag != s[i]) {
            count[flag - '0']++;
            flag = s[i];
        }
    }
    count[flag - '0']++;

    cout << min(count[0], count[1]);

    return 0;
}