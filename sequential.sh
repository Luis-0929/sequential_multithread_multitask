#!/bin/bash
echo "Running Script...."
n1=100000000
n2=1000000000
n3=10000000000

gcc sequential.c -o sequential

echo "Running Workload of $n1"
./sequential $n1
echo "Running Workload of $n2"
./sequential $n2
echo "Running Workload of $n3"
./sequential $n3
echo "....end script"

rm sequential