cp ex1.c endpoint
cd endpoint
touch file1
touch file2
gcc ex1.c
ldd a.out
mkdir -p lib/x86_64-linux-gnu
mkdir lib64
cp -f /lib64/ld-linux-x86-64.so.2 lib64/ld-linux-x86-64.so.2
cp -f /lib/x86_64-linux-gnu/libc.so.6 lib/x86_64-linux-gnu/libc.so.6
chroot /endpoint /a.out
