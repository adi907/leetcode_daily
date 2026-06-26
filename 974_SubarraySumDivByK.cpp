#include <iostream>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> sumFrequencyMap;
        int currSum = 0;
        int ans =0;
        sumFrequencyMap[0]=1;
        for(int i=0 ;i<nums.size(); i++){
            currSum = (currSum + nums[i]%k)%k;
            if(currSum < 0){
                currSum += k;
            }
            ans+= sumFrequencyMap[currSum];
            sumFrequencyMap[currSum]++;
        }
    return ans;
    }


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,k,ele;
    vector<int> nums;
    cin>> n;

    for(int i=0 ;i <n;i++){
        cin>> ele;
        nums.push_back(ele);
    }
    cin>> k;

    cout<<subarraysDivByK(nums,k);


    return 0;
}