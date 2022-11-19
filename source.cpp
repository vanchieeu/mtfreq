#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    long long a[n];
    map <long long, long long> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }

    cout << b.size() << endl;
    for (int i = 0; i < n; i++) {
        if (b[a[i]] > 0) {
            cout << a[i] << " " << b[a[i]] << endl;
            b[a[i]] = 0;
        }
    }
    return 0;
}