#!/bin/bash

gcc -Wall -Werror -Wextra -Wpedantic -fsanitize=address -g multiplier.c || exit 1

echo "test 1: 1 * 1 = 1"
./a.out 1 1

git add multiplier.c > /dev/null
git commit -m "commit" > /dev/null
git push > /dev/null