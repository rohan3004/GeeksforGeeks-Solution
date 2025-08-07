#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::sort and std::min
#include <climits>   // Required for INT_MAX

class Solution {
 public:
  /**
   * @brief Calculates the minimum difference in seconds between any two times in an array.
   * * @param arr A vector of strings representing times in "HH:MM:SS" format.
   * @return The minimum difference in seconds.
   */
  int minDifference(std::vector<std::string> &arr) {
    // There are 24 * 60 * 60 = 86400 seconds in a day.
    const int totalSecondsInDay = 86400;

    // A vector to store all time points converted to seconds from midnight.
    std::vector<int> secondsList;

    // Convert each time string to total seconds.
    for (const std::string &timeStr : arr) {
      int hours = std::stoi(timeStr.substr(0, 2));
      int minutes = std::stoi(timeStr.substr(3, 2));
      int seconds = std::stoi(timeStr.substr(6, 2));
      secondsList.push_back(hours * 3600 + minutes * 60 + seconds);
    }

    // Sort the list of seconds to easily find adjacent differences.
    std::sort(secondsList.begin(), secondsList.end());

    int min_diff = INT_MAX;

    // Find the minimum difference between consecutive time points.
    for (size_t i = 1; i < secondsList.size(); ++i) {
      min_diff = std::min(min_diff, secondsList[i] - secondsList[i - 1]);
    }

    // Now, calculate the wrap-around difference between the last and first time.
    // This is the difference from the last time of the day to the first time of the "next" day.
    int wrapAroundDiff = (secondsList[0] + totalSecondsInDay) - secondsList.back();

    // The final answer is the smaller of the two minimums.
    return std::min(min_diff, wrapAroundDiff);
  }
};