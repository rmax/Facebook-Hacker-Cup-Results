T = input()
for tc in range(1, T + 1):
  N = input()
  minX, minY, maxX, maxY, count = 50, 50, -1, -1, 0
  x = 0
  for l in range(N):
    y = 0
    for c in raw_input():
      if c == '#':
        count += 1
        minX = min(minX, x)
        minY = min(minY, y)
        maxX = max(maxX, x)
        maxY = max(maxY, y)
      y += 1
    x += 1
  xDim = maxX - minX + 1
  yDim = maxY - minY + 1
  print "Case #" + str(tc) + ":",
  print "YES" if xDim == yDim and xDim * yDim == count else "NO"
