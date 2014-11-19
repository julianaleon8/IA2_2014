#! /usr/bin/gnuplot

set key outside bottom
set xrange restore
set yrange restore
plot "./result1000gn/1000g_2.output" title "Error"
pause -1 "Hit any key to continue"
