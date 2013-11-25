#!/usr/bin/python
# Python3
import math

def debug(*args):
    #print(*args)
    pass

cases = int(input())


for case in range(cases):
    parts = input().split()
    sets = int(parts[0])
    (ps, pr, pi, pu, pw, pd, pl) = (float(x) for x in parts[1:])
    pw1 = 1.0 - pw
    pl1 = 1.0 - pl
    debug("ps: %s, pr: %s, pi: %s, pu: %s, pw: %s, pd: %s, pl: %s" % (ps, pr, pi, pu, pw, pd, pl))

    store = {}

    win_prob = 0.0
    hits = 0
    misses = 0

    def branch(wins, losses, sun):
        global win_prob, hits, misses

        # 10e8 isn't significantly faster so avoid the risk of inaccuracy
        sun = math.floor(sun*10e9 + 0.5) / 10e9
        key = (sun, wins, losses)
        if key in store:
            hits += 1
            return store[key]
        else:
            misses += 1
        win = sun * ps + (1-sun) * pr
        #debug("Win prob: %s" % win_prob)
        lose = 1.0 - win
        
        total_prob = 0.0

        # Do the check here or the prob will be added twice
        if wins + 1 == sets:
            total_prob = win
        else:
            # Ugh, 4 branches - win/sun up, win/no change, lose/sun down...
            # Chance of getting here: prob * win_prob * (1-p_w)
            total_prob += branch(wins+1, losses, sun) *  win * pw1
            # Chance of getting here: prob * win_prob * p_w
            total_prob += branch(wins+1, losses, min(1.0, sun + pu)) * win * pw

        if losses + 1 < sets:
            total_prob += branch(wins, losses+1, sun) * lose * pl1
            total_prob += branch(wins, losses+1, max(0.0, sun - pd)) * lose * pl

        #if total_prob > 1.0:
        #    print("ERROR: Probability over: %s" % total_prob)

        store[key] = total_prob
        return total_prob

    tp = branch(0, 0, pi)
    debug("Hits: %s Misses: %s" % (hits, misses))
    # debug(store)
    print("Case #%s: %06f" % (case + 1, tp))

