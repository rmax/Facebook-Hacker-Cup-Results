from sys import stdin

T = int(stdin.readline())
for t in xrange(T):
  N,M,P = map(int, stdin.readline().split())
  guys = []
  for i in xrange(N):
    tmp = stdin.readline().split()
    guys.append([-int(tmp[1]), -int(tmp[2]), tmp[0]])
  guys.sort()
  for i in xrange(N):
    guys[i] = [0, i, guys[i][2]]
  aon = guys[0:2*P:2]
  aoff = guys[2*P:N:2]
  bon = guys[1:2*P:2]
  boff = guys[2*P+1:N:2]
  for m in xrange(M):
    for g in aon: g[0] += 1
    for g in bon: g[0] += 1
    if len(aoff) > 0:
      g = max(aon)
      gg = min(aoff)
      aon.remove(g)
      aoff.remove(gg)
      aon.append(gg)
      aoff.append(g)
    if len(boff) > 0:
      g = max(bon)
      gg = min(boff)
      bon.remove(g)
      boff.remove(gg)
      bon.append(gg)
      boff.append(g)
  guys = aon+bon
  for i in xrange(2*P):
    guys[i] = guys[i][2]
  guys.sort()
  print 'Case #%d: %s' % (t+1, ' '.join(guys))
