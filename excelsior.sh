echo "Testing fillit"
echo "Compiling..."
./quickcomp.sh
clear
read -p "Should not pass... press [return] to continue, scroll or press "q" during tests"
./a.out tests/wrong_nbr_dots | less
./a.out tests/test-1234 | less
./a.out tests/wrong_nbr_dots | less
clear
read -p "Should pass..."
read -p "test-easy" 
./a.out tests/test-easy | less
read -p "test-peasy" 
./a.out tests/test-peasy | less
read -p "test-sneazy" 
./a.out tests/test-sneazy | less
read -p "valid square." 
./a.out tests/4_ValidSquare | less
read -p "test-2a" 
./a.out tests/test-2a | less
read -p "test-2b" 
./a.out tests/test-2b | less
read -p "test-2c" 
./a.out tests/test-2c | less
read -p "test-2d" 
./a.out tests/test-2d | less
read -p "test-2e" 
./a.out tests/test-2e | less
read -p "test-3a" 
./a.out tests/test-3a | less
read -p "test-4a" 
./a.out tests/test-4a | less
read -p "test-5a" 
./a.out tests/test-5a | less
read -p "test-6a" 
./a.out tests/test-6a | less
read -p "test-6b" 
./a.out tests/test-6b | less
read -p "test-6c" 
./a.out tests/test-6c | less
read -p "test-7a" 
./a.out tests/test-7a | less
read -p "test-24a" 
./a.out tests/test-24a | less
read -p "test-24b" 
./a.out tests/test-24b | less
read -p "test-super" 
./a.out tests/super | less

