#!/bin/sh

./test.sh 136 1
./test.sh 137 1

while [ 1 ]; do

./test.sh 132 0
sleep 0.1
./test.sh 132 1

./test.sh 133 0
sleep 0.1
./test.sh 133 1

./test.sh 135 0
sleep 0.1
./test.sh 135 1

./test.sh 134 0
sleep 0.1
./test.sh 134 1

done
