class Solver(object):
  def __init__(self, K, probs):
    self.K = K
    (self.ps, self.pr, self.pi, self.pu, self.pw, self.pd, self.pl) = probs
    self.cache = {}

  def solve(self, swin, owin, pi):
    try:
      return self.cache[(swin, owin, pi)]
    except KeyError:
      if swin == self.K:
        self.cache[(swin, owin, pi)] = 1.0
      elif owin == self.K:
        self.cache[(swin, owin, pi)] = 0.0
      else:
        pwin = pi * self.ps + (1 - pi) * self.pr
        # win
        c1 = self.solve(swin + 1, owin, pi + self.pu if pi + self.pu < 1.0 else 1.0)
        c2 = self.solve(swin + 1, owin, pi)
        # loses
        c3 = self.solve(swin, owin + 1, pi - self.pd if pi - self.pd > 0.0 else 0.0)
        c4 = self.solve(swin, owin + 1, pi)
        self.cache[(swin, owin, pi)] = pwin * (c1 * self.pw + c2 * (1 - self.pw)) +\
               (1 - pwin) * (c3 * self.pl + c4 * (1 - self.pl))
    return self.cache[(swin, owin, pi)]

  def solveAll(self):
    return self.solve(0, 0, self.pi)

with open('input3.txt', 'r') as f:
  with open('output3.txt', 'w') as of:
    T = int(f.readline())
    for i in range(T):
      nums = f.readline().split(' ')
      K = int(nums[0])
      probs = [float(j) for j in nums[1:]]
      solver = Solver(K, probs)
      print "Case #%d: %.6f\n" % (i + 1, solver.solveAll())
      of.write("Case #%d: %.6f\n" % (i + 1, solver.solveAll()))
