//#include<iostream>
//
//#include<vector>
//
//using  std::vector;
//
//int main()
//{
////	vector<int> v1;
//	vector<int> v2(10, 3);
////
////	vector<int> copy(v2);
////
////	vector<int> v3(v2.begin(), v2.end());
//
//	for (size_t i = 0; i < v2.size(); i++)
//
//	{
//		std::cout << v2[i] << " ";
//
//	}
////	std::cout << std::endl;
////	vector<int>::iterator it3 = v3.begin();
////	while (it3 != v3.end())
////	{
////		std::cout << *it3 << " ";
////		it3++;
////
////	}
////	std::cout << std::endl;
//}
//
//
////int main()
////{
//	/*vector<int> vi;
//	vector<char> vch;
//
//	std::cout << vi.size() << std::endl;
//	std::cout << vi.capacity() << std::endl;
//	vi.reserve(10);
//	std::cout << vi.size() << std::endl;
//	std::cout << vi.capacity() << std::endl;
//
//	vi.resize(20, 2);
//	std::cout << vi.size() << std::endl;
//	std::cout << vi.capacity() << std::endl;
//
//
//	vector<int> v1 = { 10, 0 };
////	vector<int> v2;
////	v2.resize(20, 2);
////
////	vector<int> v1 = { 1, 2, 3, 4 };*/
////	vector<int> v1;
////	v1.push_back(1);
////	v1.push_back(2);
////	v1.push_back(3);
////	v1.push_back(4);
////	auto pos=find(v1.begin(), v1.end(), 3);
////	if (pos != v1.end())
////	{
////		std::cout << "找到" <<std:: endl;
////		*pos = 30;
////		v1.insert(pos, 100);
////	}
////	for (auto e : v1)
////	{
////		std::cout << e << " ";
////	}
////	std::cout << std::endl;
////    
////}



#include"vector.hpp"

#include<iostream>

using namespace std;
void test1_vector()
{
	mzp::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);


	v.push_back(5);

	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
		
	}
	cout << endl;
	mzp::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test2_vector()
{
	mzp::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	v1.resize(2);

	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	v1.resize(8,5);
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
}

void test3_vector()
{
	mzp::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	auto  it = std::find(v1.begin(), v1.end(), 3);
	v1.insert(it, 9);
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	auto  it1 = std::find(v1.begin(), v1.end(), 5);
	//erase it之后严格来说迭代器失效了，如果it为最后一个数据，
	//那么删除之后erase的位置非法
	v1.erase(it1);

	/*v1.resize(2);

	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	v1.resize(8, 5);*/
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
	cout << endl;
	mzp::vector<int> copy(v1);
	for (auto e : copy)
	{
		std::cout << e << " ";
	}
}





void test4_vector()
{
	mzp::vector<string> v;
	v.push_back("1111");
	v.push_back("1111");
	v.push_back("1111");
	v.push_back("1111");
	v.push_back("1111");


	for (const auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


















int main()
{
	//test1_vector();
	test2_vector();
	/*test3_vector();*/
	//test4_vector();
	return 0;
}