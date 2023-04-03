#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX_LENGTH 5

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    
    string name, maxName;
    vector<string> namesVector;
    
    cout << "이름을 " << MAX_LENGTH << "개 입력하라\n";
    
    for(int k=0; k < MAX_LENGTH; k++) {
        cout << k+1<< "<<";
        getline(cin, name);
        namesVector.push_back(name);
        maxName = maxName < namesVector.at(k) ? namesVector.at(k) : maxName;
    } cout << "사전에서 가장 뒤에 나오는 이름은 " << maxName;
    
    return 0;
}