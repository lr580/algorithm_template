#include <iostream>
#include <chrono>
#include <random>
using namespace std;
int main()
{
	// 随机数种子
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 rand_num(seed);  // 大随机数
	uniform_int_distribution<long long> dist(0, 1000000000);  // 给定范围
	cout << dist(rand_num) << endl;
	return 0;
}