def advance(t1, t2, ct1, ct2):
  P = len(ct1)
  # incr minute
  for n in ct1:
    m, _ = t1[n]
    t1[n] = (m + 1, n)
  for n in ct2:
    m, _ = t2[n]
    t2[n] = (m + 1, n)

  try:
    b1 = min([v for k, v in t1.iteritems() if k not in ct1])
  except ValueError:
    return
  s1 = max([t1[a] for a in ct1])
  ct1.remove(s1[1])
  ct1.append(b1[1])

  try:
    b2 = min([v for k, v in t2.iteritems() if k not in ct2])
  except ValueError:
    return
  s2 = max([t2[a] for a in ct2])
  ct2.remove(s2[1])
  ct2.append(b2[1])


with open('input2.txt', 'r') as f:
  with open('output2.txt', 'w') as of:
    T = int(f.readline())
    for ti in range(T):
      nums = f.readline().split(' ')
      N = int(nums[0])
      M = int(nums[1])
      P = int(nums[2])
      people = []
      for _ in range(N):
        items = f.readline().split(' ')
        people.append((int(items[1]), int(items[2]), items[0]))
      people.sort(reverse=True)
      team1 = [(i, p[2]) for i, p in enumerate(people) if i % 2 == 0]
      team2 = [(i, p[2]) for i, p in enumerate(people) if i % 2 == 1]
      ct1 = team1[:P]
      ct2 = team2[:P]
      t1 = {p: (0, p) for p in team1}
      t2 = {p: (0, p) for p in team2}
      for _ in range(M):
        advance(t1, t2, ct1, ct2)
      names = sorted([i[1] for i in ct1 + ct2])
      print "Case #%d: %s" % (ti + 1, ' '.join(names))
      of.write("Case #%d: %s\n" % (ti + 1, ' '.join(names)))


