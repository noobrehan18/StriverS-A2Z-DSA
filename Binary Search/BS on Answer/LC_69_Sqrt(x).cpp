/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.*/

//linear search 
class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        while ((long) i* i<=x){
            i++;
        }
        return i-1;
        
    }
};  // tc-O(sqrt(x)) sc-O(1)

//binary search

class Solution {
public:
    int mySqrt(int x) {
        
        int l=1,r=x;
        int ans=0;
        while(l<=r){
            int mid=(l + (r-l)/2);
            if(mid<=x/mid){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};