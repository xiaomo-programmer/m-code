#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <array>
using namespace std;

//c++11���ȶ�����ת����������չ

class A
{
public:
	 A(int a)
		:_a(a)//�������Ĺ��캯��
	{

	}
private:
	int _a;
};

class Point
{
public:
	 Point(int x = 0, int y = 0)//������Ĺ��캯��
		:_x(x), _y(y)
	{

	}

private:
	int _x;
	int _y;
};

//int main()
//{
//	//C++98
//	A a(1);
//	A a2 = 2;//����������֧����ʽ����ת��(�������)
//	string s = "mzp";
//	vector<string> v;
//	v.push_back(s);
//	v.push_back("qzy");
//
//
//	//C++11 ֧�ֶ���������ʽ����ת��
//
//	Point p1={ 1, 2 };  //��ʽ����ת��(�������)  ����1��2����һ����ʱ�������������ʱ���󿽱����죬�ڱ������Ż�  �Ż���ֱ����1��2����
//	Point p2{ 1, 2 };
//   decltype(it) copy2;
//	//auto �Ƶ��ǰ�˫�н��������֪�����ض�������ͣ��ή�Ϳɶ���
//	//auto �������������ͣ�����������ֵ����
//	//auto ��Ҫ����ʱ�Ƶ����ͣ��﷨��ĸ���
//	//auto �ײ�ʵ�ֽǶȣ�����ɺ���ָ����Ҫ�Ƚ���ջ֡
//}

//int main()
//{
//	
//		// �������ͱ���
//		int x1 = { 10 };
//		int x2{ 10 };
//		int x3 = 1 + 2;
//		int x4 = { 1 + 2 };
//		int x5{ 1 + 2 };
//		// ����
//		int arr1[5] {1, 2, 3, 4, 5};
//		int arr2[]{1, 2, 3, 4, 5};
//
//		// ��̬���飬��C++98�в�֧��
//		int* arr3 = new int[5]{1, 2, 3, 4, 5};
//
//		// ��׼����
//		vector<int> v{ 1, 2, 3, 4, 5 };
//		map<int, int> m{ { 1, 1 }, { 2, 2, }, { 3, 3 }, { 4, 4 } };
//	
//
//	return 0;
//}



//��Χfor �ײ�ԭ��������
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4, 5 };
//	for (auto e : v)
//	{
//		cout << e << endl;
//	}
//	int a[] = { 1, 2, 3, 4 };
//	for (auto e : a)
//	{
//		cout << e << endl;
//	}
//}


//final ���Ը�������final ����ʾ����������ܱ��̳� override






int main()
{
	array<int, 100> a1;
	array<int, 1000> a2;

	cout << sizeof(a1) << endl;
	cout << sizeof(a2) << endl;
	//vector�ڶ��ϣ�Ҳ����resizeҲ�ܴﵽ���������
	//array��ʵûɶ��
	//default �������� -�� һ����Ե��ǹ��캯��
	//delete  �������� -�� һ����Ե��ǿ�������͸�ֵ
	//c++ 98 ������/�����Ƽ��� -��1.ֻ������ʵ�֣�ԭ�����������Ҳ��ʵ�֣���������Ĭ�����ɣ�������һ�£���ֹ������Ĭ�����ɣ�
	//                            2.������˽�У���ֹ�����������涨�壩
	//c++11 �ṩdelete ���÷��������Ӽ򵥸��������
}