#include <iostream>
#include <string>
using namespace std;
#define MAX_LEN 5

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    
    string names[MAX_LEN], maxName;
    
    for(int k=0; k < MAX_LEN; k++) {
        cout << "이름 << ";
        getline(cin, names[k]);
        maxName = maxName < names[k] ? names[k] : maxName;
    } cout << "사전에서 가장 뒤에 나오는 문자열은 " << maxName;
    
    return 0;
}