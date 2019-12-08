rem create execution file
gcc -std=c11 quick_sort.c quick_sort_main.c -o quick_c

rem loop 10 times each separate 2 seconds
for /l %%x in (1, 1, 10) do quick_c.exe & timeout /t 2