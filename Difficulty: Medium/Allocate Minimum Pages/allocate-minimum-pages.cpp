#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
  public:
    /**
     * @brief Checks if it's possible to allocate books to 'k' students
     * such that no student reads more than 'maxPages'.
     * @param arr The array of book pages.
     * @param k The number of students.
     * @param maxPages The maximum number of pages a single student can be assigned.
     * @return True if allocation is possible, otherwise false.
     */
    bool isPossible(vector<int> &arr, int k, long long maxPages) {
        int studentsRequired = 1;
        long long currentPagesSum = 0;

        for (int pages : arr) {
            // This check is implicitly handled by setting the binary search's
            // lower bound, but it's good for clarity. A single book cannot
            // be larger than the max limit.
            if (pages > maxPages) {
                return false;
            }

            if (currentPagesSum + pages > maxPages) {
                // Current student cannot take this book, assign to a new student.
                studentsRequired++;
                currentPagesSum = pages; // New student starts with this book.
            } else {
                // Assign the book to the current student.
                currentPagesSum += pages;
            }
        }

        return studentsRequired <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        // Edge Case: If the number of students is more than the number of books,
        // it's impossible to give each student at least one book.
        if (k > n) {
            return -1;
        }

        // Define the search space for our answer.
        // Use long long to avoid potential overflow if the sum is large.
        long long low = 0;
        long long high = 0;
        for (int pages : arr) {
            if (pages > low) {
                low = pages;
            }
            high += pages;
        }
        
        long long result = -1;

        // Perform binary search on the possible answer range.
        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                // 'mid' is a potential answer. Let's try for an even smaller value.
                result = mid;
                high = mid - 1;
            } else {
                // 'mid' is too small; we need to increase our page limit.
                low = mid + 1;
            }
        }

        return result;
    }
};