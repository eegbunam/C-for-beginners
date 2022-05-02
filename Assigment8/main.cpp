
#include <iostream>


int GCD(int a, int b)
{
 if (a < 0 ||  b < 0)
 {
  std::cout << "Error: negative numbers not allowed" << std::endl;
  return -1;
 }
 else if (a == 0 || b == 0)
 {
  std::cout << "Error: 0 is not allowed" << std::endl;
  return -1;
 }
 else if (a == b)
 {
  return a;
 }
 else if (a > b)
 {
  return GCD(a - b, b);
 }
 else
 {
  return GCD(a, b - a);
 }
}
int main ()

{
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    std::cout << "The GCD of " << a << " and " << b << " is " << GCD(a, b) << std::endl;
    std::cout << "test" << std::endl;
    return 0;


}