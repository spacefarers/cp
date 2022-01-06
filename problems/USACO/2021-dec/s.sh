g++-11 -o brute gen.cpp

for ((i = 1; ; ++i)); do
  echo $i
  ./gen >test.in
  # ./a < int > out1
  # ./brute < int > out2
  # diff -w out1 out2 || break
  diff -w <(./a <test.in) <(./brute <test.in) || break
done
