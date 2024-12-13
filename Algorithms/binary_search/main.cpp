#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

int binary_search(vector<int>& v, int target) {
    int left = 0, right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] > target) {
            right = mid - 1;
        }
        else if (v[mid] < target) {
            left = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}


int lower_bound(vector<int>& v, int target) {
    int left = 0, right = v.size() - 1;
    int result = -1;


    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (v[mid] > target) {
            right = mid - 1;
        }
        else if (v[mid] < target) {
            left = mid + 1;
        }
        else {

            result = mid;
            right = mid - 1;
        }
    }

    return result;
}

int upper_bound(vector<int>& v, int target) {
    int left = 0, right = v.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (v[mid] > target) {
            right = mid - 1;
        }
        else if (v[mid] < target) {
            left = mid + 1;
        }
        else {
            result = mid;
            left = mid + 1;
        }
    }

    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {
    auto l = lower_bound(nums, target);

    auto r = upper_bound(nums, target);

    return {l, r};
}


bool possible(int n, long long rows) {
    long coins = (rows * (rows + 1)) / 2;

    return coins <= n;  
}


int arrangeCoins(int n) {
    int left = 0, right = n;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (possible(n, mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int get_sum(vector<int>& nums, int divisor) {
    long long sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += ceil((float)nums[i] / divisor);
    }

    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {

    int left = 1, right = *max_element(nums.begin(), nums.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (get_sum(nums, mid) <= threshold) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

bool isReady(vector<int>& bloomday, int boq, int flow, int days) {
    int tmp_flow = 0, tmp_boq = 0;

    for (int i = 0; i < bloomday.size(); ++i) {
        if (days >= bloomday[i]) {
            tmp_flow++;

            if (tmp_flow == flow) {
                tmp_flow = 0;
                tmp_boq++;
            }
        }
        else {
            tmp_flow = 0;
        }

        if (tmp_boq == boq) {
            return true;
        }
    }

    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {

    int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isReady(bloomDay, m,  k, mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

vector<double> calc_area(vector<int>& pie_reaius) {
    vector<double> area;
    for (int i = 0; i < pie_reaius.size(); ++i) {
        double pie_area = M_PI * (pie_reaius[i]) * (pie_reaius[i]);
        area.push_back(pie_area);
    }
    return area;
}

int get_number_of_pieces(vector<double>& pies_area, double suggested_area) {
    int cnt = 0;

    for (int i = 0; i < pies_area.size(); ++i) {
        cnt += pies_area[i] / suggested_area;
    }

    return cnt;
}

double largest_area(vector<int>& pie_redius, int n) {
    const double EPS = 1e-12;
    auto pies_area = calc_area(pie_redius);

    double left = 0, right = *max_element(pies_area.begin(), pies_area.end());
    double result = -1;

    while (fabs(right - left) > EPS) {
        double mid = left + (right - left) / 2;

        if (get_number_of_pieces(pies_area, mid) >= n) {
            result = mid;
            left = mid; 
        }
        else {
            right = mid;
        }
    }

    return result;
}

vector<pair<int, int>> get_intervals_start(vector<vector<int>>& intervals) {
    vector<pair<int, int>> interval_start;
    
    for (int j = 0; j < intervals.size(); ++j) {
        interval_start.push_back({intervals[j][0], j});
        
    }

    return interval_start;
}

int find_first(vector<pair<int, int>>& intervals_start, int target) {
    int left = 0, right = intervals_start.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (intervals_start[mid].first >= target) {
            result = intervals_start[mid].second;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {

    auto intervals_start = get_intervals_start(intervals);
    sort(intervals_start.begin(), intervals_start.end());

    vector<int> right_intervals(intervals.size(), -1);
    for (int i = 0; i < intervals.size(); ++i) {
        int idx = find_first(intervals_start, intervals[i][1]);
        
        if (idx != -1) {
            right_intervals[i] = idx;
        }
    }

    return right_intervals;
}


bool is_valid(int a, int b, int c) {
    return a + b > c;
}

int triangleNumber(vector<int>& nums) {
    int triplets = 0;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int a = nums[i], b = nums[j];

            // Find the largest index `tmp` where nums[i] + nums[j] > nums[tmp]
            int left = j + 1, right = n - 1;
            int tmp = j;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (is_valid(a, b, nums[mid])) {
                    tmp = mid;
                    left = mid + 1;
                }
                else {
                    right = mid  - 1;
                }
            }

            // All indices from j + 1 to tmp form valid triangles
            triplets += (tmp - j);
        }
    }

    return triplets;
}


bool is_covered_all_houses(vector<int>& houses, vector<int>& heaters, int reduis) {
    int j = 0;
    for (int i = 0; i < (int) heaters.size(); ++i) {
        // Covered range [left, right] by the ith heater
        int leftC = heaters[i] - reduis, rightC = heaters[i] + reduis;

        while (j < (int) houses.size() && leftC <= houses[j] && houses[j] <= rightC)
            ++j;	// cover more houses with ith heater
    }
    return j == (int) houses.size();	// all is covered?
}

int findRadius(vector<int> &houses, vector<int> &heaters) {

    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int start = 0, end = 1e9, radius = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (is_covered_all_houses(houses, heaters, mid))	// find smallest
            end = mid - 1, radius = mid;
        else
            start = mid + 1;
    }
    return radius;
}

int findMin(vector<int>& nums) {

    int left = 0, right = nums.size() - 1, ans = 6000;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[left] <= nums[mid]) {
            ans = min(ans, nums[left]);
            left = mid + 1;
        }
        else {
            ans = min(ans, nums[mid]);
            right = mid - 1;
        }
    }

    return ans;

}


bool is_enough_time(vector<int>& piles, int h, int speed) {
    int time_needed = 0;
    for (int pile : piles) {
        time_needed += ceil((double ) pile / speed);
    }

    return time_needed <= h;

}

int minEatingSpeed(vector<int>& piles, int h) {
    // k : bananas per hour
    int k = -1;
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (is_enough_time(piles, h, mid)) {
            k = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return k;

}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0, right = matrix[0].size() - 1;

    while (left < matrix.size() && right >= 0) {
        if (matrix[left][right] < target) {
            left++;
        }
        else if (matrix[left][right] > target) {
            right--;
        }
        else {
            return true;
        }
    }
    return false;
}



int main() {

    vector<vector<int>> v {{1,5,5,7}, {13,14,16,20}, {23,30,34,60}};
    //vector<int> h {1, 4};

    cout << searchMatrix(v, 13);


    return 0;
}