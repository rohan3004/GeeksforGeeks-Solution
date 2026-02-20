#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Custom comparator to decide the order of two strings
    static bool compare(string a, string b) {
        // Return true if a+b is strictly greater than b+a
        return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        // Step 1: Convert all integers to strings
        vector<string> str_arr;
        for (int num : arr) {
            str_arr.push_back(to_string(num));
        }

        // Step 2: Sort the array of strings using the custom comparator
        sort(str_arr.begin(), str_arr.end(), compare);

        // Step 3: Handle the edge case where the array has multiple 0s
        // If the largest number after sorting is "0", the entire result is just "0"
        if (str_arr[0] == "0") {
            return "0";
        }

        // Step 4: Concatenate the sorted strings to form the largest number
        string result = "";
        for (string s : str_arr) {
            result += s;
        }

        return result;
    }
};