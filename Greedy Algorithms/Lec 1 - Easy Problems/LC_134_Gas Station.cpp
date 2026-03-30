/*There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int tank=0;
        int st=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            tank+=diff;
            if(tank<0){
                st=i+1;
                tank=0;
            }
        }
        if(total>=0){
            return st;
        }
        else{
            return -1;
        }
    }
};