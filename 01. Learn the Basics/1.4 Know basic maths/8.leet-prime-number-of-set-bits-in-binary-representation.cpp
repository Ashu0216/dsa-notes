class Solution {
public:
    bool isPrimeBits(int x){
        return ( x==2 || x==3 || x==5 || x==7 ||x==11 ||x==13 ||
            x==17 || x==19);

        // If that number is 2, 3, 5, 7, 11, 13, 17, or 19, then we add one to our count. We only need primes up to 19 because R≤10 ^6 < 2^20
    }

    int countSetBits(int n){
        int count = 0;
        while (n > 0) {
            n &= (n - 1); // Turns off the rightmost set bit
            count++;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {

        int ans = 0;

        for(int x = left ; x <= right ; x++){
            if( isPrimeBits(countSetBits(x)))
                ans++;
        }
        return ans;
        
    }
};

/*
╭──────────────────────────────────────────────────────────────╮
│                         Complexity                           │
├──────────────────────────────────────────────────────────────┤
│  Time  : O(D)                                                │
│          (D = R − L, number of integers processed)           │
│          Bit-counting variant → O(D log D)                   │
│--------------------------------------------------------------│
│  Space : O(1)                                                │
│--------------------------------------------------------------│
│  Notes : Each number is processed once                       │
│          Log factor appears if bit counting is explicit      │
╰──────────────────────────────────────────────────────────────╯
*/

// Link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/submissions/1926659286/?source=submission-ac