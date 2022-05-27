set  yrange[-1.5:1.5]
set  xrange[300000000000000:800000000000000]
set  xlabel "Frecuencia"
set  ylabel "V_0" 
set title "Frecuencia vrs. Voltaje"
a=4.12e-15
b=-0.667
f(x)=a*x+b
fit f(x) 'cte.dat' u 3:1:2 via  a, b
chi2=(FIT_P)
set label 1 at first 400000000000000,1 sprintf("{/Symbol c}^2 = %.5f", chi2)
plot f(x) t 'Fit', 'cte.dat' u 3:1:2 lc 2 pt 7 w errorbars t 'V_0'
show label