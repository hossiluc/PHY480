set title 'error vs. x'
set xlabel 'x'
set ylabel 'error'

set logscale

plot "bessel.dat" using ($1):($4)
set out "bessel.ps"
set term postscript color enhanced
replot

