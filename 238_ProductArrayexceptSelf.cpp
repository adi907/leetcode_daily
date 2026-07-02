#include <iostream>
using namespace std;

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>suffixProduct(nums.size());

        int currProduct = 1;
        for(int i=nums.size()-1;i>=0;i--){
            suffixProduct[i]=currProduct;
            currProduct*=nums[i];
        }
        currProduct = 1;
        vector<int> ans;
        for(int i=0;i<nums.size(); i++){
            ans.push_back(currProduct*suffixProduct[i]);

            currProduct*=nums[i];
        }
    return ans;
    }

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, x;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    vector<int> result = productExceptSelf(nums);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}