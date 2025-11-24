#include <iostream>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    int currSum = 0;
    vector<bool> ans;
    for (int i : nums){
        currSum *= 2;
        if (i){
            currSum++;
        }
        currSum %= 5;

        if (currSum){
            ans.push_back(false);
        }else{
            ans.push_back(true);
        }
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

    for(int i = 0; i<n ;i++ ){
        cin>>ele;
        nums.push_back(ele);
    }
    vector<bool> ans = prefixesDivBy5(nums);
    for(int i=0;i<ans.size(); i++){
        cout<< ans[i]<< " ";
    }
    return 0;
}