# define ll long long int
class Solution {
public:

ll power(ll a,ll n,ll mod){
        ll res=1;
        while(n){
        if(n%2==1){
            res=(res*a)%mod;
            n--;
        }
        else{
            a=(a*a)%mod;
            n/=2;
        }
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mod=1e9+7;
        int l=0,r=nums.size()-1;
        long long res=0;
        while(l<=r){
            if(nums[l]+nums[r]>target){
                r--;
            }
            else{
                res=res+(power(2,r-l,mod));
                l++;
            }
        }
        return res%mod;
    }
};