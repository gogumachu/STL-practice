#include<iostream>
#include <algorithm> // transform()
#include <iterator>
#include <functional>

using namespace std;

/*함수 객체(Functor)용 클래스
구조체는 모든게 public인 c++클래스로 간주 가능
(class의 default 접근 제한자는 private, struct는 public)
함수객체용 클래스는 클래스 정의할 때
내부에 함수 호출 연산자만 오버로드 해서 정의해주면 됨
*/
class Root {
	public: 
		//함수 객체를 만들기 위해서는 함수 호출 연산자를 반드시 오버로딩 해야 한다.
		double operator() (double x) {
			return x*x;
		}
};

int main() {
	//uniform initalization 유니폼 초기화 :  {} 를 이용한 초기화
	// 단일 초기화 메커니즘 제공을 위해 추가됨, 형 변환을 허용하지 않음, 변수를 다른 형의 자료값으로 초기화하려 할경우 컴파일 에러
//	int a{ 5.5 };  //compile error!
	int a{ 5 };

	//배열은 유니폼 초기화 형식취급이 안되는듯 int로 선언해도 아래의 경우 컴파일 된다.
	double data[]{ 1.5,2.3,3.5,4,5 };
	
	//functor 전달
	Root root;
	cout << "functor 전달" << endl;
	//ostream_iterator 는 스트림 반복자, 두번째 인자는 출력할 다음에 쓸 구분자 문자열
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), root);

	//labmda 표현식 전달
	//a 의 복사본이 증가한다. 실제 a 값은 변경 안됨 변경하게 하고 싶으면 &a 로 캡쳐
	cout << "\nlamda 전달" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [a](double x)mutable {return x*(++a); });
	//a : 6~10

	//labmda 표현식 전달2
	//위에서의 a 값이 여기서 유지되지는 않는다.
	cout << "\nlamda 전달2" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [a](double x)mutable {return x*(a); });


	//function<> 타입 변수 인수로 사용
	cout << "\nfunctional type" << endl;
	function<double(double)> op{ [](double x) {return x*x; } };
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), op);

	//다른 람다 표현식을 호출하는 람다 표현식 인수로 사용
	cout << "\nlamda lamda" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [&op](double x) {return op(x)*op(x); });
	
	cout << endl;
	cout << "a is : " << a << endl;

}