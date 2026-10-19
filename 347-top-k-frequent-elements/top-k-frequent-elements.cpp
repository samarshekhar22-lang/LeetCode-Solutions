class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
        for(int i:nums){
            m1[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i :m1){
            pq.push({i.second, i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
        auto save=pq.top();
        pq.pop();
        ans.push_back(save.second);
        }
        return ans;     
    }
};