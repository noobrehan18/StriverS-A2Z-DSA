/*
Check if the Array is Sorted II

Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.
Examples:
Input : nums = [1, 2, 3, 4, 5]
Output : true
Explanation : For all i (1 <= i <= 4) it holds nums[i] <= nums[i+1], hence it is sorted and we return true.
Input : nums = [1, 2, 1, 4, 5]
Output : false
Explanation : For i == 2 it does not hold nums[i] <= nums[i+1], hence it is not sorted and we return false.*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// sheet solution->
class Solution{	
	public:
		bool isSorted(vector<int>& nums){
			for(int i=1;i < nums.size();i++){               //T.C-> O(n)
                if(nums[i]<nums[i-1]){
                     return false;

                }   
            }
            return true;
		}       
};

// approach->2
bool isSorted(int arr[], int n){
    for(int i=1; i<n;i++){
        if(arr[i]>=arr[i-1]){

        }else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if (isSorted(arr, n)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }
return 0;

}
