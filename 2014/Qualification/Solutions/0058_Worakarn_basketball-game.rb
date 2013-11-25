class Player 
  include Comparable
  
  attr_accessor :fg, :h, :t, :name
  
  def <=>(that)
      [-self.t, self.fg, self.h] <=> [-that.t, that.fg, that.h]
  end
  
  def inspect
    "Player " + [self.name, self.t, self.fg, self.h].inspect
  end
  
end

gets.to_i.times{|t|
  n,m,p = gets.split.map(&:to_i)
  all_players = []
  n.times{
    name,fg,h = gets.split
    player = Player.new
    player.name = name
    player.fg = fg.to_i
    player.h = h.to_i
    player.t = 0
    all_players << player
  }
  
  team1 = []
  team2 = []
  teams=[team1, team2]
  all_players.sort.reverse.each{|player|
    teams[0]<<player
    teams.reverse!
  }
  
  team1_field = team1[0..p-1]
  team1_bench = team1[p..-1]
  team2_field = team2[0..p-1]
  team2_bench = team2[p..-1]
  
  m.times{
    
    team1_field.each{|player| player.t+=1}
    team2_field.each{|player| player.t+=1}
    
    if !team1_bench.empty?
      team1_field.sort!
      team1_bench.sort!
      out1 = team1_field.delete_at(0)
      in1 = team1_bench.delete_at(-1)
      team1_field << in1
      team1_bench << out1
    end
    
    if !team2_bench.empty?
      team2_field.sort!
      team2_bench.sort!
      out2 = team2_field.delete_at(0)
      in2 = team2_bench.delete_at(-1)
      team2_field << in2
      team2_bench << out2
    end
    
  }
  
  flist = (team1_field + team2_field).map{|player| player.name}.sort.join(" ")
  puts "Case ##{t+1}: #{flist}"
}