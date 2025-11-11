import numpy as np
import scipy
import random
from mip import Model, xsum, BINARY, OptimizationStatus
seed = 42
rangex = 1000
N=30
K=4

M=np.array([ [rangex*(random.random()) for j in range(K)] for i in range(N) ])
for i in M:
  i[0] = np.abs(i[0])
print(M)

def envy(A, M, mode="std"):
    # A, M are shape (N, K); A has entries in {+1, -1} with exactly one +1 per row
    if not np.all(np.sum(A == 1, axis=1) == 1):
        raise ValueError("A has multiple (or zero) +1s in a row. expected exactly one per row")

    # PE_p = sum_i M[i,p]*ReLU(A[i,p]) - 2*sum_i M[i,p]*A[i,p]
    reluA = np.maximum(A, 0)                      # ReLU on {+1,-1} -> {1,0}
    PE = np.sum(M * reluA, axis=0) - 2*np.sum(M * A, axis=0)

    if mode == "std":
        return float(PE.std(ddof=0))
    elif mode == "mae":
        return float(np.mean(np.abs(PE - PE.mean())))
    else:
        raise ValueError("mode wrong")

# simple solve: try every single combination and compute envy
# complexity： N^(K+1)

def solve_simple(mode="std"):
    N, K = M.shape
    best_score = float("inf")
    A_best = None
    for assign in np.ndindex(*(K,) * N):
        A = -np.ones((N, K), dtype=int)
        A[np.arange(N), assign] = 1
        score = envy(A, M, mode)
        if score < best_score:
            best_score = score
            A_best = A
    if A_best is None:
        print("none found")
        return
    reluA = (A_best > 0).astype(int)
    util = np.sum(M * reluA, axis=0)
    N, K = A_best.shape
    for p in range(K):
        items = np.where(A_best[:, p] == 1)[0].tolist()  # 0-based indices
        print(f"Person {p} received items: {items}")
        print(f"  Utility: {util[p]:.6g}")

    # Print both global envy metrics for the chosen assignment
    mae = envy(A_best, M, mode="mae")
    std = envy(A_best, M, mode="std")
    print(f"Final MAE envy: {mae:.6g}")
    print(f"Final STDDEV envy: {std:.6g}")
    print(f"(Assignment chosen by minimizing {'MAE' if mode=='mae' else 'STDDEV'})")

def solve_mae(M, time_limit=None, verbose=True):
    M = np.asarray(M, dtype=float)
    N, K = M.shape
    
    c = M.sum(axis=0)
    
    m = Model(sense='MIN', solver_name='CBC')
    if time_limit is not None:
        m.max_seconds = float(time_limit)
    
    x = [[m.add_var(var_type=BINARY, name=f"x_{i}_{p}") for p in range(K)] for i in range(N)]
    
    for i in range(N):
        m += xsum(x[i][p] for p in range(K)) == 1
    pe_expr = []
    for p in range(K):
        pe = -3.0 * xsum(M[i, p] * x[i][p] for i in range(N)) + 2.0 * float(c[p])
        pe_expr.append(pe)
    
    mu = m.add_var(name="mu")
    u  = [m.add_var(lb=0.0, name=f"u_{p}") for p in range(K)]
    
    m += K * mu == xsum(pe_expr[p] for p in range(K))
    
    for p in range(K):
        m += u[p] >= pe_expr[p] - mu
        m += u[p] >= mu - pe_expr[p]
    
    m.objective = xsum(u[p] for p in range(K)) / K
    m.optimize()
    
    status = m.status
    if status not in (OptimizationStatus.OPTIMAL, OptimizationStatus.FEASIBLE):
        print(f"Solver ended with status:{status}")
        return
    
    assign = np.array([np.argmax([x[i][p].x for p in range(K)]) for i in range(N)], dtype=int)
    A = -np.ones((N, K), dtype=int)
    A[np.arange(N), assign] = 1
    
    reluA = (A > 0).astype(int)
    util  = (M * reluA).sum(axis=0)
    PE    = -3.0 * util + 2.0 * c
    
    mae = float(np.mean(np.abs(PE - PE.mean())))
    std = float(PE.std(ddof=0))
    
    if verbose:
        for p in range(K):
            items = np.where(A[:, p] == 1)[0].tolist()
            print(f"Person {p} received items: {items}")
            print(f"  Utility: {util[p]:.6g}")
        print(f"Final MAE envy: {mae:.6g}")
        print(f"Final STDDEV envy: {std:.6g}")
        if status == OptimizationStatus.OPTIMAL:
            print("(Proved optimal for MAE)")
        else:
            print("(Feasible solution; not proved optimal)")

    # print-only API: return nothing
    return None



