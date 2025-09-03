g++ -O3 -std=c++17 gen.cpp -o gen || { echo "Compile gen.cpp failed"; exit 1; }
g++ -O3 -std=c++17 opti.cpp -o opti || { echo "Compile opti.cpp failed"; exit 1; }
g++ -O3 -std=c++17 meme.cpp -o meme || { echo "Compile meme.cpp failed"; exit 1; }

# Continue with stress testing
for ((i = 1; ; ++i)); do
    echo $i
    ./gen $i > wtc.txt
    diff -w <(./opti < wtc.txt) <(./meme < wtc.txt) || break
done
