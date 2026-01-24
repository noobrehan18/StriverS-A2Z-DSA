vector<int> minPartition(int N) {
    
    vector<int> denomination = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    
    vector<int> result; 

   
    for (int i = 0; i < denomination.size(); i++) {
        while (N >= denomination[i]) { 
            N -= denomination[i];  
            result.push_back(denomination[i]); 
        }
    }
    
    return result;
}

// sheet qs 
class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
	    
	    sort(coins.rbegin(), coins.rend());
	    
	    int count = 0;

	    for(int i = 0; i < coins.size(); i++) {
	        while(amount >= coins[i]) {
	            amount -= coins[i];
	            count++;
	        }
	    }
	    if(amount != 0) return -1;

	    return count;
	}
};
