#!/usr/bin/env ruby

t = STDIN.gets.to_i

(1..t).each do |index|
  n = STDIN.gets.to_i

  m = (1..n).collect do
    STDIN.gets
  end
  # find first black cell
  x = nil
  y = nil
  catch (:found) do
    n.times do |i|
      n.times do |j|
        if m[i][j] == ?#
          x, y = i, j
          throw :found
        end
      end
    end
  end

  if x == nil and y == nil
    ans = "YES"
  else
    length = 1
    while m[x + length] != nil and m[x + length][y] == ?#
      length = length + 1
    end
    catch (:done) do
      ans = "NO"
      n.times do |i|
        n.times do |j|
          if i - x >= 0 and i - x < length and j - y >= 0 and j - y < length
            if m[i][j] != ?#
              throw :done
            end
          else
            if m[i][j] == ?#
              throw :done
            end
          end
        end
      end
      ans = "YES"
    end
  end

  puts "Case ##{index}: #{ans}"
end
