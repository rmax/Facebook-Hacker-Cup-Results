f = open("basketballgame.in", "r")

T = int(f.readline())




def calc(N, P, M):
	timeplayed = N * [0]
	players = []
	bench = []
	for i in range(P):
		players.append(i)
	for i in range(P, N):
		bench.append(i)
	for m in range(M):
		for player in players:
			timeplayed[player] += 1
		players.sort(key = lambda x: 10000 * timeplayed[x] + x)
		bench.sort(key = lambda x: -10000 * timeplayed[x] - x)
		if len(bench) > 0:
			player_to_add = bench.pop()
			player_to_remove = players.pop()
			bench.append(player_to_remove)
			players.append(player_to_add)
	return players


for t in range(T):
	temp = f.readline()
	temp = temp.split(' ')
	for i in range(len(temp)):
		temp[i] = int(temp[i])
	N = temp[0]
	M = temp[1]
	P = temp[2]
	players = []
	for i in range(N):
		stats = f.readline()
		stats = stats.split(' ')
		players.append([stats[0], int(stats[1]) * 500 + int(stats[2])])
	players.sort(key=lambda x: -1 * x[1])
	player_rank = dict()
	for i in range(len(players)):
		player_rank[i] = players[i][0]

	names = []

	players_on_field = calc((N + 1) / 2 , P, M)
	for player in players_on_field:
		names.append(player_rank[2 * player])

	players_on_field = calc(N / 2, P, M)
	for player in players_on_field:
		names.append(player_rank[2 * player + 1])

	names.sort()
	
	
	print "Case", "#" + str(t + 1) + ":", 
	print ' '.join(names)



