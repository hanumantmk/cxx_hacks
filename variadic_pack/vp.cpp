#include <iostream>

void slurp(...) {}

template<int ...N>
void print_lambda() {
   slurp([]() { std::cout << N << std::endl; return 0; }()...);
}

template<int ...N>
void print_sizeof() {
   std::cout << sizeof...(N) << std::endl;
}

int sum() {
   return 0;
}

template<typename ...T>
int sum(int a, T... b) {
   return a + sum(b...);

}

template<int ...N>
void print_operator() {
   std::cout << sum((5 + N)...) << std::endl;
}

int main() {
   std::cout << "Lambda:" << std::endl;
   print_lambda<1,2,3,4,5,6>();
   std::cout << std::endl;

   std::cout << "Sizeof:" << std::endl;
   print_sizeof<8,9>();
   std::cout << std::endl;

   std::cout << "Operator:" << std::endl;
   print_operator<1,2,3,4,5,6>();
   std::cout << std::endl;

   return 0;
}
