class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> u1;
        for(int i=0;i<numbers.size();i++){
            int remain=target-numbers[i];
            if(u1.find(remain)!=u1.end()){
                return{(u1[remain])+1,i+1};
            }
            u1[numbers[i]]=i;
        }
        return {};
    }
};
