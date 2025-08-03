int solve(int n, vector<int> &arr){
    //base case
    if(n==1||n==0){
        return n;
    }

    if(arr[n]!=-1){
        return arr[n];
    }

    int res= solve(n-1,arr)+solve(n-2,arr);
    arr[n]=res;
    return res;


}
int fib(int n) {
    vector<int> arr(n+1,-1);
    return solve(n,arr);
}