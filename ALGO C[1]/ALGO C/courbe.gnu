set title 'Resultat des tris'
set xrange [1000:10000];
set yrange [0:0.02];
set xlabel 'taille du tableau'
set ylabel 'Temps en  (s)'
set key right top box;
plot 'resultat.txt' using 1:2 with linespoints title 'Bubble Sort' lt rgb 'blue', \
     'resultat.txt' using 1:3 with linespoints title 'Selection Sort' lt rgb 'red', \
     'resultat.txt' using 1:4 with linespoints title 'Insertion Sort' lt rgb 'green', \
     'resultat.txt' using 1:5 with linespoints title 'Quick Sort' lt rgb '#9400D3', \
     'resultat.txt' using 1:6 with linespoints title 'Heap Sort' lt rgb '#FF8C00', \
     'resultat.txt' using 1:7 with linespoints title 'Merge Sort' lt rgb '#4682B4', \
     'resultat.txt' using 1:8 with linespoints title 'Counting Sort' lt rgb 'purple', \
     'resultat.txt' using 1:9 with linespoints title 'Radix Sort' lt rgb '#A52A2A', \
     'resultat.txt' using 1:10 with linespoints title 'Shell Sort' lt rgb 'magenta'
pause mouse
