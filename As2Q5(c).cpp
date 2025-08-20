#include <iostream>
#include <vector>
using namespace std;

class LowerTriangular {
    vector<int> arr;
    int n;
public:
    LowerTriangular(int n): n(n), arr(n*(n+1)/2,0) {}
    int index(int i,int j) { return (i*(i-1))/2 + (j-1); }
    void set(int i,int j,int x) { if(i>=j) arr[index(i,j)]=x; }
    int get(int i,int j) { return (i>=j)?arr[index(i,j)]:0; }
};

int main() {
    int n=4;
    LowerTriangular l(n);

    l.set(1,1,1);
    l.set(2,1,2); l.set(2,2,3);
    l.set(3,1,4); l.set(3,2,5); l.set(3,3,6);
    l.set(4,1,7); l.set(4,2,8); l.set(4,3,9); l.set(4,4,10);

    cout<<"Lower Triangular Matrix:\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<l.get(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
