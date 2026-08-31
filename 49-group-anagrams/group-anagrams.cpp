class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string i:strs){
            string temp=i;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> result;
        for(auto it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};