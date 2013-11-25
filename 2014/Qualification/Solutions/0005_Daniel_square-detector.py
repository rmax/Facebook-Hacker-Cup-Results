#!/usr/bin/python2
T = int(raw_input())
for _ in xrange(T):
	N = int(raw_input())
	s = []
	for i in xrange(N):
		s.append(raw_input())
	
	firsti = -1
	for i in xrange(N):
		if '#' in s[i]:
			firsti = i
			break
	
	firstj = -1
	for j in xrange(N):
		if s[firsti][j] == '#':
			firstj = j
			break
	
	L = 0
	for k in xrange(j, N):
		if s[firsti][k] == '.':
			break
		L += 1

	ans = "YES"
	if firsti + L > N:
		ans = "NO"
	for i in xrange(N):
		for j in xrange(N):
			if i in xrange(firsti, firsti+L) and j in xrange(firstj, firstj + L) and s[i][j] != '#':
				ans = "NO"
			if (i not in xrange(firsti, firsti+L) or j not in xrange(firstj, firstj+L)) and s[i][j] != '.':
				ans = "NO"

	print "Case #%d: %s" % (_ + 1, ans)
