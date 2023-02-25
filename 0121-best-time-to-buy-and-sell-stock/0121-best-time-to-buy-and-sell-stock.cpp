class Solution {
public:
int maxProfit(vector<int>& prices) 
    {
         int least = INT_MAX;
         int profit=0;
         int price = 0;
         
         for(int i=0;i<prices.size();i++){
             if(prices[i] < least) least = prices[i];
             
             price = prices[i] - least;
             
             if(price > profit) profit = price;
         }
         
         return profit;
        }
    
    
};
