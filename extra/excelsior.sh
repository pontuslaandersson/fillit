echo "Testing fillit"
echo "Compiling..."
./quickcomp.sh
clear
read -p "Should not pass... press [return] to continue, scroll or press "q" during tests"
read -p "./a.out tests/wrong_nbr_dots "
./a.out tests/wrong_nbr_dots 
printf '\n'
read -p  "./a.out tests/test-1234 "
./a.out tests/test-1234 
printf '\n'
read -p "./a.out tests/wrong_nbr_dots "
./a.out tests/wrong_nbr_dots
printf '\n'
read -p	"./a.out tests/empty-file "
./a.out tests/empty-file 
printf '\n'
read -p "./a.out tests/first-and-only "
./a.out tests/first-and-only 
printf '\n'
read -p "./a.out tests/27 "
./a.out tests/27 
printf '\n'
read -p "./a.out tests/illegal-shape "
./a.out tests/illegal-shape
printf '\n'
read -p "./a.out tests/incorrect-file"
./a.out tests/incorrect-file
printf '\n'
read -p "./a.out tests/its-over-26 "
./a.out tests/its-over-26
printf '\n'
read -p "./a.out tests/single-file"
./a.out tests/single-file
printf '\n'
read -p "./a.out tests/test-1234"
./a.out tests/test-1234 
printf '\n'
read -p "./a.out tests/wrong-nbr-blocks"
./a.out tests/wrong-nbr-blocks 
printf '\n'
read -p "./a.out tests/wrong_nbr_dots "
./a.out tests/wrong_nbr_dots 
printf '\n'
read -p	"tuomas tests n1" 
./a.out tests/tuomas_tests/n1
printf '\n'
read -p	"tuomas tests n2" 
./a.out tests/tuomas_tests/n2
printf '\n'
read -p	"tuomas tests n3" 
./a.out tests/tuomas_tests/n3
printf '\n'
read -p	"tuomas tests n4" 
./a.out tests/tuomas_tests/n4
printf '\n'
read -p	"tuomas tests n5" 
./a.out tests/tuomas_tests/n5
printf '\n'
read -p	"tuomas tests n6" 
./a.out tests/tuomas_tests/n6
printf '\n'
read -p	"tuomas tests n7" 
./a.out tests/tuomas_tests/n7
printf '\n'
read -p	"tuomas tests n8" 
./a.out tests/tuomas_tests/n8
printf '\n'
read -p	"tuomas tests n9" 
./a.out tests/tuomas_tests/n9
printf '\n'
read -p	"tuomas tests n10" 
./a.out tests/tuomas_tests/n10
printf '\n'
read -p	"tuomas tests n11" 
./a.out tests/tuomas_tests/n11
printf '\n'
read -p	"tuomas tests n12" 
./a.out tests/tuomas_tests/n12
printf '\n'
read -p	"tuomas tests n13" 
./a.out tests/tuomas_tests/n13
printf '\n'
read -p	"tuomas tests n14" 
./a.out tests/tuomas_tests/n14
printf '\n'
read -p	"tuomas tests n15" 
./a.out tests/tuomas_tests/n15
printf '\n'
read -p	"tuomas tests n16" 
./a.out tests/tuomas_tests/n16
printf '\n'
read -p	"tuomas test_doublenl.txt" 
./a.out tests/tuomas_tests/test_doublenl.txt
printf '\n'



read -p "Should pass..."
clear
read -p	"test-easy" 
./a.out tests/test-easy
printf '\n'
read -p	"4-down" 
./a.out tests/4-down
printf '\n'
read -p "test-peasy" 
./a.out tests/test-peasy
printf '\n'
read -p "test-sneazy" 
./a.out tests/test-sneazy
printf '\n'
read -p "test-neg" 
./a.out tests/test-neg
printf '\n'
read -p "valid square." 
./a.out tests/4_ValidSquare
printf '\n'
read -p	"valid_16" 
./a.out tests/valid_16
printf '\n'
read -p "test-2a" 
./a.out tests/test-2a
printf '\n'
read -p "test-2b" 
./a.out tests/test-2b
printf '\n'
read -p "test-2c" 
./a.out tests/test-2c
printf '\n'
read -p "test-2d" 
./a.out tests/test-2d
printf '\n'
read -p "test-2e" 
./a.out tests/test-2e
printf '\n'
read -p "test-3a" 
./a.out tests/test-3a
printf '\n'
read -p "test-4a" 
./a.out tests/test-4a
printf '\n'
read -p "test-5a" 
./a.out tests/test-5a
printf '\n'
read -p "test-6a" 
./a.out tests/test-6a
printf '\n'
read -p "test-6b" 
./a.out tests/test-6b
printf '\n'
read -p "test-6c" 
./a.out tests/test-6c
printf '\n'
read -p "test-7a" 
./a.out tests/test-7a
printf '\n'
read -p "test-24a" 
./a.out tests/test-24a
printf '\n'
# read -p "test-24b" 
# ./a.out tests/test-24b | less
#printf '\n'
read -p	"tuomas tests 1" 
./a.out tests/tuomas_tests/1
printf '\n'
read -p	"tuomas tests 2" 
./a.out tests/tuomas_tests/2
printf '\n'
read -p	"tuomas tests 3" 
./a.out tests/tuomas_tests/3
printf '\n'
read -p	"tuomas tests 4" 
./a.out tests/tuomas_tests/4
printf '\n'
read -p	"tuomas tests 5" 
./a.out tests/tuomas_tests/5
printf '\n'
read -p	"tuomas tests 6" 
./a.out tests/tuomas_tests/6
printf '\n'
read -p	"tuomas tests 7" 
./a.out tests/tuomas_tests/7
printf '\n'
# read -p	"tuomas tests 8" 
# ./a.out tests/tuomas_tests/8
# printf '\n'
read -p	"tuomas tests test_3.txt" 
./a.out tests/tuomas_tests/test_3.txt
printf '\n'
read -p	"tuomas tests test_6.txt" 
./a.out tests/tuomas_tests/test_6.txt
printf '\n'
read -p	"tuomas tests test_edge1.txt" 
./a.out tests/tuomas_tests/test_edge1.txt
printf '\n'
read -p	"tuomas tests test_edge2.txt" 
./a.out tests/tuomas_tests/test_edge2.txt
printf '\n'
read -p "super" 
time ./a.out tests/super
printf '\n'