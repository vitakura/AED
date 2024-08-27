#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversions += leftArr.size() - i; // Contando inversões
        }
    }

    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }

    return inversions;
}

long long countInversions(vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += countInversions(arr, left, mid);
        inversions += countInversions(arr, mid + 1, right);
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}

int main() {
    int N;
    
    while (cin >> N && N != 0) {
        vector<int> sequence(N);
        for (int i = 0; i < N; i++) {
            cin >> sequence[i];
        }
        
        long long inversions = countInversions(sequence, 0, N - 1);
        
        if (inversions % 2 == 0) {
            cout << "Carlos" << endl;
        } else {
            cout << "Marcelo" << endl;
        }
    }
    
    return 0;
}
