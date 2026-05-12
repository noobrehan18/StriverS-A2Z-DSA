/*You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo"  */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> stCities;
        int n=paths.size();
        for (int i = 0; i < n; i++) {
            stCities.insert(paths[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (stCities.find(paths[i][1]) == stCities.end()) {
                return paths[i][1];
            }
        }
        return "";
    }
};