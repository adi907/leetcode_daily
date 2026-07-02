#include <iostream>
using namespace std;

int calculateSubsequence(int value, unordered_map<int,int> frequencyMap){
    int cnt = 0;
    while(frequencyMap[value]>0){
        cnt++;
        value++;
    }

return cnt;
}
int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    unordered_map<int,int> frequencyMap;
    for(int i=0 ;i<nums.size();i++){
        frequencyMap[nums[i]] = i;
    }
    int ans = 1;
    for(int i=0;i<nums.size();i++){
        if(frequencyMap[nums[i]-1] == 0 && frequencyMap[nums[i]+1]>0 && frequencyMap[nums[i]] == i){
            // starting point
            int len = calculateSubsequence(nums[i],frequencyMap);
            ans = max(ans,len);
        }
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
    cout << longestConsecutive(nums) << endl;


    return 0;
}