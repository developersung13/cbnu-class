#include <iostream>
using namespace std;

int big(int num1, int num2, int maxNum=100) {
    int bigNum = num1 < num2 ? num2 : num1;
    if (bigNum < maxNum) return bigNum;
    return maxNum;
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x = big(3, 5); // 3과 5중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
    int y = big(300, 60); // 300과 60중 큰 값 300이 최대값 100보다 크므로, 100 리턴
    int z = big(30, 60, 50); // 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
    cout << x << ' ' << y << ' ' << z << '\n';
    
    return 0;
}