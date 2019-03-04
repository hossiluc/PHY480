set title 'Error vs Step'
set xlabel 'log(Step)'
set ylabel 'log(Relative Error)'

f1(x) = a1*x + b1
fit [0:2] f1(x) "integ1.dat" using ($1):($2) via a1,b1
fit_title1 = sprintf("%-+4.1f*x %-+4.1f",a1,b1)

f2(x) = a2*x + b2
fit [0:3] f2(x) "integ2.dat" using ($1):($2) via a2,b2
fit_title2 = sprintf("%-+4.1f*x %-+4.1f",a2,b2)


plot "integ1.dat" using ($1):($2) title 'Simpson',\
a1*x + b1 title fit_title1,\
"integ2.dat" using ($1):($2) title 'Minle',\
a2*x + b2 title fit_title2,\
"integ1.dat" using ($1):($3) title 'GSL'

set out "integ.ps"
set term postscript color enhanced
replot



 

