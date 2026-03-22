/*Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will be the same.

 

Example 1:

Input: houses = [1,2,3], heaters = [2]
Output: 1*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int radius = 0;
        
        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            
            int distRight = INT_MAX;
            int distLeft = INT_MAX;
            
            // Heater on the right
            if (it != heaters.end()) {
                distRight = *it - house;
            }
            
            // Heater on the left
            if (it != heaters.begin()) {
                distLeft = house - *(it - 1);
            }
            
            int closest = min(distLeft, distRight);
            radius = max(radius, closest);
        }
        
        return radius;
    }
};