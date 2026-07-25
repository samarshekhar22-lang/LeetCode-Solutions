class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> s1;
        for(int i=0;i<op.size();i++){
            if(op[i]=="+"){
                int a=s1.top();
                s1.pop();
                int a1=s1.top();
                s1.push(a);
                int a2=a+a1;
                s1.push(a2);
            }else if(op[i]=="D"){
                int a3=s1.top()*2;
                s1.push(a3);
            }else if(op[i]=="C"){
                s1.pop();
            }else{
                s1.push(stoi(op[i]));
            }
        }
        int sum=0;
        while(!s1.empty()){
            int a5=s1.top();
            s1.pop();
            sum+=a5;
        }
        return sum;
    }
};
