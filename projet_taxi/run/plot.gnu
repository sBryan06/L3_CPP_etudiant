set out 'out_plot.png'
set terminal png size 800,600
set style fill solid border -1
set grid ytics
set boxwidth 0.8
set xtics rotate by -45
set yrange [0:*] 
plot 'plot.csv' using 2:xtic(1) lc rgb 'yellow' with boxes notitle
