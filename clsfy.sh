#!/bin/bash

DIR="./.hiddenfolder"

if [ -d $DIR ]; then
  :
else
  mkdir ./.hiddenfolder
  clang main.c simple-strings/sstring.c -o .hiddenfolder/clsfy
fi

FILE="./.hiddenfolder/ls.txt"

if [ -f "$FILE" ]; then
  eza ./folder -D | cat >$FILE
else
  touch ./.hiddenfolder/ls.txt
  ls -D | cat >$FILE
  FILE="./.hiddenfolder/ls.txt"
fi

output=$(./.hiddenfolder/clsfy "$1")
status=$?

echo "output : $output"
echo "status : $status"

if [ "$status" == 159 ]; then
  rm "$FILE"
  ./.hiddenfolder/clsfy "$1"
fi

pos="./folder/$output"

if [ -n "$2" ]; then
  mv $2 $pos
fi
