#include <iostream>
using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> runningSum;
    int currSum = 0;
    runningSum[currSum]=-1;
    int ans = 0;
    
    for(int i=0; i<nums.size();i++){
        if(!nums[i]){
            currSum--;
        }else{
            currSum++;
        }

        if(runningSum.count(currSum)!=0){
            ans = max(ans, i-runningSum[currSum]);
        }else{
            runningSum[currSum]=i;
        }
    }
return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;


    return 0;
}