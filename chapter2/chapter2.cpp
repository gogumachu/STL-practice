#include <iostream>
#include <cstdint> // uint64_t

#include <array> //array
#include <list> // list
#include <deque> //deque
#include <vector> //vector

#include <algorithm> //gnerate, copy
#include <string> //string
#include <iterator> // for iterator (istream_iterator, back_inserter..)

void problem1();
void problem2();
void problem3();
void problem4();

int main() {
   // problem1();
   //problem2();
   //problem3();
   problem4();

}
//array
void problem1() {
    //unsinged int : 0 ~ 4,294,967,295
    // unsinged int 로 정의할 경우 49,50 번째가 범위를 넘어서 이상한 값이 출력됨
    std::array<uint64_t,50> fibonacci; 
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    unsigned short int i {0};
    //generate : strat iterator, end interator, 값을 생성할 함수를 세번째 인자로 받음
    // lamda 에서 값으로 캡처한 변수의 로컬 복제본의 값은 람다 표현식의 실행에서 다음 실행으로 값이 유지됨
    std::generate(std::begin(fibonacci)+2,std::end(fibonacci),
    [i,&fibonacci]() mutable { return fibonacci[i+1] + fibonacci[i++];});

    std::cout<<i<<std::endl; //i 의 값은 0으로 출력됨
    for(size_t i{0}; i<50; i++){ //typedef unsigned int size_t
        std::cout<<fibonacci[i]<<" ";
        if(i%8 ==7)
            std::cout<<"\n";
    }
}

//vector
void problem2() {
    std::vector<std::string> cities;
    cities.reserve(10); // 공간을 할당해 둔다.
    std::cout<<" 공백으로 구분해서 입력, 종료하려면 ctrl+Z 누르세요\n";
    //copy(InputIterator first, InputIterator last, OutputIterator result)
    //back_inserter : return back_insert_iterator
    //insert new elements automatically at the end of the container
    //Container should be a container class with member push_back defined.
    std::copy(std::istream_iterator<std::string> {std::cin}, std::istream_iterator<std::string> {},
        std::back_inserter(cities));

    std::sort(cities.begin(),cities.end());

    std::copy(std::begin(cities),std::end(cities),std::ostream_iterator<std::string> {std::cout," "});
}

//list
void problem3() {
    std::cout<<"List\n";
    std::list<std::string> cities;
    std::string city;
    std::cout<<"enter로 구분해서 도시 이름 입력하세요. 빈 라인을 입력시 끝남\n";
    while(getline(std::cin, city,'\n'), !city.empty())
        cities.emplace_back(city);

    //list has no random access iterator ,so it can't use <algorithm> sort
    //we have to use list's sort
    cities.sort();

    std::copy(std::begin(cities),std::end(cities),std::ostream_iterator<std::string>{std::cout," "});

}

void problem4() {
    std::list<std::string> cities {"Seoul", "New York", "Busan", "Pari","London"};
    std::deque<std::string> d_cities;
    //front_inserter : return front_insert_iterator
    // front_insert_iterator call push_front()
    std::copy(std::begin(cities),std::end(cities),std::front_inserter(d_cities));
    sort(d_cities.begin(),d_cities.end());
    for(auto it = std::begin(d_cities); it!=std::end(d_cities); it++){
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";
}