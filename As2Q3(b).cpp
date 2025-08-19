#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n-1];
    cout<<"Enter a sorted array with 1 missing element of size "<<n-1<<": ";
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int beg=0;
    int end=n-2;
    int missing=0;
    while(beg<=end){
        int mid=(beg+end)/2;
        if(arr[mid]!=mid + 1){
            missing = mid + 1;
            end = mid - 1;
            }
            else {
                beg = mid+1;
            }
        }
        cout<<"The missing elements is: "<<missing<<endl;
    return 0;
    }