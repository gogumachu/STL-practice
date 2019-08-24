#include <iostream>
#include <algorithm>
#include <iterator> // iterator (istrea_iterator)
#include <string> // string
#include <memory> // smart pointer

//container
#include <list>
#include <deque>
#include <queue>

using namespace std;
void problem4();
void problem5();
void problem6();

int main() {
    //problem4();
    //problem5();
    problem6();
}

void problem4() {
    deque<shared_ptr<string>> dq;
    string word;
    while( !(cin >> word).eof()){
        dq.push_back(make_shared<string>(word));
    }
    cin.clear();
    list<shared_ptr<string>> li;
    copy(dq.begin(),dq.end(),back_inserter(li));
    //list는 landom access 를 제공하지 않아서 그냥 sort 함수 사용할수 없음
    // 그래서 list 의 멤버함수 sort를 사용해야 함
    auto compare_l = [](const shared_ptr<string> a, const shared_ptr<string> b){return *a < *b;};
    li.sort(compare_l);
    for(auto &a : li) {
        cout << *a <<"  ";
    }
    cout << endl;
}

void problem5() {
    string word;
    using strPtr = unique_ptr<string>;
    auto comp = [](const strPtr& s1, const strPtr& s2){return *s1 < *s2;};
    priority_queue<strPtr, vector<strPtr>,decltype(comp)> pq {comp};
    while(!(cin>>word).eof()) {
        pq.emplace(new string{word}); // emplace 는 저장할 객체 타입의 생성자를 바로 호출함
        // 여기서는 shared_ptr<string> 생성자를 호출
        // pq.push(make_unique<string>(word))  해도 됨
    }
    cin.clear();

    while(!pq.empty()) {
        cout << *pq.top() << "  ";
        pq.pop();
    }
    cout<<endl;
}

void problem6() {
    vector<unique_ptr<string>> v;
    string word;
    while(!(cin>>word).eof()) {
        v.emplace_back(new string(word));
    }
    auto comp = [](const unique_ptr<string>& s1, const unique_ptr<string>& s2) {return *s1 < *s2;};
    make_heap(v.begin(), v.end(),comp);

    for(const auto& s : v) {
        cout << *s << " ";
    }
    cout << endl;
}