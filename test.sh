#!/bin/bash

gcc -Wall -Werror -Wextra -Wpedantic -fsanitize=address -g multiplier.c || exit 1

echo "test 1: 1 * 1 = 1"
./a.out 1 1

echo "test 2: 99 * 99 = 9801"
./a.out 99 99

# git add multiplier.c > /dev/null
# git commit -m "commit" > /dev/null
# git push > /dev/null