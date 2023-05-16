#!/bin/bash -v
rm -rf ./astar ../output/*
g++ astar.cpp -o astar -O3
for i in {0..9}
do
    ./astar <../input/input$i.txt >../output/output$i.txt
done 
rm -rf ./astar