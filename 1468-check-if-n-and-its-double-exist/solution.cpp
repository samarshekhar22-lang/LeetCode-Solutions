class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> m1;
        for(int i=0;i<arr.size();i++){
            if(m1.count(arr[i]*2)){
                return true;
            }else if(arr[i]%2==0&& m1.count(arr[i]/2)){
                return true;
            }
            m1[arr[i]]=1;
        }
        return false;
    }
};
