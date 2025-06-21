/*
You are given an array nums of distinct integers.

In one operation, you can swap any two adjacent elements in the array.

An arrangement of the array is considered valid if the parity of adjacent elements alternates, meaning every pair of neighboring elements consists of one even and one odd number.

Return the minimum number of adjacent swaps required to transform nums into any valid arrangement.

If it is impossible to rearrange nums such that no two adjacent elements have the same parity, return -1©leetcode

*/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> evenPos; 
        vector<int> oddPos;  

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                evenPos.push_back(i);
            } else {
                oddPos.push_back(i);
            }
        }

        int evenCount = evenPos.size();
        int oddCount = oddPos.size();

        if (abs(evenCount - oddCount) > 1) {
            return -1;
        }

        int swaps1 = INT_MAX; // for even 
        int swaps2 = INT_MAX; // for odd 


        if (evenCount >= oddCount) {
            swaps1 = 0;
            int correctIndex = 0;
            for (int i = 0; i < evenPos.size(); i++) {
                swaps1 += abs(evenPos[i] - correctIndex);
                correctIndex += 2;
            }
        }


        if (oddCount >= evenCount) {
            swaps2 = 0;
            int correctIndex = 0;
            for (int i = 0; i < oddPos.size(); i++) {
                swaps2 += abs(oddPos[i] - correctIndex);
                correctIndex += 2;
            }
        }

        return min(swaps1, swaps2);
    }
};
