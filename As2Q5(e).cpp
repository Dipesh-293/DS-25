#include <iostream>
#include <vector>
using namespace std;

class Symmetric {
    vector<int> arr;
    int n;
public:
    Symmetric(int n): n(n), arr(n*(n+1)/2,0) {}
    int index(int i,int j) {
        if(i>=j) return (i*(i-1))/2 + (j-1);
        else return (j*(j-1))/2 + (i-1);
    }
    void set(int i,int j,int x) { arr[index(i,j)]=x; }
    int get(int i,int j) { return arr[index(i,j)]; }
};

int main() {
    int n=4;
    Symmetric s(n);

    s.set(1,1,1); s.set(1,2,2); s.set(1,3,3); s.set(1,4,4);
    s.set(2,2,5); s.set(2,3,6); s.set(2,4,7);
    s.set(3,3,8); s.set(3,4,9);
    s.set(4,4,10);

    cout<<"Symmetric Matrix:\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<s.get(i,j)<<" ";
        cout<<endl;
    }
    return 0;
}
