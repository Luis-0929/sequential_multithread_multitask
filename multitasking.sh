echo Running multitasking script...

n1=100000000
n2=1000000000
n3=10000000000

p1=2
p2=4
p3=8

gcc multitasking.c -o multitasking

echo "Sending workload of $n1"
./multitasking $n1 $p1



rm multitasking
echo ...end of multitasking script