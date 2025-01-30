#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

// Multiply two k×k matrices (A*B) % MOD
vector<vector<long long>> matMul(const vector<vector<long long>>& A,
                                 const vector<vector<long long>>& B, int k) {
    vector<vector<long long>> C(k, vector<long long>(k, 0LL));
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            __int128 sum = 0; // use 128-bit to avoid overflow before mod
            for(int r=0; r<k; r++){
                sum += (__int128)A[i][r] * B[r][j];
            }
            C[i][j] = (long long)(sum % MOD);
        }
    }
    return C;
}

// Add two k×k matrices (A+B) % MOD
vector<vector<long long>> matAdd(const vector<vector<long long>>& A,
                                 const vector<vector<long long>>& B, int k){
    vector<vector<long long>> C(k, vector<long long>(k, 0LL));
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            long long s = A[i][j] + B[i][j];
            if(s >= MOD) s -= MOD;
            C[i][j] = s;
        }
    }
    return C;
}

// Identity matrix of size k
vector<vector<long long>> matIdentity(int k){
    vector<vector<long long>> I(k, vector<long long>(k, 0LL));
    for(int i = 0; i < k; i++){
        I[i][i] = 1;
    }
    return I;
}

/*
  We want the sum S(e) = M^1 + M^2 + ... + M^e for a k×k matrix M.
  We'll do this with a divide-and-conquer approach in O(k^3 log e):
   - If e=1, return M.
   - If e is even, let half = S(e/2). Then S(e) = half + M^(e/2)*half.
   - If e is odd, S(e) = S(e-1) + M^e.
*/
pair<vector<vector<long long>>, vector<vector<long long>>> matSumPow(
        const vector<vector<long long>>& M, long long e, int k) {
    // Returns (S(e), M^e)
    // Where S(e) = M^1 + M^2 + ... + M^e, all modded
    if(e == 1){
        // S(1) = M, M^1 = M
        return make_pair(M, M);
    }
    // Recur
    if(e % 2 == 0){
        auto half = matSumPow(M, e/2, k); 
        // half.first = S(e/2), half.second = M^(e/2)
        // M^(e/2)*S(e/2)
        auto temp = matMul(half.second, half.first, k);
        // S(e) = S(e/2) + M^(e/2)*S(e/2)
        auto S_e = matAdd(half.first, temp, k);
        // M^e = (M^(e/2))^2
        auto M_e = matMul(half.second, half.second, k);
        return make_pair(S_e, M_e);
    } else {
        // e is odd
        // S(e-1), M^(e-1)
        auto minus1 = matSumPow(M, e-1, k);
        // M^e = M^(e-1)*M
        auto M_e = matMul(minus1.second, M, k);
        // S(e) = S(e-1) + M^e
        auto S_e = matAdd(minus1.first, M_e, k);
        return make_pair(S_e, M_e);
    }
}

// Multiply matrix A and vector V (both size k) -> vector of dimension k
vector<long long> matVec(const vector<vector<long long>>& A,
                         const vector<long long>& V, int k) {
    vector<long long> R(k, 0LL);
    for(int i=0; i<k; i++){
        __int128 sum = 0;
        for(int j=0; j<k; j++){
            sum += (__int128) A[i][j] * V[j];
        }
        R[i] = (long long)(sum % MOD);
    }
    return R;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        long long k, n; 
        cin >> k >> n;  // k up to 10, n up to ~9e8 possible

        // Build the transition matrix M of size k×k
        // Rows,cols indexed [0..k-1], representing product states i+1 -> j+1
        // M[i][j] = 1 if (i+1)*g = (j+1) for some g in [1..k], else 0
        // But there's at most one g = (j+1)/(i+1), if divisible and <= k
        // So effectively:
        //   if (j+1) % (i+1) == 0 and (j+1)/(i+1) <= k => M[i][j]=1 else 0
        vector<vector<long long>> M(k, vector<long long>(k, 0LL));
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                // i+1 -> j+1
                long long num = j+1;      // prospective new product
                long long denom = i+1;    // old product
                if(num % denom == 0) {
                    long long g = num / denom;
                    if(g >= 1 && g <= k) {
                        M[i][j] = 1; 
                    }
                }
            }
        }

        // Compute S(n) = M^1 + M^2 + ... + M^n, all modulo
        // We'll do this even if n is huge (e.g., 7e6), by using matSumPow with O(k^3 log n).
        auto sumPowPair = matSumPow(M, n, (int)k);
        // sumPowPair.first == S(n), the sum of powers
        // sumPowPair.second == M^n

        auto& S_of_n = sumPowPair.first;

        // Multiply S(n) by the vector V(1), where V(1)[0] = 1, others 0
        // This will give us the total ways (over d=1..n) to reach product x in position x−1
        vector<long long> V1(k, 0LL);
        V1[0] = 1; // product=1 is the starting state
        auto result = matVec(S_of_n, V1, (int)k);


        for(int x=0; x<(int)k; x++){
            cout << result[x];
            if(x+1 < k) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}