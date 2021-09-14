gcc ex1.c

count=10
for i in $(seq $count); do
    ./a.out
    sleep 1
done

rm -f a.out
