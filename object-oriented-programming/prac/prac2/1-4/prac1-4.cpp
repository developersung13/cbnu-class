#include <iostream>
#define LIMIT_LENGTH_OF_CHAR 99
using namespace std;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str, str2;

    cout << "�� ��ȣ�� �Է��ϼ��� >> ";
    cin >> str;

    cout << "�� ��ȣ�� �ٽ� �ѹ� �Է��ϼ��� >> ";
    cin >> str2;

    if (str == str2)
        cout << "�����ϴ�.";
    else
        cout << "���� �ʽ��ϴ�.";
    return 0;
}