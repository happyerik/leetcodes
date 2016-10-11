//Sieve of Eratosthenes: algorithm steps for primes
//The Sieve of Eratosthenes uses an extra O(n) memory and its runtime complexity is O(n log log n).
class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i] == false)
                continue;
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
        
        int res = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i] == true) 
                res++;
        return res;
    }
};