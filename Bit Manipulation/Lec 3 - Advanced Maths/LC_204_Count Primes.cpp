/*Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
// brute force approach
class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i))
                cnt++;
        }
        return cnt;
    }
};

// optimised approach - Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        
        vector<bool>isprime(n,true);
        isprime[0]=isprime[1]=false;

        for(int i=2;i*i<n;i++){
            if(isprime[i]){
                for(int j=i*i;j<n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                cnt++;
            }
        }
        return cnt;

    }
};