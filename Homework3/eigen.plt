set title 'State vs r'
set xlabel 'r'

plot "eigen_basis1.dat" using ($1):($2) title 'D = 1',\
"eigen_basis5.dat" using ($1):($2) title 'D = 5',\
"eigen_basis10.dat" using ($1):($2) title 'D = 10',\
"eigen_basis20.dat" using ($1):($2) title 'D = 20'

set out "eigen.ps"
set term postscript color enhanced
replot



 

