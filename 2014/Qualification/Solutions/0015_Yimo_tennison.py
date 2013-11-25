f = open("tennison.in", "r")

T = int(f.readline())
precision = 10

def calc(wins, losses, prob_sun, current_p):
	if round(current_p, precision) == 0.0:
		return
	global p_win_sun, p_win_rain, p_sun, p_sun_boost_value, p_sun_boost_chance, p_rain_boost_value, p_rain_boost_chance, p_win, dp
	win_prob = prob_sun * (p_win_sun - p_win_rain) + p_win_rain
	
	lose_prob = 1 - win_prob
	new_prob_sun = round(min(1, p_sun_boost_value + prob_sun), precision)
	if not new_prob_sun in dp[wins + 1][losses]:
		dp[wins + 1][losses][new_prob_sun] = 0.0
	dp[wins + 1][losses][new_prob_sun] += current_p * win_prob * p_sun_boost_chance

	new_prob_sun = prob_sun
	if not new_prob_sun in dp[wins + 1][losses]:
		dp[wins + 1][losses][new_prob_sun] = 0.0
	if not new_prob_sun in dp[wins][losses + 1]:
		dp[wins][losses + 1][new_prob_sun] = 0.0
	dp[wins + 1][losses][new_prob_sun] += current_p * win_prob * (1 - p_sun_boost_chance)
	dp[wins][losses + 1][new_prob_sun] += current_p * lose_prob * (1 - p_rain_boost_chance)

	new_prob_sun = round(max(0, prob_sun - p_rain_boost_value), precision)
	if not new_prob_sun in dp[wins][losses + 1]:
		dp[wins][losses + 1][new_prob_sun] = 0.0
	dp[wins][losses + 1][new_prob_sun] += current_p * lose_prob * p_rain_boost_chance

for t in range(T):
	temp = f.readline()
	temp = temp.split(' ')
	for i in range(1, len(temp)):
		temp[i] = float(temp[i])
	temp = temp[::-1]
	K = int(temp.pop())
	p_win_sun = temp.pop()
	p_win_rain = temp.pop()
	p_sun = temp.pop()
	p_sun_boost_value = temp.pop()
	p_sun_boost_chance = temp.pop()
	p_rain_boost_value = temp.pop()
	p_rain_boost_chance = temp.pop()
	p_win = 0.0
	dp = dict()
	for i in range(K + 1):
		dp[i] = dict()
		for j in range(K + 1):
			dp[i][j] = dict()
	dp[0][0][p_sun] = 1
	for i in range(K):
		for j in range(K):
			for k, v in dp[i][j].iteritems():
				calc(i, j, k, v)
	for j in range(K):
		for k in dp[K][j].values():
			p_win += k
	print "Case", "#" + str(t + 1) + ":", 
	print '{0:.6f}'.format(round(p_win, 6))



