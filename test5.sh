i=0
while [ $i -lt 10000 ]; do
	./quickcomp.sh && ./a.out tests/tuomas_tests/5
	printf '\n'
	./quickcomp.sh && ./a.out tests/test-24a
	let i=i+1
	printf '\n'
	printf $i
	printf '\n'
done
