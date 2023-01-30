class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        int arr[38];
        arr[0]=0,arr[1]=arr[2]=1;
        int i=3;
        for(i=3;i<=n;i++)
        {
            arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
            
        }
        return arr[i-1];
        
    }
};