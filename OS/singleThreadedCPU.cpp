#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//https://leetcode.com/problems/single-threaded-cpu/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> allTasks(n, vector<int>(3));
        
        for (int i = 0; i < n; i++) {
            allTasks[i][0] = i; // index
            allTasks[i][1] = tasks[i][0]; // availableTime
            allTasks[i][2] = tasks[i][1]; // ProcessingTime
        }

        // Sort on the basis of duration first then index
        priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;
        sort(allTasks.begin(), allTasks.end(), CompareAvailability());

        int i = 0, index = 0, curTime = 0;
        vector<int> result(n);

        while (i < n) {
            // Check if i-th task's starting time is smaller or equal to current time
            while (i < n && curTime >= allTasks[i][1]) {
                minHeap.push(allTasks[i]);
                i++;
            }

            // Initialization process
            if (minHeap.empty()) {
                curTime = allTasks[i][1];
            }

            if (!minHeap.empty()) {
                vector<int> curTask = minHeap.top();
                minHeap.pop();
                result[index++] = curTask[0];
                curTime += curTask[2];
            }
        }

        while (!minHeap.empty()) { // If there are tasks left in the heap
            vector<int> curTask = minHeap.top();
            minHeap.pop();
            result[index++] = curTask[0];
        }

        return result;
    }

    struct Compare {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return (a[2] == b[2]) ? (a[0] > b[0]) : (a[2] > b[2]);
        }
    };

    struct CompareAvailability {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }
    };
};
