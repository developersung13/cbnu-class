#include <iostream>
#define LIMIT_LENGTH_OF_CHAR 99
using namespace std;


int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
    char str[100];

    cout << "���ڵ��� �Է��Ͻÿ�(100�� �̸�)\n";
    cin.getline(str, LIMIT_LENGTH_OF_CHAR);

    for (int k = 0; k < LIMIT_LENGTH_OF_CHAR; k++)
        if (str[k] == 'x')
            ans++;
    cout << "X�� ������ " << ans;
    return 0;
}