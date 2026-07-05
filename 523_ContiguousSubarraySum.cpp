#include <iostream>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumFrequencyMap;
        int currSum = 0;
        sumFrequencyMap[currSum]= -1;
        for(int i=0 ;i<nums.size();i++){
            currSum+=nums[i];
            currSum= currSum%k;
            if(sumFrequencyMap.count(currSum) != 0){
                int len = i-sumFrequencyMap[currSum];
                if(len >=2){
                    return true;
                }
            }else{
                sumFrequencyMap[currSum]= i;
            }
        }
        return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, x, k;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    cin >> k;
    cout << (checkSubarraySum(nums, k) ? "true" : "false") << endl;


    return 0;
}