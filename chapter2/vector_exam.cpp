#include<iostream>
#include<vector>
#include<array>
#include<string>
using namespace std;

int main() {

	array<string, 5> words{"a","b","c","d","e"};
	cout << words[1]<< endl;

	//make_move_iterator 
	// 
	vector<string> words_copy{make_move_iterator(begin(words)), make_move_iterator(end(words))};
	//move 로 words 원소들을  vector로 이동시켜서 빈 스트링 값이 나옴
	cout << words[1] << endl; //빈 원소 출력됨
	cout << words.size() << endl; //size는 그대로 5

	for (auto it = words_copy.begin(); it < words_copy.end(); it++) {
		cout << *it << endl;
	}

}