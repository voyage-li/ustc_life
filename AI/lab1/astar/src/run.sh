#!/bin/bash -v
rm -rf ./astar

if [ $1 -eq 0 ]; then
    g++ -DDEBUG astar.cpp -o astar -O3
else
    g++ astar.cpp -o astar -O3
fi

for i in {0..9}
do
    ./astar <../input/input$i.txt >../output/output$i.txt
done 
rm -rf ./astar