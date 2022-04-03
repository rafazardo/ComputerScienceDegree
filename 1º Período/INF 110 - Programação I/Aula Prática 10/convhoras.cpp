#include <iostream>
#include <iomanip>
using namespace std;

void convhoras(int seg, int &h, int &m, int &s) {
    int sup;
    s = seg%60;
    sup = seg/60;
    m = sup%60;
    sup = sup/60;
    h = sup%60;
}

int main() {

    int seg;
    int h = 0;
    int m = 0;
    int s = 0;
    cin >> seg;
    
    convhoras(seg,h,m,s);
    cout << setfill('0') << setw(2) << h << ":";
    cout << setfill('0') << setw(2) << m << ":";
    cout << setfill('0') << setw(2) << s << endl;
    return 0;
}

