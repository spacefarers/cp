echo "Compiling"
g++-11 -o gen gen.cpp
g++-11 -o brute ../usaco/2019-usopen/g-1.cpp
g++-11 -o a ../practice/usaco1.cpp

echo "Starting Check"

for ((i = 1; i < 500; ++i)); do
  ./gen >test.in
  # ./a < int > out1
  # ./brute < int > out2
  # diff -w out1 out2 || break
  diff -w <(./a <test.in) <(./brute <test.in) || break
  echo "Checking #$i: Match"
done
