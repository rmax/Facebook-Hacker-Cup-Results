f = open("squaredetector.in", "r")

T = int(f.readline())


for t in range(T):
	size = 1
	start = False
	startx = 0
	starty = 0
	stop = False
	N = int(f.readline())
	grid = []
	for i in range(N):
		grid.append(f.readline())


	for i in range(N):
		for j in range(N):
			if not start:
				if grid[i][j] == '#':
					start = True
					startx = i
					starty = j
			else:
				if grid[i][j] != '#':
					stop = True
				else:
					size += 1
			if stop:
				break
		if stop or start:
			break
	isSquare = True

	for i in range(N):
		for j in range(N):
			if i >= startx and i < startx + size and j >= starty and j < starty + size:
				if grid[i][j] != '#':
					isSquare = False
			else:
				if grid[i][j] == '#':			
					isSquare = False
	print "Case", "#" + str(t + 1) + ":", 
	if isSquare:
		print "YES"
	else:
		print "NO"





