#ifndef TESTTESTCASE_H
#define TESTTESTCASE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//T(int,==100)/N(int,>=1,<=100)/x(float,>=0,<=1000),y(float,>=0,<=1000)
//T
//N
//x y
//x y
//...
//N
//x y
//x y

template <typename T>
class Variance {
private:
	int type; //0 : int, 1 : float, 2 : string
public:
	Variance()
	{
		type = 0;
	}
	string variance_names; // T N x y
	T upper_bound, lower_bound;
	void set_type(string type);
	//set upper_bound, lower_bound
	void set_range(string range);
};

//for문을 돌릴 단위
vector<string> for_tokens; // T(int,==100) N(int,>=1,<=100) x(float,>=0,<=1000),y(float,>=0,<=1000)
//같은 for문 안에 있는 변수
vector<string> in_for_tokens;
// x(float,>=0,<=1000) y(float,>=0,<=1000)//변수의 조건, [0] == type(int, char, string ...) [1], [2], ... == range(>=0, <=100, ==50)
vector<string> variance_constraint;
//n번째 변수의 속성
template <typename T>
vector<Variance<T>*> variance_attr;

//#1
//input : argv[1]
//output : variance_attr
void make_variance_attr();
ofstream* write_testcase_file(string path); //마지막에 ~.close();

//#2
void make_testcase();
//int, float ...
//get random value in range
template <typename T>
T get_value(T upper_bound, T lower_bound);
//string
string get_value();

//#3
void test_testcase();
//getline(openFile, line);
//cin << line;
ifstream* read_testcase_file(string path);


#endif