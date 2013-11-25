
def play(players,M,P):
    N           = len(players)
    active      = [ True if n<P else False for n in range(N) ]
    time_played = [ 0 for n in range(N) ]

    if N==P: return players

    for m in range(M):

        for n in range(N):
            if active[n]: time_played[n] += 1

        bestout, bt = None, -1
        for n in range(N):
            if active[n] and time_played[n]>=bt: bestout, bt = n, time_played[n]

        bestin, bt = None, M+1
        for n in range(N):
            if not active[n] and time_played[n] < bt: bestin, bt = n, time_played[n]
        
        active[bestin] = True
        active[bestout] = False

    return [ players[n] for n in range(N) if active[n] ]

T = int( input() )
for t in range(1,T+1):
    N, M, P = [ int(x) for x in input().split() ]
    players = []
    for n in range(N):
        row = input().split()
        players.append( ( int(row[1]), int(row[2]), row[0] ) )
    players.sort()
    T1 = [ x[2] for x in players[-1::-2] ]
    T2 = [ x[2] for x in players[-2::-2] ]
    answer = play(T1,M,P) + play(T2,M,P)
    answer.sort()
    print('Case #{}: {}'.format(t,' '.join(answer)))
