#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  /**
   * @brief Arranges an array of non-negative integers to form the largest possible number.
   * * @param arr A vector of integers.
   * @return A string representing the largest number formed by concatenating the integers.
   */
  string findLargest(vector<int> &arr) {
    // 1. Convert all integers to their string representations.
    vector<string> s_arr;
    for (int num : arr) {
      s_arr.push_back(to_string(num));
    }

    // 2. Sort the strings using a custom lambda comparator.
    // The comparator checks which order of concatenation (a+b vs b+a) yields a larger number.
    sort(s_arr.begin(), s_arr.end(), [](const string& a, const string& b) {
      return a + b > b + a;
    });

    // 3. Handle the edge case where the array contains only zeros.
    // If the first element after sorting is "0", the entire number is 0.
    if (s_arr[0] == "0") {
      return "0";
    }

    // 4. Concatenate the sorted strings to get the final result.
    string result = "";
    for (const string& s : s_arr) {
      result += s;
    }

    return result;
  }
};