//
// Created by amer on 7/8/24.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k);
int get_sum(vector<int>& nums);
int eliminateMaximum(vector<int>& dist, vector<int>& speed);
void wiggle_sort(vector<int> &nums);
int arrayPairSum(vector<int>& nums);
void selection_sort(vector<int> &list);
void count_sort(vector<int> &list);
int largestPerimeter(vector<int>& nums);
bool can_be_triangle(int len1, int len2, int len3);
void insertion_sort(vector<int> &arr);
vector<vector<int>> minimumAbsDifference(vector<int>& arr);
void insertion_sort_v2(vector<int> &arr);
vector<int> sortArray(vector<int>& nums);
void Count_Sort_for_strings_v1(vector<string> &array);
void Count_Sort_for_strings_v2(vector<string> &array);

#endif //SORTING_SORTING_H
