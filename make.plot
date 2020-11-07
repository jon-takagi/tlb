set term png enhanced giant size 1980, 1080
set output 'graph2.png'
set ylabel "average access time(ns)"
set xlabel "number of pages accessed"
set logscale x 2
plot 'output.dat' with lines
