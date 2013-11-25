T = int(raw_input())

def k(p):
    return (int(p[1]), int(p[2]))

def rotate(arr, M, P):
    playing = arr[:P]
    benched = arr[P:]
    
    if not benched: return playing

    for x in xrange(M):
        playing = [p[:3]+[p[3]+1] for p in playing]
        playing.sort(key = lambda p: (-int(p[3]), int(p[1]), int(p[2])))
        benched.sort(key = lambda p: (-int(p[3]), int(p[1]), int(p[2])), reverse=True)

        to_bench = playing[0]
        playing = playing[1:] + [benched[0]]
        benched = benched[1:] + [to_bench]

    return playing

for t in range(1, T+1):
    print "Case #%s:" % t,

    N,M,P = map(int,raw_input().split())

    players = [raw_input().split()+[0] for x in xrange(N)]
    players.sort(key=lambda p: (int(p[1]), int(p[2])), reverse=True)

    t1 = players[::2]
    t2 = players[1::2]

    p1 = rotate(t1, M, P)
    p2 = rotate(t2, M, P)

    final = p1+p2
    final.sort()
    print " ".join(a[0] for a in final)