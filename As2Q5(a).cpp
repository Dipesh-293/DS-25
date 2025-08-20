#include <iostream>
#include <vector>
using namespace std;

class Diagonal {
    vector<int> arr;
    int n;
public:
    Diagonal(int n): n(n), arr(n,0) {}
    void set(int i, int j, int x) {
        if(i==j) arr[i-1] = x;   // store only diagonal
    }
    int get(int i, int j) {
        return (i==j) ? arr[i-1] : 0;
    }
};

int main() {
    int n = 4;
    Diagonal d(n);

    d.set(1,1,5);
    d.set(2,2,8);
    d.set(3,3,9);
    d.set(4,4,12);

    cout << "Diagonal Matrix:\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout << d.get(i,j) << " ";
        cout << endl;
    }
    return 0;
}
