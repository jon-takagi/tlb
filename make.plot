set term png enhanced giant size 1980, 1080
set output 'graph.png'
set ylabel "average access time(ns)"
set xlabel "number of pages accessed"
plot '2**.dat' with lines
