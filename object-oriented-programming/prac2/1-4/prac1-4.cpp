#include <iostream>
#define LIMIT_LENGTH_OF_CHAR 99
using namespace std;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str, str2;

    cout << "새 암호를 입력하세요 >> ";
    cin >> str;

    cout << "새 암호를 다시 한번 입력하세요 >> ";
    cin >> str2;

    if (str == str2)
        cout << "같습니다.";
    else
        cout << "같지 않습니다.";
    return 0;
}