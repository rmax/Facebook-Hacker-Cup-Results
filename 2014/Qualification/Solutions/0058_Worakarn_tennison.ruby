gets.to_i.times{|t|
  k,ps,pr,pi,pu,pw,pd,pl = gets.split.map(&:to_f)
  k=k.to_i
  pi=(pi*1000).to_i
  pu=(pu*1000).to_i
  pd=(pd*1000).to_i

  h={pi=>1.0}
  sum = 0.0

  (2*k-1).times{
    hh={}
    h.each{|key,val|
      wins,p_sun = key.divmod(1001)
      p_sun_f = p_sun/1000.0
      p_win_set = ps*p_sun_f+pr*(1-p_sun_f)
      p_lose_set = 1-p_win_set
      p_sun_up = p_sun + pu
      p_sun_up = 1000 if p_sun_up > 1000
      p_sun_down = p_sun - pd
      p_sun_down = 0 if p_sun_down < 0
    
      win_val = val * p_win_set
      lose_val = val * p_lose_set
      if wins == k-1
        sum += win_val
      else
        #win and up
        wc_val = win_val * pw
        wc_key = 1001*(wins+1)+p_sun_up
        if wc_val > 0
          hh[wc_key] ||= 0.0
          hh[wc_key] += wc_val
        end
      
        #win and not up
        wn_val = win_val * (1-pw)
        wn_key = 1001*(wins+1)+p_sun
        if wn_val > 0
          hh[wn_key] ||= 0.0
          hh[wn_key] += wn_val
        end
      end
    
      #lose and not down
      ln_val = lose_val * (1-pl)
      ln_key = 1001*wins+p_sun
      if ln_val > 0
        hh[ln_key] ||= 0.0
        hh[ln_key] += ln_val
      end
    
      #lose and down
      lc_val = lose_val * pl
      lc_key = 1001*wins+p_sun_down
      if lc_val > 0
        hh[lc_key] ||= 0.0
        hh[lc_key] += lc_val
      end
    }
    h=hh
    #p h
  }

  printf("Case ##{t+1}: %.6f\n", sum)
}