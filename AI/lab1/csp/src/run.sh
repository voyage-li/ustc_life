#!/bin/bash
# rm -rf ./csp

# if [ $1 -eq 0 ]; then
#     g++ -DDEBUG csp.cpp -o csp -O3
# else
#     g++ csp.cpp -o csp -O3
# fi

for i in {0..9}
do
    ./csp <../input/input$i.txt >../output/output$i.txt
done 
rm -rf ./csp