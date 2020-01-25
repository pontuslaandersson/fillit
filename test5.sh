i=0
while [ $i -lt 500 ]; do
	./quickcomp.sh && ./a.out tests/tuomas_tests/5
	let i=i+1
	printf '\n'
done
