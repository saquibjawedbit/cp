def solve():
    import sys,sys
    data = sys.stdin.read().strip().split()
    if not data: 
        return
    it = iter(data)
    t = int(next(it))
    out_lines = []
    import bisect


    def build_next_diff(a, n):
        next_diff = [0]*(n+2)
        next_diff[n] = n+1
        next_diff[n+1] = n+1
        for i in range(n-1, 0, -1):
            if a[i+1] == a[i]:
                next_diff[i] = next_diff[i+1]
            else:
                next_diff[i] = i+1
        return next_diff
    def query_eq(X, L, R):
        if X not in pos_by_val: 
            return None
        lst = pos_by_val[X]
        idx = bisect.bisect_left(lst, L)
        if idx < len(lst) and lst[idx] <= R:
            return lst[idx]
        return None

    def query_dev(X, L, R):
        if L > R: 
            return None
        if a[L] != X:
            return L
        nd = next_diff[L]
        if nd <= R:
            return nd
        return None

    for _ in range(t):
        n = int(next(it)); k = int(next(it))
    
        a = [None]
        for i in range(n):
            a.append(int(next(it)))
        r = k // 2

        next_diff = [0]*(n+2)
        next_diff[n] = n+1
        next_diff[n+1] = n+1
        for i in range(n-1, 0, -1):
            if a[i+1] == a[i]:
                next_diff[i] = next_diff[i+1]
            else:
                next_diff[i] = i+1

    
        pos_by_val = {}
        for i in range(1, n+1):
            val = a[i]
            if val not in pos_by_val:
                pos_by_val[val] = []
            pos_by_val[val].append(i)
            

        def new_group_upper(g_next):
            return n - k + 2*g_next

     
        def same_group_limit(g):
            if g < r:
                return n - 2*(r - g)
            else:
                return n


        L_bound = 2
        U_bound = new_group_upper(1) 
        cand = query_dev(1, L_bound, U_bound)
        if cand is not None:
            out_lines.append("1")
            continue


        dp = {}
      
        cand_eq = query_eq(1, L_bound, U_bound)
        if cand_eq is None:
     
            out_lines.append("1")
            continue
        dp[1] = {1: cand_eq}
        ans = None
        forced = 1
        
        while True:
            exp_val = forced + 1
            found_deviation = False
            for g, pos in dp[forced].items():
              
                nxt = pos + 1
                if nxt <= same_group_limit(g) and nxt <= n:
                    if a[nxt] != exp_val:
                        found_deviation = True
                        break
              
                if g < r:
                    L_new = pos + 2
                    U_new = new_group_upper(g+1)
                    if L_new <= U_new:
                        cand_dev = query_dev(exp_val, L_new, U_new)
                        if cand_dev is not None:
                            found_deviation = True
                            break
            if found_deviation:
                ans = exp_val
                break
       
            next_dp = {}
            for g, pos in dp[forced].items():
          
                nxt = pos + 1
                if nxt <= same_group_limit(g) and nxt <= n:
                    if a[nxt] == exp_val:
                        if g in next_dp:
                            if nxt < next_dp[g]:
                                next_dp[g] = nxt
                        else:
                            next_dp[g] = nxt
 
                if g < r:
                    L_new = pos + 2
                    U_new = new_group_upper(g+1)
                    if L_new <= U_new:
                        cand_eq_new = query_eq(exp_val, L_new, U_new)
                        if cand_eq_new is not None:
                            newg = g + 1
                            if newg in next_dp:
                                if cand_eq_new < next_dp[newg]:
                                    next_dp[newg] = cand_eq_new
                            else:
                                next_dp[newg] = cand_eq_new
            if not next_dp:
               
                ans = forced + 1
                break
            forced += 1
            dp[forced] = next_dp
        out_lines.append(str(ans))
    sys.stdout.write("\n".join(out_lines))
    
if __name__ == '__main__':
    solve()
