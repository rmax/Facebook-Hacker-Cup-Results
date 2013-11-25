#!/usr/bin/python
# Python 3

# Players come out worst first, then are reinserted best first
# p1 p2 p3 p4, 2 in
# TIMES AT THE START OF EACH SLICE
# [p1:0, p2:0] [p3:0, p4:0]
# p2 out (higher rank), p3 in (lower rank)
# [p1:1, p3:0] [p2:1, p4:0]
# p2 out (higher time), p4 in (lower time)
# [p3:1, p4:0] [p1:2, p2:1]
# p3 out (higher time), p2 in (lower time)
# [p2:1 p4:1] [p1:1 p3:2]
# p4 out (rank), p1 in (time)
# [p1:1, p2:2] [p3:2, p4:2]
# uhhh... times at the end of each slice...
# [p1:1 p2:1] [p3:0 p4:0]
# [p1:2 p3:1] [p2:2 p4:0]
# [p3:2 p4:1] [p1:2 p2:2]
# [p1:3 p4:2] [p3:2 p2:2]
# [p4:3 p2:3] [p1:3 p3:2]

# ... wtf, the limits are so low this can just be crunched

import itertools
import os
import sys
cases = int(input())

def debug(*args):
    #print(*args)
    pass

for case in range(cases):
    (pc, time, onfield) = [int(x) for x in input().split()]
    players = []
    for p in range(pc):
        (name, sp, height) = input().split()
        players.append({'name': name, 'height': int(height), 'rate': int(sp)})
    debug(players)
    debug([(x['rate'], x['height']) for x in players])
    players.sort(key = lambda x: (x['rate'], x['height']), reverse = True)
    debug(players)

    # Split the list into the odd/even bits
    teams = ([x['name'] for i,x in enumerate(players[0::2])],
        [x['name'] for i,x in enumerate(players[1::2])])
    debug(teams)

    # Anonyingly, teams can be assymetrical so this has to be done twice...
    def crunch(np):
        players = [{'rank': i, 'time': 0} for i in range(np)]
        field = players[0:onfield]

        for m in range(time):
            debug(field)

            for p in field:
                p['time'] += 1
            # Find highest time, highest rank, want the one going out at the _back_
            field.sort(key = lambda x: (x['time'], x['rank']), reverse = False)
            debug(field)
            # Lowest time, lowest rank
            players.sort(key = lambda x: (x['time'], x['rank']), reverse = True)
            p_out = field.pop()
            p_in = players.pop()
            field.append(p_in)
            players.append(p_out)

            debug(field)
            debug()

        ret = [x['rank'] for x in field]
        return ret

    if len(teams[0]) < onfield:
        names1 = range(len(teams0))
    else:
        names1 = crunch(len(teams[0]))
    if len(teams[1]) == len(teams[0]):
        names2 = names1
    else:
        if len(teams[1]) < onfield:
            names2 = len(teams[1])
        else:
            names2 = crunch(len(teams[1]))

    names = []
    for p in names1:
        names.append(teams[0][p])
    for p in names2:
        names.append(teams[1][p])
    names.sort()
    print("Case #%s: %s" % (case + 1, " ".join(names)))

