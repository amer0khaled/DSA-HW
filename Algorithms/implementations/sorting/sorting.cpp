#include<iostream>
#include<vector>

using namespace std;


/*

    1 3 10 11 12
*/


//Time: O(n2) >> worst case O(n2), best case O(n)
//Memory: O(1)
void insertion_sort(vector<int> &list) {
    for (int i = 1; i < list.size(); ++i) {
        int key = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            --j;
        }
        list[j + 1] = key;
    }
}

int get_minimum(vector<int> &list, int start) {
    int min_index = start;
    for (int i = start + 1; i < list.size(); ++i) {
        if (list[i] < list[min_index]) 
            min_index = i;
    }
    return min_index;
}


//Time: O(n2) >> worst case O(n2), best case O(n2)
// Memory: O(1)

/* 
note: the best time complexity you can get from sorting algorithm based on
comparison is nlogn.

insertion is better than selection sort from average time prespective, but 
selection sort is better from caching prespective cause it's wide range decreases
unlike insertion it uses all wide range.
*/
void selection_sort(vector<int> &list) {
    for (int i = 0; i < list.size() - 1; ++i) {
        int min_index = get_minimum(list, i);
        swap(list[min_index], list[i]);
    }
}


//assume all elements in the array is positive values
//count sort is useless when the max number in the array is so huge
//Time: O(n + max)
//memory: O(max)
void count_sort(vector<int> &list) {
    //find the largest element in array
    auto mx = *max_element(list.begin(), list.end());

    //compute freq array 
    vector<int> freq_array (mx + 1);
    for (int i = 0; i < list.size(); ++i) {
        freq_array[list[i]]++;
    }

    //put the values back to the array
    int indx = 0;
    for (int i = 0; i < freq_array.size(); ++i) {
        for (int j = 0; j < freq_array[i]; ++j, ++indx) {
            list[indx] = i;
        }
    }
}


int main() {

    vector<int> list {12, 11, 10, 1, 3};
    vector<int> list1 {5, 4, 3, 2, 1};
    count_sort(list);

    for (auto item : list)
        cout << item << " ";
    cout << "\n";

    return 0;
}
