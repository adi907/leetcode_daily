#include <iostream>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int ans = INT_MIN;

        for(int i: nums){
            currSum +=i;
            ans = max(ans,currSum);
            currSum = max(currSum , 0);
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

    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    cout<<maxSubArray(nums);


    return 0;
}