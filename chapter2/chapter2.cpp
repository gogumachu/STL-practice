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
    // unsinged int �� ������ ��� 49,50 ��°�� ������ �Ѿ �̻��� ���� ��µ�
    std::array<uint64_t,50> fibonacci; 
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    unsigned short int i {0};
    //generate : strat iterator, end interator, ���� ������ �Լ��� ����° ���ڷ� ����
    // lamda ���� ������ ĸó�� ������ ���� �������� ���� ���� ǥ������ ���࿡�� ���� �������� ���� ������
    std::generate(std::begin(fibonacci)+2,std::end(fibonacci),
    [i,&fibonacci]() mutable { return fibonacci[i+1] + fibonacci[i++];});

    std::cout<<i<<std::endl; //i �� ���� 0���� ��µ�
    for(size_t i{0}; i<50; i++){ //typedef unsigned int size_t
        std::cout<<fibonacci[i]<<" ";
        if(i%8 ==7)
            std::cout<<"\n";
    }
}

//vector
void problem2() {
    std::vector<std::string> cities;
    cities.reserve(10); // ������ �Ҵ��� �д�.
    std::cout<<" �������� �����ؼ� �Է�, �����Ϸ��� ctrl+Z ��������\n";
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
    std::cout<<"enter�� �����ؼ� ���� �̸� �Է��ϼ���. �� ������ �Է½� ����\n";
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