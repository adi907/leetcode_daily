#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
        int currSum = 0;
        int sum = 0;
        int total = 0;

        for(int i = 0; i<nums.size() ; i++){
            currSum += nums[i]*i;
            total += nums[i];
        }

        int ans = currSum;
        for(int i = nums.size()-1 ; i>0 ; i--){
            currSum = currSum - (nums.size()-1)*nums[i] + (total-nums[i]);
            ans = max(ans,currSum);
        }
    return ans;   
} 
    
int main() {
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
    
        int n,ele;
    vector<int> nums;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    int ans = maxRotateFunction(nums);
    cout<<ans;
        return 0;
    }