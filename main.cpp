
#include <iostream>

using namespace std;

int sum(int n);
int product(int n);


int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;

  cout << "The sum from 1 to " << n << " is " << sum(n) << endl;
  cout << "Product from 1 to " << n << " is " << product(n) << endl;
  return 0;
}

int sum(int n) {
  int total = 0;
  for (int i = 1; i <= n; ++i) {
    total += i;
  }
  return total;
}

int product(int n) {
  int total = 1;
  for (int i = 1; i <= n; ++i) {
    total *= i;
  }
  return total;
}
