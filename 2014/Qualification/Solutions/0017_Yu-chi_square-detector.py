with open('input.txt', 'r') as f:
  with open('output', 'w') as of:
    tot_rnds = int(f.readline())
    for ri in range(tot_rnds):
      N = int(f.readline())
      x1 = N
      x2 = 0
      y1 = N
      y2 = 0
      cnt = 0
      for y in range(N):
        line = f.readline()
        for x in range(N):
          if line[x] == '#':
            cnt += 1
            if x < x1:
              x1 = x
            if x > x2:
              x2 = x
            if y < y1:
              y1 = y
            if y > y2:
              y2 = y
      dx = x2 - x1 + 1
      dy = y2 - y1 + 1
      if dx == dy and dx * dy == cnt:
        of.write("Case #%d: YES\n" % (ri + 1))
      else:
        of.write("Case #%d: NO\n" % (ri + 1))

