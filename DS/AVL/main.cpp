//
// Created by amer on 10/28/24.
//

#include <iostream>
#include "AVLTree.cpp"
using namespace std;


void f1() {
    AVLTree tree;

    for (int i = 0; i <= 32; ++i) {	// degenerate
        tree.insert_value(i);
        tree.level_order_traversal();
    }
}

int findFloor(vector<int>& arr, int k) {
    int result = -1;
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > k)
            right = mid - 1;
        else if (arr[mid] < k)
            left = mid + 1;
        else return mid;
    }

    if (left > right)
        result = right;

    return result;

}


int main() {

    vector<int> arr {1, 2, 8, 10, 11, 12, 19};
    cout << findFloor(arr, 5);


    return 0;
}
