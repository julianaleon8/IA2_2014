#! /usr/bin/gnuplot

set key outside bottom
set xrange [0:20]
set yrange [0:20]
set term png
set output "10-mytest2000.png"
plot "<awk '{if($3 == 1) print}' 10-mytest2000.txt" title "Dentro","<awk '{if($3 == -1) print}' 10-mytest2000.txt" title "Afuera", "./c.dat" with circles title "Circulo"
set term x11
#pause -1 "10-mytest2000"
