#include <iostream>
#include <type_traits>

template<int N>
struct rank : rank<N-1>{};

template<>
struct rank<0>{};

struct select_overload : rank<10>{};

template<int X, int Y>
using enable_multi = typename std::enable_if<X % Y == 0>::type;

template<int X>
enable_multi<X, 15> fizzbuzz_impl (rank<3>) {
   std::cout << "fizzbuzz" << std::endl;
}

template<int X>
enable_multi<X, 3> fizzbuzz_impl (rank<2>) {
   std::cout << "fizz" << std::endl;
}

template<int X>
enable_multi<X, 5> fizzbuzz_impl (rank<1>) {
   std::cout << "buzz" << std::endl;
}

template<int X>
void fizzbuzz_impl (rank<0>) {
   std::cout << X << std::endl;
}

template<int X>
void fizzbuzz () {
   fizzbuzz<X-1>();
   fizzbuzz_impl<X>(select_overload{});
}

template<>
void fizzbuzz<1> () {
   fizzbuzz_impl<1>(select_overload{});
}

int main() {
   fizzbuzz<100>();

   return 0;
}
