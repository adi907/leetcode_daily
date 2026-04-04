#include <iostream>
using namespace std;

long long maxSubarraySum(vector<int>& nums, int k) {
    long long maxSum = INT_MIN;
    long long currSum = 0;
    vector<long long int> prefixSum(nums.size() + 1,0);
    unordered_map<int,long long int> indexMinPrefixSumMap;
    
    for(int i=1 ;i<=nums.size(); i++){
        prefixSum[i] = (long long)((long long)nums[i-1] + (long long)prefixSum[i-1]);
    }

    for(int i = 0 ; i <= nums.size(); i++){
        
        if(indexMinPrefixSumMap.find(i%k) == indexMinPrefixSumMap.end()){
            indexMinPrefixSumMap[i%k] = prefixSum[i];
        }else{
            currSum = prefixSum[i] - indexMinPrefixSumMap[i%k];
            maxSum = max(maxSum , currSum);
            indexMinPrefixSumMap[i%k] = min(indexMinPrefixSumMap[i%k] , prefixSum[i]);
        }

        if(i==0){
            continue;
        }
        
    }

    return maxSum;
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, ele,k;
    vector<int> nums;

    cin>> n;
    for(int i=0;i<n;i++){
        cin>> ele;
        nums.push_back(ele);
    }
    cin>>k;
    cout<<maxSubarraySum(nums,k);

    return 0;
}