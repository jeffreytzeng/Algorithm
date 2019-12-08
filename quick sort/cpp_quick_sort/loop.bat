rem create execution file
g++ -std=c++11 quick_sort.cpp quick_sort_main.cpp -o quick

rem loop 10 times each separate 2 seconds
for /l %%x in (1, 1, 10) do quick.exe & timeout /t 2