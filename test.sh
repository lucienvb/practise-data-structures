#!/bin/bash

gcc -Wall -Werror -Wextra -Wpedantic -fsanitize=address -g multiplier.c || exit 1

echo "test 1: 1 * 1 = 1"
./a.out 1 1

echo "test 2: 99 * 99 = 9801"
./a.out '99' '99'

echo "test 3: -99 * 99 = -9801"
./a.out '-99' '99'

echo "test 4: -99 * -99 = 9801"
./a.out '-99' '-99'

echo "test 5: 4582236412336 * 8822364411111111111 = 4.0426159e+31"
./a.out 4582236412336 8822364411111111111

# git add multiplier.c > /dev/null
# git commit -m "commit" > /dev/null
# git push > /dev/null