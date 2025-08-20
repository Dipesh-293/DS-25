#include <iostream>
#include <vector>
using namespace std;

class UpperTriangular {
    vector<int> arr;
    int n;
public:
    UpperTriangular(int n): n(n), arr(n*(n+1)/2,0) {}
    int index(int i,int j) { return (j*(j-1))/2 + (i-1); }
    void set(int i,int j,int x) { if(i<=j) arr[index(i,j)]=x; }
    int get(int i,int j) { return (i<=j)?arr[index(i,j)]:0; }
};

int main() {
    int n=4;
    UpperTriangular u(n);

    u.set(1,1,1); u.set(1,2,2); u.set(1,3,3); u.set(1,4,4);
    u.set(2,2,5); u.set(2,3,6); u.set(2,4,7);
    u.set(3,3,8); u.set(3,4,9);
    u.set(4,4,10);

    cout<<"Upper Triangular Matrix:\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<u.get(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
