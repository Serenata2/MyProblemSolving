#include <iostream>
#include <string>

using namespace std;


int main() 
{
    string str;
    cin >> str;

    string ans;

    if (str == "A+") {
        ans = "4.3";
    }
    else if (str == "A0") {
        ans = "4.0";
    }
    else if (str == "A-") {
        ans = "3.7";
    }
    else if (str == "B+") {
        ans = "3.3";
    }
    else if (str == "B0") {
        ans = "3.0";
    }
    else if (str == "B-") {
        ans = "2.7";
    }
    else if (str == "C+") {
        ans = "2.3";
    }
    else if (str == "C0") {
        ans = "2.0";
    }
    else if (str == "C-") {
        ans = "1.7";
    }
    else if (str == "D+") {
        ans = "1.3";
    }
    else if (str == "D0") {
        ans = "1.0";
    }
    else if (str == "D-") {
        ans = "0.7";
    }
    else {
        ans = "0.0";
    }

    cout << ans;

    return 0;
}