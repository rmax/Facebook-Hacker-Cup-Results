from sys import stdin

def first():
  for i in xrange(N):
    for j in xrange(N):
      if board[i][j] == '#':
        return i,j

def last():
  for i in xrange(N-1, -1, -1):
    for j in xrange(N-1, -1, -1):
      if board[i][j] == '#':
        return i,j

def test():
  if x0 > x1 or y0 > y1 or x1 - x0 != y1 - y0: return False
  for i in xrange(N):
    for j in xrange(N):
      if i >= x0 and j >= y0 and i <= x1 and j <= y1:
        if board[i][j] == '.': return False
      else:
        if board[i][j] == '#': return False
  return True

T = int(stdin.readline())
for t in xrange(T):
  N = int(stdin.readline())
  board = [stdin.readline() for i in xrange(N)]
  x0, y0 = first()
  x1, y1 = last()
  print 'Case #%d:' % (t+1), 'YES' if test() else 'NO'
