#include<iostream>
#include<stdexcept>

using namespace std;

uint64_t convertFromBase(string bin, uint32_t base) {
    const static string digits = "0123456789ABCDEF";

    if(base < 2 or base > 16) {
        throw invalid_argument("Invalid base.");
    }

    uint64_t r = 0;

    for(const char& d: bin) {
        auto p = digits.find(d);
        if(p == string::npos or p >= base) {
            throw invalid_argument("Invalid number.");       
        }
        r = r * base + p;
    }
    return r;
}

int main() {
    string bin;
    uint32_t base;

    while(cin >> bin >> base) {
        try{
            uint64_t res = convertFromBase(bin, base);
            cout << bin << " in base 10 is equal to " << res << '\n';
        }
        catch(invalid_argument& e) {
            cerr << e.what() << '\n';
        }
    }
}