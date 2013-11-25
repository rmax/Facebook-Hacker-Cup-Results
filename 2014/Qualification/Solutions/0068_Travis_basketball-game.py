import sys

class Player:
    def __init__(self, name, rank, time):
        self.name = name
        self.rank = rank
        self.time = time

def argmax(l, fn):
    res = None
    val = None
    for x in l:
        v = fn(x)
        if res == None or v > val:
            res = x
            val = v
    return res

def get(team, m, p):
    team = [Player(team[i][0], i, 0) for i in xrange(len(team))]
    cur_in = team[0:p]
    cur_out = team[p:]
    for i in xrange(m):
        for pl in cur_in:
            pl.time += 1
        leaving_player = argmax(cur_in, lambda pl : (pl.time, pl.rank))
        cur_in.remove(leaving_player)
        cur_out.append(leaving_player)

        entering_player = argmax(cur_out, lambda pl : (-pl.time, -pl.rank))
        cur_out.remove(entering_player)
        cur_in.append(entering_player)
    return [pl.name for pl in cur_in]

ncases = int(sys.stdin.readline().strip())
for c in xrange(ncases):
    n, m, p = [int(x) for x in sys.stdin.readline().split()]
    players = []
    for i in xrange(n):
        player, perc, height = sys.stdin.readline().split()
        players.append((player, int(perc), int(height)))
    players.sort(key = lambda (_,a,b) : (-a,-b))
    team1 = players[0::2]
    team2 = players[1::2]
    s = get(team1, m, p)
    t = get(team2, m, p)
    print "Case #%d: %s" % (c+1, " ".join(sorted(s + t)))
