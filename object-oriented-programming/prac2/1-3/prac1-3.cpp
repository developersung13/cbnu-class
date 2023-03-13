#include <iostream>
#define LIMIT_LENGTH_OF_CHAR 99
using namespace std;


int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
    char str[100];

    cout << "문자들을 입력하시오(100개 미만)\n";
    cin.getline(str, LIMIT_LENGTH_OF_CHAR);

    for (int k = 0; k < LIMIT_LENGTH_OF_CHAR; k++)
        if (str[k] == 'x')
            ans++;
    cout << "X의 개수는 " << ans;
    return 0;
}