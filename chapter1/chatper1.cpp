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

void problem_2() //소문자를 * 로 바꿈
{
	string strarr[]{ "aBRANDYaa","iPEPPERoo","eHIee" };
	function<string(string)>op{
		[](string s) {
			 for (auto iter = begin(s); iter != end(s); ++iter) {
				 if (*iter == 97 || *iter == 101 || *iter == 105 || *iter == 111 || *iter == 117) //소문자 모음일 경우 * 로 바꿔준다. a,e,i,o
					 *iter = '*';
			}
			 return s;
		}		
	};
	transform(begin(strarr),end(strarr), ostream_iterator<string>(cout, " "), op);
}

void problem_3() { // 소문자를 대문자로 바꿔서 출력
	string strarr[]{ "brandy","pepper","hi" };

	function<string(string)>op{
		[] (string s) {
			transform(begin(s), end(s),begin(s),::toupper);
			return s;
		}
	};

	transform(begin(strarr),end(strarr),ostream_iterator<string>(cout,"    "),op);
	
}