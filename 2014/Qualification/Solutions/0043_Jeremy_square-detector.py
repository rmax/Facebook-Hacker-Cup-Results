#!/usr/bin/python
import os

def debug(*args):
    #print(*args)
    pass

cases = int(input())
for case in range(cases):
    done = False
    borders = None
    lines = int(input())
    firstline = -1
    squared = False

    def result(res):
        global done
        global squared
        print("Case #%s: %s" % (case + 1, res))
        done = True
        squared = False

    for li in range(lines + 1):
        # Inject a dummy final line
        if li == lines:
            line = "."
        else:
            line = input().strip()

        if done:
            continue
        
        debug(line)

        left = line.find("#")
        right = line.rfind("#")+1
        debug("left: %s right: %s" % (left, right))

        if left == -1:
            if squared or not borders:
                continue
            if borders:
                if not squared and li - firstline == borders[1] - borders[0]:
                    squared = True
                    debug("Found square")
                    continue
                elif not squared:
                    debug("Height mismatch")
                    result('NO')
                    continue
        else:
            if squared:
                debug('Junk outside square')
                result('NO')
                continue


        if line[left:right].find('.') != -1:
            debug("Stuff inside block")
            result('NO')
            continue
        #debug(line[left:right])
        # This is actually redundant...
        if line[left:right].count("#") != right - left or\
                line.count("#") != right - left:
            debug("Stuff outside block")
            result('NO')
            continue

        if borders and (left != borders[0] or right != borders[1]):
            debug("Border mismatch")
            result('NO')
            continue

        if borders is None:
            borders = (left, right)
            firstline = li
            debug("Set borders to %s %s" % borders)
            continue
    if squared:
        result('YES')

