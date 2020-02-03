echo "Testing fillit"
echo "Compiling..."
make re -C .../fillit/fillit/
clear
read -p "Should not pass... press [return] to continue, scroll or press "q" during tests"
read -p "../fillit/fillit tests/wrong_nbr_dots "
../fillit/fillit tests/wrong_nbr_dots
printf '\n'
read -p  "../fillit/fillit tests/test-1234 "
../fillit/fillit tests/test-1234
printf '\n'
read -p "../fillit/fillit tests/wrong_nbr_dots "
../fillit/fillit tests/wrong_nbr_dots
printf '\n'
read -p	"../fillit/fillit tests/empty-file "
../fillit/fillit tests/empty-file
printf '\n'
read -p "../fillit/fillit tests/first-and-only "
../fillit/fillit tests/first-and-only
printf '\n'
read -p "../fillit/fillit tests/27 "
../fillit/fillit tests/27
printf '\n'
read -p "../fillit/fillit tests/illegal-shape "
../fillit/fillit tests/illegal-shape
printf '\n'
read -p "../fillit/fillit tests/incorrect-file"
../fillit/fillit tests/incorrect-file
printf '\n'
read -p "../fillit/fillit tests/its-over-26 "
../fillit/fillit tests/its-over-26
printf '\n'
read -p "../fillit/fillit tests/single-file"
../fillit/fillit tests/single-file
printf '\n'
read -p "../fillit/fillit tests/test-1234"
../fillit/fillit tests/test-1234
printf '\n'
read -p "../fillit/fillit tests/wrong-nbr-blocks"
../fillit/fillit tests/wrong-nbr-blocks
printf '\n'
read -p "../fillit/fillit tests/wrong_nbr_dots "
../fillit/fillit tests/wrong_nbr_dots
printf '\n'
read -p	"tuomas tests n1" 
../fillit/fillit tests/tuomas_tests/n1
printf '\n'
read -p	"tuomas tests n2" 
../fillit/fillit tests/tuomas_tests/n2
printf '\n'
read -p	"tuomas tests n3" 
../fillit/fillit tests/tuomas_tests/n3
printf '\n'
read -p	"tuomas tests n4" 
../fillit/fillit tests/tuomas_tests/n4
printf '\n'
read -p	"tuomas tests n5" 
../fillit/fillit tests/tuomas_tests/n5
printf '\n'
read -p	"tuomas tests n6" 
../fillit/fillit tests/tuomas_tests/n6
printf '\n'
read -p	"tuomas tests n7" 
../fillit/fillit tests/tuomas_tests/n7
printf '\n'
read -p	"tuomas tests n8" 
../fillit/fillit tests/tuomas_tests/n8
printf '\n'
read -p	"tuomas tests n9" 
../fillit/fillit tests/tuomas_tests/n9
printf '\n'
read -p	"tuomas tests n10" 
../fillit/fillit tests/tuomas_tests/n10
printf '\n'
read -p	"tuomas tests n11" 
../fillit/fillit tests/tuomas_tests/n11
printf '\n'
read -p	"tuomas tests n12" 
../fillit/fillit tests/tuomas_tests/n12
printf '\n'
read -p	"tuomas tests n13" 
../fillit/fillit tests/tuomas_tests/n13
printf '\n'
read -p	"tuomas tests n14" 
../fillit/fillit tests/tuomas_tests/n14
printf '\n'
read -p	"tuomas tests n15" 
../fillit/fillit tests/tuomas_tests/n15
printf '\n'
read -p	"tuomas tests n16" 
../fillit/fillit tests/tuomas_tests/n16
printf '\n'
read -p	"tuomas test_doublenl.txt" 
../fillit/fillit tests/tuomas_tests/test_doublenl.txt
printf '\n'



read -p "Should pass..."
clear
read -p	"test-easy" 
../fillit/fillit tests/test-easy
printf '\n'
read -p	"4-down" 
../fillit/fillit tests/4-down
printf '\n'
read -p "test-peasy" 
../fillit/fillit tests/test-peasy
printf '\n'
read -p "test-sneazy" 
../fillit/fillit tests/test-sneazy
printf '\n'
read -p "test-neg" 
../fillit/fillit tests/test-neg
printf '\n'
read -p "valid square." 
../fillit/fillit tests/4_ValidSquare
printf '\n'
read -p	"valid_16" 
../fillit/fillit tests/valid_16
printf '\n'
read -p "test-2a" 
../fillit/fillit tests/test-2a
printf '\n'
read -p "test-2b" 
../fillit/fillit tests/test-2b
printf '\n'
read -p "test-2c" 
../fillit/fillit tests/test-2c
printf '\n'
read -p "test-2d" 
../fillit/fillit tests/test-2d
printf '\n'
read -p "test-2e" 
../fillit/fillit tests/test-2e
printf '\n'
read -p "test-3a" 
../fillit/fillit tests/test-3a
printf '\n'
read -p "test-4a" 
../fillit/fillit tests/test-4a
printf '\n'
read -p "test-5a" 
../fillit/fillit tests/test-5a
printf '\n'
read -p "test-6a" 
../fillit/fillit tests/test-6a
printf '\n'
read -p "test-6b" 
../fillit/fillit tests/test-6b
printf '\n'
read -p "test-6c" 
../fillit/fillit tests/test-6c
printf '\n'
read -p "test-7a" 
../fillit/fillit tests/test-7a
printf '\n'
read -p "test-24a" 
../fillit/fillit tests/test-24a
printf '\n'
# read -p "test-24b" 
# ../fillit/fillit tests/test-24b | less
#printf '\n'
read -p	"tuomas tests 1" 
../fillit/fillit tests/tuomas_tests/1
printf '\n'
read -p	"tuomas tests 2" 
../fillit/fillit tests/tuomas_tests/2
printf '\n'
read -p	"tuomas tests 3" 
../fillit/fillit tests/tuomas_tests/3
printf '\n'
read -p	"tuomas tests 4" 
../fillit/fillit tests/tuomas_tests/4
printf '\n'
read -p	"tuomas tests 5" 
../fillit/fillit tests/tuomas_tests/5
printf '\n'
read -p	"tuomas tests 6" 
../fillit/fillit tests/tuomas_tests/6
printf '\n'
read -p	"tuomas tests 7" 
../fillit/fillit tests/tuomas_tests/7
printf '\n'
# read -p	"tuomas tests 8" 
# ../fillit/fillit tests/tuomas_tests/8
# printf '\n'
read -p	"tuomas tests test_3.txt" 
../fillit/fillit tests/tuomas_tests/test_3.txt
printf '\n'
read -p	"tuomas tests test_6.txt" 
../fillit/fillit tests/tuomas_tests/test_6.txt
printf '\n'
read -p	"tuomas tests test_edge1.txt" 
../fillit/fillit tests/tuomas_tests/test_edge1.txt
printf '\n'
read -p	"tuomas tests test_edge2.txt" 
../fillit/fillit tests/tuomas_tests/test_edge2.txt
printf '\n'
read -p "super" 
time ../fillit/fillit tests/super
printf '\n'
