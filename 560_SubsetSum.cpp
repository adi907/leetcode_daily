#include <iostream>
using namespace std;



int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    return 0;
}
int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> sumFrequencyMap;
        int sum = 0;
        sumFrequencyMap[0]= 1;

        for(int i=0 ;i<nums.size();i++){
            sum += nums[i];
            if(sumFrequencyMap.count(sum - k) != 0){
                ans += sumFrequencyMap[sum - k];
            }
            sumFrequencyMap[sum]++;
        }

    return ans;
    }
