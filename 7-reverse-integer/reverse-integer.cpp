class Solution {
public:
    int reverse(int x) {
        long long number=0;
        while(x!=0){
           int r=x%10;
            number=number*10+r;
            x=x/10;
        }
        if(number<=INT_MAX && number>=INT_MIN){
            return number;
        }
        return 0;
    }
};