#include <iostream>
using namespace std;

int minOperations(vector<int>& nums, int k) {
        int currSum = 0;
        for(int i=0 ; i<nums.size(); i++){
            currSum += nums[i];
        }
        return (currSum%k);
}