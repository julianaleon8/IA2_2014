#! /usr/bin/gnuplot

set key outside bottom
set xrange [0:20]
set yrange [0:20]
set term png
set output "welp.png"
plot "<awk '{if($3 == 1) print}' 8-mytrain1000-mytest2000.ouput" title "Dentro","<awk '{if($3 == -1) print}' 8-mytrain1000-mytest2000.ouput" title "Fuera", "./c.dat" with circles title "Circulo"
set term x11
#pause -1 "welp"
