#! /usr/bin/gnuplot

set key outside bottom
set xrange [0:20]
set yrange [0:20]
set term png
set output "10-test2000.png"
plot "<awk '{if($3 == 1) print}' 10-test2000.txt" title "Afuera","<awk '{if($3 == -1) print}' 10-test2000.txt" title "Dentro", "./c.dat" with circles title "Circulo"
set term x11
#pause -1 "10-test2000"
