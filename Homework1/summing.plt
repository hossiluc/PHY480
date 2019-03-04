set title 'Error vs Step'
set xlabel 'Step'
set ylabel 'Error'

set logscale

set xrange[0:1200]
set yrange[.1:15]

f(x) = a*x+b
fit [100:1000] f(x) "summing.dat" using ($1):(abs($2-$3)/(.5*abs($3)+abs($2))) via a,b

plot "summing.dat" using ($1):(abs($2-$3)/(.5*abs($3)+abs($2))),\
a*x+b 

set out "summing.ps"
set term postscript color enhanced
replot

