#include <iostream>
#include <chrono>
#include <random>
using namespace std;
int main()
{
  //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  //mt19937 rand_num(seed); 方法一
    random_device divc;
  mt19937 rand_num(divc()); //方法二：Linux真随机数
  uniform_int_distribution<long long> dist(0, 1000000000);
  cout << dist(rand_num) << endl;
  return 0;
}
