#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void problem_1();
void problem_2();
void problem_3();

int main() {
//	problem_1();
//	problem_2();
	problem_3();
}

void problem_1()
{
	string strarr[]{ "brandy","pepper","hi" };
	for (auto iter = begin(strarr); iter != end(strarr); ++iter) {
		cout << *iter << endl;
	}
}

void problem_2() //�ҹ��ڸ� * �� �ٲ�
{
	string strarr[]{ "aBRANDYaa","iPEPPERoo","eHIee" };
	function<string(string)>op{
		[](string s) {
			 for (auto iter = begin(s); iter != end(s); ++iter) {
				 if (*iter == 97 || *iter == 101 || *iter == 105 || *iter == 111 || *iter == 117) //�ҹ��� ������ ��� * �� �ٲ��ش�. a,e,i,o
					 *iter = '*';
			}
			 return s;
		}		
	};
	transform(begin(strarr),end(strarr), ostream_iterator<string>(cout, " "), op);
}

void problem_3() { // �ҹ��ڸ� �빮�ڷ� �ٲ㼭 ���
	string strarr[]{ "brandy","pepper","hi" };

	function<string(string)>op{
		[] (string s) {
			transform(begin(s), end(s),begin(s),::toupper);
			return s;
		}
	};

	transform(begin(strarr),end(strarr),ostream_iterator<string>(cout,"    "),op);
	
}