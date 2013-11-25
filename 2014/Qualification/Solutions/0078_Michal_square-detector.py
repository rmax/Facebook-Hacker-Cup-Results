T = int( input() )
for t in range(1,T+1):
    N = int( input() )
    A = [ input() for n in range(N) ]
    rlo, rhi, clo, chi, cnt = N, -1, N, -1, 0
    for r in range(N):
        for c in range(N):
            if A[r][c] == '#':
                rlo = min( rlo, r )
                rhi = max( rhi, r )
                clo = min( clo, c )
                chi = max( chi, c )
                cnt = cnt+1
    if rhi-rlo == chi-clo:
        expected_cnt = (rhi-rlo+1)**2
        square = (cnt == expected_cnt)
    else:
        square = False
    print('Case #{}: {}'.format(t,'YES' if square else 'NO'))
