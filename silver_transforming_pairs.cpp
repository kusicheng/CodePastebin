#include <iostream>
using namespace std;

// Define a simple 2x2 matrix structure
struct Matrix {
    // Matrix represented as:
    // [ a  b ]
    // [ c  d ]
    long long a, b, c, d;
};

// Multiply two 2x2 matrices: returns M * N.
Matrix multiply(const Matrix &M, const Matrix &N) {
    Matrix R;
    R.a = M.a * N.a + M.b * N.c;
    R.b = M.a * N.b + M.b * N.d;
    R.c = M.c * N.a + M.d * N.c;
    R.d = M.c * N.b + M.d * N.d;
    return R;
}

// Recursive function to get the transformation matrix M,
// such that (c, d) = (a, b) * M.
Matrix get_matrix(long long A, long long B, long long C, long long D) {
    // Base case: we have reached the starting pair.
    if (C == A && D == B) {
        // Identity matrix
        return {1, 0, 0, 1};
    }
    
    // If C > D then the last forward move was:
    // (x, y) -> (x+y, y) which corresponds to multiplying by A = [[1,1],[0,1]].
    // Reverse by subtracting D from C.
    if (C > D) {
        long long k = (C - A) / D;
        if (k < 1) k = 1;  // ensure at least one subtraction
        long long newC = C - k * D;
        Matrix M_prev = get_matrix(A, B, newC, D);
        // A^k = [[1, k],[0, 1]]
        Matrix A_k = {1, k, 0, 1};
        return multiply(M_prev, A_k);
    }
    // Otherwise, if D > C then the last forward move was:
    // (x, y) -> (x, x+y) corresponding to multiplying by B = [[1,0],[1,1]].
    else {
        long long k = (D - B) / C;
        if (k < 1) k = 1;  // ensure at least one subtraction
        long long newD = D - k * C;
        Matrix M_prev = get_matrix(A, B, C, newD);
        // B^k = [[1, 0],[k, 1]]
        Matrix B_k = {1, 0, k, 1};
        return multiply(M_prev, B_k);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    // Input: a, b, c, d where a < b < c < d.
    cin >> a >> b >> c >> d;

    // Recover the transformation matrix M such that (c,d) = (a,b)*M.
    Matrix M = get_matrix(a, b, c, d);

    // Output alpha, beta, gamma, delta.
    cout << M.a << " " << M.b << " " << M.c << " " << M.d << "\n";

    return 0;
}

