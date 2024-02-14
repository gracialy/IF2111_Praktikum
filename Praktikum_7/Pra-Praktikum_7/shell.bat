gcc stack.c -c
gcc dividestack.c -c
gcc driver.c -c
gcc stack.o dividestack.o driver.o -o a
a