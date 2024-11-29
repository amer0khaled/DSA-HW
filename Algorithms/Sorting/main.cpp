//
// Created by amer on 11/26/24.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


// insertion sort >> the idea behind this algorithm is the <incremental thinking> technique
void insertionSort(vector<int> &v) {
  const int n = v.size();
  for (int i = 1; i < n; i++) {
    int key = v[i];
    int j = i - 1;

    // shift and add in the right location
    while (j >= 0 && v[j] > key) {
      // shift right
      v[j + 1] = v[j];
      j--;
    }

    // the first right element
    v[j + 1] = key;
  }
}


void selectionSort(vector<int>& v) {

  // Iterate over each element in the vector, except the last one.
  for (int i = 0; i < v.size() - 1; ++i) {
    // Assume the current element is the minimum
    int mn_idx = i;

    // Search for the smallest element in the remaining unsorted part of the vector
    for (int j = i + 1; j < v.size(); ++j) {
      // If we find a smaller element, update the minimum index
      if (v[mn_idx] > v[j])
        mn_idx = j;
    }

    // After finding the minimum element, swap it with the current element at index i
    if (mn_idx != i)
      swap(v[i], v[mn_idx]);

  }
}


void countSort(vector<int>& v) {
  // Step 1: Find the maximum element in the array.
  int mx = INT_MIN;
  for (auto item : v) {
    mx = max(mx, item);
  }

  // Step 2: Create a frequency array `frq` to store the count of each number.
  vector<int> frq(mx + 1, 0);
  for (auto item : v) {
    frq[item]++;
  }

  // Step 3: Rebuild the sorted array in place.
  int idx = 0;
  for (int i = 0; i <= mx; ++i) {
    for (int j = 0; j < frq[i]; ++j, ++idx) {
      v[idx] = i;
    }
  }

}



int main() {

  vector<int> v {7, 2, 4, 3, 5, 6, 8, 9, 10};

  countSort(v);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }

  cout << "\n";

  return 0;
}