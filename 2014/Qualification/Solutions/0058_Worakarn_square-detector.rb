gets.to_i.times{|t|
  n = gets.to_i
  sq=true
  m=0
  f=nil
  n.times{
    s=gets.strip + "."
    if(sq)
      ss=s.split(//).reduce([".",0]){|a,c| a[0]==c ? a[-1]+=1 : (a<<1;a[0]=c);a }[1..-1]
      if sq
        if f==nil
          if ss.size>3
            sq=false
          elsif ss.size==3
            f=ss
            m=1
          end
        elsif m==f[1]
          sq=false if ss.size > 1
        else
          if ss==f
            m+=1
          else
            sq=false
          end
        end
      end   
    end 
  }
  if(sq)
    puts "Case ##{t+1}: YES"
  else
    puts "Case ##{t+1}: NO"
  end
}