class Solution {
public:
    int prefixStrings(int n) {
        long long MOD = 1e9 + 7;

        // Helper lambda for modular exponentiation
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        // Helper lambda for modular inverse using Fermat's Little Theorem
        auto modInverse = [&](long long k) {
            return power(k, MOD - 2);
        };

        long long num = 1;
        long long den = 1;

        // Calculate (2n)! / (n! * n!) which simplifies to the product of (n + i) / i
        for (int i = 1; i <= n; ++i) {
            num = (num * (n + i)) % MOD;
            den = (den * i) % MOD;
        }

        // Calculate C_n = (num / den) / (n + 1)
        long long ans = (num * modInverse(den)) % MOD;
        ans = (ans * modInverse(n + 1)) % MOD;

        return (int)ans;
    }
};