#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    
    string name, maxName;
    
    for(int k=0; k < 5; k++) {
        cout << "이름<<";
        getline(cin, name);
        maxName = maxName < name ? name : maxName;
    } cout << "사전에서 가장 뒤에 나오는 문자열은 " << maxName;
    
    return 0;
}