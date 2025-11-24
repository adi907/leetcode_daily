#include <iostream>
using namespace std;

// Approach 1 : Recursion
bool isDivisible(int sum){
    if(sum%3 == 0){
        return true;
    }
    return false;
}
// int div3Sum(vector<int>& nums, int sum, int ind){
//     if(ind == nums.size()){
//         if(isDivisible(sum)){
//             return sum;
//         }else{
//             return -1;
//         }
//     }
//     int a=0,b=0;

//         a = div3Sum(nums, sum + nums[ind], ind+1); 
//         b = div3Sum(nums, sum , ind+1); 

//     return max(a,b);
// }

// int maxSumDivThree(vector<int>& nums) {
//     int maxSum = 0;
//     int currSum = 0;
//     int ind = 0;


//     return div3Sum(nums , currSum , ind);
// }


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, ele;
    vector<int> nums;
    cin>> n;
    for(int i =0 ;i<n;i++){
        cin>> ele;
        nums.push_back(ele);
    }

    cout<< maxSumDivThree(nums);

    return 0;
}

// Approach 2: Memoization

const int UNVIS = INT_MIN;          // dp unvisited marker
const int NEG_INF = INT_MIN / 4;    // impossible state marker

int dfs(const vector<int>& nums, int ind, int rem, vector<vector<int>>& dp){
    if(ind == nums.size()){
        return (rem == 0) ? 0 : NEG_INF;
    }
    if(dp[ind][rem] != UNVIS) return dp[ind][rem];

    // option 1: skip current
    int skip = dfs(nums, ind + 1, rem, dp);

    // option 2: take current -> need tail remainder such that (nums[ind] + tail) % 3 == rem
    int need = (rem - (nums[ind] % 3) + 3) % 3;
    int tail = dfs(nums, ind + 1, need, dp);
    int take = (tail == NEG_INF) ? NEG_INF : nums[ind] + tail;

    return dp[ind][rem] = max(skip, take);
}

// int maxSumDivThree(vector<int>& nums) {
//     int n = nums.size();
//     vector<vector<int>> dp(n, vector<int>(3, UNVIS));
//     int ans = dfs(nums, 0, 0, dp);
//     return (ans == NEG_INF) ? 0 : ans;
// }

// Approach 3: Tabulation
int maxSumDivThree(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(4, INT_MIN));
    
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0; // Sum of 0 is always divisible by 3
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            // Not take the current number
            dp[i][j] = dp[i-1][j];
            
            // Take the current number
            int newSum = dp[i-1][(j - nums[i-1] % 3 + 3) % 3];
            if(newSum != INT_MIN) {
                dp[i][j] = max(dp[i][j], newSum + nums[i-1]);
            }
        }
    }
    
    return dp[n][0];
}