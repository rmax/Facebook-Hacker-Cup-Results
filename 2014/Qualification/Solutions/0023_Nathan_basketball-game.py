T = input()
for tc in range(1, T + 1):
  N, M, P = [int(x) for x in raw_input().split(" ")]
  players = []
  for i in range(N):
    ln = raw_input().split(" ")
    players.append([0, -int(ln[1]), -int(ln[2]), ln[0]])
  players.sort()
  court1 = []
  bench1 = []
  court2 = []
  bench2 = []
  for i in range(N):
    if i % 2:
      if i < 2 * P:
        court1.append(players[i])
      else:
        bench1.append(players[i])
    else:
      if i < 2 * P:
        court2.append(players[i])
      else:
        bench2.append(players[i])
  if 2 * P < N:
    for i in range(M):
      for p in court1:
        p[0] += 1
      for p in court2:
        p[0] += 1
      court1.sort()
      court2.sort()
      bench1.sort()
      bench2.sort()
      tmp = court1[-1]
      court1[-1] = bench1[0]
      bench1[0] = tmp
      tmp = court2[-1]
      court2[-1] = bench2[0]
      bench2[0] = tmp
  names = [x[3] for x in court1] + [x[3] for x in court2]
  print "Case #" + str(tc) + ":", ' '.join(sorted(names))
