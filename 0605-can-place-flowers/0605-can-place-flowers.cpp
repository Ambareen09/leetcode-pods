class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                int tempcount=0;
                while(i<flowerbed.size() && flowerbed[i]==0 ){
                    tempcount++;
                    i++;
                }
                n-=(tempcount-1)/2;
             }
        }
        return n<=0;
    }
};