echo "Testing fillit"
echo "Compiling..."
./quickcomp.sh
echo "\nShould pass..."
./a.out tests/test-easy
echo "\nShould not pass..."
./a.out tests/wrong_nbr_dots
echo "\nShould not pass..."
./a.out tests/test-1234
echo "\nShould not pass..."
./a.out tests/wrong_nbr_dots
