#!/bin/bash

echo "Artem" > ../week1/file.txt
link ../week1/file.txt _ex2.txt

find ../.. -inum $(stat -f '%i' _ex2.txt) >> ex2.txt
find ../.. -inum $(stat -f '%i' _ex2.txt) -exec rm {} \; >> ex2.txt
