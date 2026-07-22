class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> ans;
        for(int i=0;i<heights.size();i++){
            ans.push_back({heights[i],names[i]});
        }
        vector<string> result;
        sort(ans.begin(),ans.end());
        for(int i=heights.size()-1;i>=0;i--){
            result.push_back(ans[i].second);
        }
        return result;
    }
};
