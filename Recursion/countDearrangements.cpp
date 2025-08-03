class Solution {
  public:
    int countDer(int n) {
        if(n<=1){
            return 0;
        }
        
        if(n==2){
            return 1;
        }
        
        
        return (n-1)*(countDer(n-1)+countDer(n-2));
    }
};