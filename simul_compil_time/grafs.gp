set xlabel 'Tamaño del sistema'
set ylabel 'Tiempo (s)'
set key left top
set grid
set xrange [0:528]
set term png
set output "Compilation_time_o0.png"
set title 'Tiempo de compilación con optimización -O0'
plot 'time_data01.txt' u 1:2:3 w yerrorlines title 'p=0.15' lc rgb 'blue', 'time_data02.txt' u 1:2:3 w yerrorlines title 'p=0.40' lc rgb 'red', 'time_data03.txt' u 1:2:3 w yerrorlines title 'p=0.65' lc rgb 'green',  'time_data04.txt' u 1:2:3 w yerrorlines title 'p=0.85' lc rgb 'brown' 
set output "Compilation_time_o1.png"
set title 'Tiempo de compilación con optimización -O1'
plot 'time_data11.txt' u 1:2:3 w yerrorlines title 'p=0.15' lc rgb 'blue', 'time_data12.txt' u 1:2:3 w yerrorlines title 'p=0.40' lc rgb 'red', 'time_data13.txt' u 1:2:3 w yerrorlines title 'p=0.65' lc rgb 'green',  'time_data14.txt' u 1:2:3 w yerrorlines title 'p=0.85' lc rgb 'brown' 
set output "Compilation_time_o3.png"
set title 'Tiempo de compilación con optimización -O3'
plot 'time_data31.txt' u 1:2:3 w yerrorlines title 'p=0.15' lc rgb 'blue', 'time_data32.txt' u 1:2:3 w yerrorlines title 'p=0.40' lc rgb 'red', 'time_data33.txt' u 1:2:3 w yerrorlines title 'p=0.65' lc rgb 'green',  'time_data34.txt' u 1:2:3 w yerrorlines title 'p=0.85' lc rgb 'brown' 
