#!/bin/bash

mkdir tmp
touch tmp/file1 tmp/file2

link tmp/file1 tmp/link1
gcc ex4.c
./a.out > ex4.txt
rm a.out
