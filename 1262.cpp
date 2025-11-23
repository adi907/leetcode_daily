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

int div3Sum(vector<int>& nums, int sum, int ind, vector<int>& dp){
    if(ind == nums.size()){
        if(isDivisible(sum)){
            return dp[ind] = sum;
        }else{
            return dp[ind] = 0;
        }
    }
    int a=0,b=0;

        a = div3Sum(nums, sum + nums[ind], ind+1, dp); 
        b = div3Sum(nums, sum , ind+1, dp); 


        cout<<"Bhai index: "<< ind<<" value: "<< max(a,b)<<endl;
    return dp[ind] = max(a,b);
}

int maxSumDivThree(vector<int>& nums) {
    int maxSum = 0;
    int currSum = 0;
    int ind = 0;

    vector<int> dp(nums.size() + 1, -1); 
    dp[0] = 0;
    cout<<endl;

    int ans = div3Sum(nums , currSum , ind, dp); 
    for(int i = 0 ;i<dp.size(); i++){
        cout<< dp[i]<< " ";
    }
    return ans;
}


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

    cout<< endl<<"Ans: "<<maxSumDivThree(nums)<<endl;


    return 0;
}