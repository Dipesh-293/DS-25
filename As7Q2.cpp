#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex]) minIndex = i;
            if (arr[i] > arr[maxIndex]) maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if (maxIndex == left) maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 9, 1};
    int n = 7;

    improvedSelectionSort(arr, n);

    cout << "Improved Selection Sorted Array: ";
    for (int x : arr) cout << x << " ";
}
