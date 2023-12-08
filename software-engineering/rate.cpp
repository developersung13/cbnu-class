#include <iostream>
using namespace std;

int main() {
    char good, hot, youngDriverExist = 'F';
    int amt, poor, young;
    double localFactor, baseRate, rate;
    
    cin >> amt >> poor >> young >> good >> hot >> localFactor;
    
    // Amt 처리 (#1)
    switch (amt) {
        case 20:
            rate = baseRate = 50;
            break;
        case 50:
            rate = baseRate = 75;
            break;
        case 100:
            rate = baseRate = 100;
            break;
        case 300:
            rate = baseRate = 150;
            break;
        case 1000:
            rate = baseRate = 300;
            break;
        default:
            cout << "amt 입력 오류!!\n";
            return 0;
    }
    
    cout << "\nAMT 처리: " << rate << "\n\n";
    
    // Poor 처리 (#2)
    switch (poor) {
        case 0:
            break;
        case 1:
            rate += baseRate * 0.2;
            break;
        case 2:
            rate += baseRate * 0.5;
            break;
        default:
            cout << "poor 입력 오류!!\n";
            return 0;
    }
    
    cout << "\nPoor 처리: " << rate << "\n\n";
    
    // Young, Good 처리 (#3, #4)
    if (young >= 16 && young <= 20) {
        youngDriverExist = 'T';
        if (good == 'T')
            rate += baseRate * 0.125; // 12.5% 인상
        else if (good == 'F')
            rate += baseRate * 0.25; // 25% 인상
        else {
            cout << "amt 입력 오류!!\n";
            return 0;
        }
            
    } else if (young >= 21 && young <= 24) {
        youngDriverExist = 'T';
        if (good == 'T')
            rate += baseRate * 0.075; // 7.5% 인상
        else if (good == 'F') {
            rate += baseRate * 0.15; // 15% 인상
        }
        else {
            cout << "amt 입력 오류!!\n";
            return 0;
        }
    }
    
    cout << "\nYoung, Good 처리: " << rate << "\n\n";
    
    // Hot 처리 (#5)
    if (hot == 'T')
        rate += baseRate * 0.25; // 25% 인상
        
    cout << "\nHot 처리: " << rate << "\n\n";
        
    // LocalFactor 처리 (#6)
    if (localFactor >= 0.75 && localFactor <= 1.25)
        rate = rate * localFactor;
    else
        cout << "LocalFactor 입력 오류!!\n";
        
    cout << "\nLocalFactor 처리: " << rate << "\n\n";
    
    // 보험 가입이 거절되는 5가지 경우
    if (amt == 1000) {
        if (hot == 'T') rate = 0;
        if (poor != 0)  rate = 0;
    } else if (amt == 300) {
        if (poor == 2) rate = 0;
        if (hot == 'T') {
            if (youngDriverExist == 'T') rate = 0;
            if (poor != 0) rate = 0;
        }
    }
    
    cout << amt << ' ' << poor << ' ' << young << ' ' << good << ' ' << hot << ' ' << localFactor << ' ' << rate << '\n';
    return 0;
}