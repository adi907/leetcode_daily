#include <iostream>
using namespace std;

int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int leftProduct = 1;
        int rightProduct = 1;

        for(int i=0;i<nums.size(); i++){
            leftProduct*=nums[i];
            rightProduct*=nums[nums.size()-1-i];

            ans = max(ans, max(leftProduct,rightProduct));

            if(leftProduct == 0){
                leftProduct = 1;
            }
            if(rightProduct == 0){
                rightProduct = 1;
            }
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
    cin>> n;
    for(int i=0 ;i <n;i++){
        cin>> ele;
        nums.push_back(ele);
    }
    cout<<maxProduct(nums);

    return 0;
}