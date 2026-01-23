/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

// brurte force approach give TLE O(N^2) 
//.     47 / 50 testcases passed
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxfre=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            vector<int> hash(26,0);
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxfre= max(maxfre,hash[s[j]- 'A']);
                int len=j-i+1;
                int ch=len-maxfre;
                if(ch <=k ){
                    maxlen=max(maxlen,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};

// optimal approach O(N)

class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n = s.size();
            int maxLen = 0;
            int maxFreq = 0;
            int l = 0, r = 0;
            vector<int> hash(26, 0);
    
            while (r < n) {
                hash[s[r] - 'A']++;
                maxFreq = max(maxFreq, hash[s[r] - 'A']);
    
                int length = r - l + 1;
    
                if (length - maxFreq > k) {
                    hash[s[l] - 'A']--;
                    l++;
                }
    
                maxLen = max(maxLen, r - l + 1);
    
                r++;
            }
    
            return maxLen;
        }
    };