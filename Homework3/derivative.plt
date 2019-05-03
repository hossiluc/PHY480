set title "Error per Derivative Method"
set xlabel "h"
set ylabel "Error"

plot "derivative_test.dat" using 1:5 title "Diff_extrap2",\
"derivative_test.dat" using 1:4 title "Diff_extrap",\
"derivative_test.dat" using 1:3 title "Central",\
"derivative_test.dat" using 1:2 title "Forward"

set out "derive.ps"
set term postscript color enhanced
replot

