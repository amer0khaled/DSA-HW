//
// Created by amer on 7/7/24.
//

#include "sorting.h"

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> result {};
    //sort array
    sort(arr.begin(), arr.end());

    //get minimum difference
    int def = abs(arr[1] - arr[0]);
    for (int i = 1, j = 2; j < arr.size(); ++i, ++j) {
        if (def >= arr[j] - arr[i])
            def = arr[j] - arr[i];
    }

    //get elements
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i + 1] - arr[i] == def)
            result.push_back({arr[i], arr[i + 1]});
    }

    return result;
}

void insertion_sort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


bool can_be_triangle(int len1, int len2, int len3) {
    if (len1 + len2 > len3 && len1 + len3 > len2 && len2 + len3 > len1)
        return true;
    else
        return false;
}

int largestPerimeter(vector<int>& nums) {
    int mx = INT32_MIN;
    int perimeter = 0;

    insertion_sort(nums);
    for (int a = 0, b = 1, c = 2; c < nums.size(); ++a, ++b, ++c) {
        bool is_traingle = can_be_triangle(nums[a], nums[b], nums[c]);
        if (!is_traingle)
            continue;
        else {
            perimeter = nums[a] + nums[b] + nums[c];
            if (mx < perimeter)
                mx = perimeter;
        }

    }
    return perimeter;
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

void selection_sort(vector<int> &list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        auto min = min_element(it, list.end());
        swap(*it, *min);
    }
}


int arrayPairSum(vector<int>& nums) {
    selection_sort(nums);
    int sum = 0;
    for (int i = 0, j = 1; j < nums.size(); i += 2, j += 2) {
        sum += min(nums[i], nums[j]);
    }
    return sum;
}
/*                  0 1 2 3 4 5
 * [3,5,2,1,6,4] ⇒ [3,5,1,6,2,4] or [1,6,2,5,3,4]
 *
 * nums[even] <= nums[odd]
 *
 * 1 2 3 4 5 6 >> 1 6 2 5 3 4
 *
 * 1 6 2 3 4 5
 * 1 6 2 5 3 4
 *
 * */
void wiggle_sort(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int front = 1, back = nums.size() - 1; front <= nums.size() / 2; ++front) {
        if (front % 2 != 0) {
            int key = nums[back];
            int i = back - 1;
            while (i >= front) {
              nums[i + 1] = nums[i];
              i--;
          }
          nums[i + 1] = key;
        }
    }
}


int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int eliminated_monsters {};
    int charge_time {};

    //calculate time for each monster
    vector<double> time (dist.size());
    for (int i = 0; i < time.size(); ++i) {
        time[i] = (double)dist[i] / speed[i];
    }

    sort(time.begin(), time.end());
    for (int i = 0; i < dist.size(); ++i, ++charge_time) {
        time[i] -= charge_time;
        if (time[i] > 0)
            eliminated_monsters++;
        else
            return eliminated_monsters;
    }

    return eliminated_monsters;

}

int get_sum(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
        sum += nums[i];
    return sum;
}

// 4 3 1 2 5
int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    // convert minus into positive numbers
    int i = 0;
    while (i < nums.size() && nums[i] < 0 && k > 0) {
        nums[i] = -nums[i];
        i++;
        k--;
    }

    // if there is more k
    //here all numbers are positive
    //if k is odd flip the smallest number else leave it as it's
    if (k > 0 && k % 2 != 0) {
        // 1 2 3 4 5
        sort(nums.begin(), nums.end());
        nums[0] = -nums[0];
    }

    // get sum
    return get_sum(nums);
}
