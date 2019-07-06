#include <iostream>
#include <string> //string
#include <algorithm> //copy
//container
#include <deque>
#include <list>
//adapter
#include <stack>
#include <queue> //priority_queue

void problem1();
void problem2();
void problem3();

int main() {
 //   problem1();
 //   problem2();
    problem3();
}

void problem1() {
    std::string word;
    std::deque<std::string> words;
    std::list<std::string> c_words;
    while(true){
        //words seperated by spaces, press crtl+Z to input end
        if((std::cin >> word).eof())
            break;
        //emplace는 객체 타입의 생성자를 호출해 컨테이너 내부에서 객체 생성함
        words.emplace_back(word);
    }
    //back_inserter : return back_insert_iterator
    //insert new elements automatically at the end of the container
    //Container should be a container class with member push_back defined.
    std::copy(words.begin(),words.end(),std::back_inserter(c_words));

    c_words.sort();
    //Ranged-based for loops
    for(const auto &it : c_words) {
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}

//stack 컨테이너를 이용해 키보드로 입력한 한 줄 문장에 있는 문자들의 순서를 뒤집는 프로그램
// 공백, 문장부호 무시 회문 여부도 출력 (로꾸꺼 로꾸꺼)
// input : aaB AA
//output : AABaa is  Palindrome? 1
void problem2() {
    std::stack<char> stack1;
    std::stack<char> stack2;
    bool is_palin = true;
    char a =' ';
    while((a = std::cin.get()) != '\n') {
        int aschi = a;
        //only alphabet
        if( (aschi>=65 && aschi<=90) || (aschi>=97 && aschi<=122) ) {
            stack1.emplace(a);
        }
    }
    //stack size;
    size_t size = stack1.size();
    size_t half_size = size/2;
    //절반만 다른 스택에 넣은 뒤에 비교한다.
    for(size_t i=0; i<half_size; i++) {
        char b = stack1.top();
        stack2.emplace(b);
        stack1.pop();
        std::cout<<b;
    }
    //홀수면
    if(size%2==1){
        std::cout<<stack1.top();
        stack1.pop();
        half_size++;
    }
    for(size_t i = half_size; i<size; i++) {
        char s1 = stack1.top();
        char s2 = stack2.top();
        std::cout<<s1;
        if(tolower(s1) != tolower(s2))
            is_palin = false;
        stack1.pop();
        stack2.pop();
    }
     std::cout<<"\nis  Palindrome? "<<is_palin<<std::endl;
}

//priority queue 이용해서 입력된 단어들 알파벳 역순으로 출력
//input : tree ant blue moon four cat
//output : tree moon four cat blue ant
void problem3() {
    std::priority_queue<std::string> pq;
    std::string str;
    while(!(std::cin >> str).eof()) {
        pq.emplace(str);
    }
    while (!pq.empty()) {
        std::cout<<pq.top()<<" ";
        pq.pop();
    }
    std::cout<<std::endl;
}