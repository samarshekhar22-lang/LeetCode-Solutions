static bool countFreq(pair<int,int> &p1, pair<int,int>&p2){
    return p1.second>p2.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mm;
        for(int i=0;i<nums.size();i++){
            mm[nums[i]]++;
    }
    vector<pair<int, int>>store;
    for(auto i:mm){
        store.push_back(i);
    }
    sort(store.begin(),store.end(),countFreq);
    vector<int> finalAns;
    for(int i=0;i<k;i++){
        finalAns.push_back(store[i].first);
    }
    return finalAns;
};
};
