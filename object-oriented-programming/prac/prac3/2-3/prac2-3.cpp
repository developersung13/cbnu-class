#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big);

int main() {
    int num1, num2, big;
    
    cout << "정수 2개를 입력해 주세요: ";
    cin >> num1 >> num2;
    
    if (bigger(num1, num2, big)) cout << "두 수가 동일합니다.";
    else cout << big << "이 더 큽니다.";
    
    return 0;
}

bool bigger(int a, int b, int& big) {
    big = a;
    if (big < b) {
        big = b;
        return false;
    } else if (big > b)
        return false;
    return true;
}