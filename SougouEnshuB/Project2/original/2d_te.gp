reset  
unset key
set xrange [0:1] 
set yrange [0:1]
set zrange [0:1]  
set xlabel "x"
set ylabel "y"
set zlabel "theta"

set ticslevel 0
set grid xtics ytics ztics

set size square

set term gif animate 
set output "temp.gif"

n0 = 1  
n1 = 51
dn = 1

load "2d_gif.plt" 