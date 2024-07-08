//
// Created by amer on 7/8/24.
//

#include "sorting.h"

//decreasing order
void insertion_sort_v2(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/*
 *
    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104

 * */
vector<int> sortArray(vector<int>& nums) {
    //get max number
    int mx = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());

    //compute freq size
    int size = 0;
    if (min < 0)
        size = mx + abs(min) + 1;
    else
        size = mx + 1;

    vector<int> freq (size);

    //compute freq
    for (int i = 0; i < nums.size(); ++i) {
        if (min < 0)
            freq[nums[i] + abs(min)]++;
        else
            freq[nums[i]]++;
    }

    //put freq elements back into the array
    auto indx = 0;
    for (int i = 0; i < freq.size(); ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            if (min < 0)
                nums[indx++]  = i + min;
            else
                nums[indx++] = i;
        }
    }
    return nums;
}

void Count_Sort_for_strings_v1(vector<string> &array) {
    for (int i = 1; i < array.size(); ++i) {
        string key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j][0] > key[0]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void Count_Sort_for_strings_v2(vector<string> &array) {
    for (int i = 1; i < array.size(); ++i) {
        string key = array[i];
        int j = i - 1;
        while ( (j >= 0) &&  ( (array[j][0] > key[0]) || ((array[j][0] == key[0])  && (array[j][1] > key[1])) )) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

}


int main() {

    // -4 -3 -2
    vector<string> arr {"axz", "axa", "zzz", "abc", "abe"};
    Count_Sort_for_strings_v2(arr);
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
