x=1
while [ $x -le 24 ]
do
	nbrs=$(sed -n "$x"p tests/files/00_test.txt)
	echo "line $x [$nbrs]: \c"
	sleep .5
	./push_swap $nbrs | ./checker_Mac $nbrs
	((x++))
done