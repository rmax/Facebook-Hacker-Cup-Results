============================
Qualification Round Problems
============================

.. contents::

Square Detector
---------------

You want to write an image detection system that is able to recognize
different geometric shapes. In the first version of the system you settled
with just being able to detect filled squares on a grid.

You are given a grid of N×N square cells. Each cell is either white or black.
Your task is to detect whether all the black cells form a square shape.

Input
=====
The first line of the input consists of a single number T, the number of test
cases.

Each test case starts with a line containing a single integer N. Each of the
subsequent N lines contain N characters. Each character is either "."
symbolizing a white cell, or "#" symbolizing a black cell. Every test case
contains at least one black cell.

Output
======
For each test case i numbered from 1 to T, output "Case #i: ", followed by
YES or NO depending on whether or not all the black cells form a completely
filled square with edges parallel to the grid of cells.

Constraints
===========

::

  1 ≤ T ≤ 20
  1 ≤ N ≤ 20


Basketball Game
---------------

A group of N high school students wants to play a basketball game. To divide
themselves into two teams they first rank all the players in the following
way:

Players with a higher shot percentage are rated higher than players with a
lower shot percentage.
If two players have the same shot percentage, the taller player is rated
higher.
Luckily there are no two players with both the same shot percentage and
height so they are able to order themselves in an unambiguous way. Based on
that ordering each player is assigned a draft number from the range [1..N],
where the highest-rated player gets the number 1, the second highest-rated
gets the number 2, and so on. Now the first team contains all the players
with the odd draft numbers and the second team all the players with the even
draft numbers.

Each team can only have P players playing at a time, so to ensure that
everyone gets similar time on the court both teams will rotate their players
according to the following algorithm:

Each team starts the game with the P players who have the lowest draft
numbers.
If there are more than P players on a team after each minute of the game the
player with the highest total time played leaves the playing field. Ties are
broken by the player with the higher draft number leaving first.
To replace her the player on the bench with the lowest total time played
joins the game. Ties are broken by the player with the lower draft number
entering first.
The game has been going on for M minutes now. Your task is to print out the
names of all the players currently on the field, (that is after M rotations).

Input
=====
The first line of the input consists of a single number T, the number of test
cases.

Each test case starts with a line containing three space separated integers N M
P

The subsequent N lines are in the format "<name> <shot_percentage> <height>".
See the example for clarification.

Constraints
===========

::

  1 ≤ T ≤ 50
  2 * P ≤ N ≤ 30
  1 ≤ M ≤ 120
  1 ≤ P ≤ 5

Each name starts with an uppercase English letter, followed by 0 to 20
lowercase English letters. There can be players sharing the same name. Each
shot percentage is an integer from the range [0..100]. Each height is an
integer from the range [100..240]

Output
======
For each test case i numbered from 1 to T, output "Case #i: ", followed by 2 *
P space separated names of the players playing after M rotations. The names
should be printed in lexicographical order.

Example
=======
In the first example if you sort all the players by their shot percentage you
get the list: [Wai, Purav, Weiyan, Slawek, Lin, Meihong]. This makes the two
teams::

  [Wai, Weiyan, Lin]
  [Purav, Slawek, Meihong]

The game starts with Lin and Meihong sitting on the bench in their respective
teams. After the first minute passes it's time for Weiyan and Slawek to sit out
since they have the highest draft numbers of the people who played. After the
second minute passes Lin and Meihong will keep playing since they only played
one minute so far and it's Wai and Purav who have to sit out.

Finally after the third minute Lin and Maihong go back to the bench and all the
players currently playing again are::

  Purav Slawek Wai Weiyan


Tennison
--------

You may be familiar with the works of Alfred Lord Tennyson, the famous English
poet. In this problem we will concern ourselves with Tennison, the less famous
English tennis player. As you know, tennis is not so much a game of skill as a
game of luck and weather patterns. The goal of tennis is to win K sets before
the other player. However, the chance of winning a set is largely dependent on
whether or not there is weather.

Tennison plays best when it's sunny, but sometimes of course, it rains.
Tennison wins a set with probability ps when it's sunny, and with probability
pr when it's raining. The chance that there will be sun for the first set is
pi. Luckily for Tennison, whenever he wins a set, the probability that there
will be sun increases by pu with probability pw. Unfortunately, when Tennison
loses a set, the probability of sun decreases by pd with probability pl. What
is the chance that Tennison will be successful in his match?

Rain and sun are the only weather conditions, so P(rain) = 1 - P(sun) at all
times. Also, probabilities always stay in the range [0, 1]. If P(sun) would
ever be less than 0, it is instead 0. If it would ever be greater than 1, it is
instead 1.

Input
=====
Input begins with an integer T, the number of tennis matches that Tennison
plays. For each match, there is a line containing an integer K, followed by the
probabilities ps, pr, pi, pu, pw, pd, pl in that order. All of these values are
given with exactly three places after the decimal point.

Output
======
For each match, output "Case #i: " followed by the probability that Tennison
wins the match, rounded to 6 decimal places (quotes for clarity only). It is
guaranteed that the output is unaffected by deviations as large as 10-8.

Constraints
===========

::

  1 ≤ T ≤ 100
  1 ≤ K ≤ 100
  0 ≤ ps, pr, pi, pu, pw, pd, pl ≤ 1
  ps > pr


.. [Source] https://www.facebook.com/hackercup/problems.php?pid=373965339404375&round=598486203541358
