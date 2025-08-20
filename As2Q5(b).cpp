#include <iostream>
#include <vector>
using namespace std;

class TriDiagonal {
    vector<int> arr;
    int n;
public:
    TriDiagonal(int n): n(n), arr(3*n-2,0) {}
    int index(int i,int j) {
        if(i-j==0) return i-1;          // main diagonal
        else if(i-j==1) return (n-1)+(i-1);  // lower diagonal
        else if(j-i==1) return (2*n-1)+(i-1); // upper diagonal
        return -1; // invalid
    }
    void set(int i,int j,int x) {
        int k=index(i,j);
        if(k!=-1) arr[k]=x;
    }
    int get(int i,int j) {
        int k=index(i,j);
        return (k!=-1)?arr[k]:0;
    }
};

int main() {
    int n=4;
    TriDiagonal t(n);

    t.set(1,1,1); t.set(1,2,2);
    t.set(2,1,3); t.set(2,2,4); t.set(2,3,5);
    t.set(3,2,6); t.set(3,3,7); t.set(3,4,8);
    t.set(4,3,9); t.set(4,4,10);

    cout<<"Tri-diagonal Matrix:\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<t.get(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
