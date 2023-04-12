#include <iostream>
#include <cstring>
using namespace std;

char& find(char a[], char c, bool& success) {
    int k;
    success = false;
    for (k=0; k < strlen(a); k++)
        if (a[k] == c) {
            success = true;
            return a[k];
        }
    return a[k];
}

int main() {
    char s[] = "Mike";
    bool b = false;
    char& loc = find(s, 'M', b);
    
    if(b == false) {
        cout << "M을 발견할 수 없다" << endl;
        return 0;
    }
    
    loc = 'm'; // 'M' 위치에 'm' 기록
    cout << s << endl; // "mike"가 출력됨
    
    return 0;
}