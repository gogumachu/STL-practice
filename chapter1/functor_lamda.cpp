#include<iostream>
#include <algorithm> // transform()
#include <iterator>
#include <functional>

using namespace std;

/*�Լ� ��ü(Functor)�� Ŭ����
����ü�� ���� public�� c++Ŭ������ ���� ����
(class�� default ���� �����ڴ� private, struct�� public)
�Լ���ü�� Ŭ������ Ŭ���� ������ ��
���ο� �Լ� ȣ�� �����ڸ� �����ε� �ؼ� �������ָ� ��
*/
class Root {
	public: 
		//�Լ� ��ü�� ����� ���ؼ��� �Լ� ȣ�� �����ڸ� �ݵ�� �����ε� �ؾ� �Ѵ�.
		double operator() (double x) {
			return x*x;
		}
};

int main() {
	//uniform initalization ������ �ʱ�ȭ :  {} �� �̿��� �ʱ�ȭ
	// ���� �ʱ�ȭ ��Ŀ���� ������ ���� �߰���, �� ��ȯ�� ������� ����, ������ �ٸ� ���� �ڷᰪ���� �ʱ�ȭ�Ϸ� �Ұ�� ������ ����
//	int a{ 5.5 };  //compile error!
	int a{ 5 };

	//�迭�� ������ �ʱ�ȭ ��������� �ȵǴµ� int�� �����ص� �Ʒ��� ��� ������ �ȴ�.
	double data[]{ 1.5,2.3,3.5,4,5 };
	
	//functor ����
	Root root;
	cout << "functor ����" << endl;
	//ostream_iterator �� ��Ʈ�� �ݺ���, �ι�° ���ڴ� ����� ������ �� ������ ���ڿ�
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), root);

	//labmda ǥ���� ����
	//a �� ���纻�� �����Ѵ�. ���� a ���� ���� �ȵ� �����ϰ� �ϰ� ������ &a �� ĸ��
	cout << "\nlamda ����" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [a](double x)mutable {return x*(++a); });
	//a : 6~10

	//labmda ǥ���� ����2
	//�������� a ���� ���⼭ ���������� �ʴ´�.
	cout << "\nlamda ����2" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [a](double x)mutable {return x*(a); });


	//function<> Ÿ�� ���� �μ��� ���
	cout << "\nfunctional type" << endl;
	function<double(double)> op{ [](double x) {return x*x; } };
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), op);

	//�ٸ� ���� ǥ������ ȣ���ϴ� ���� ǥ���� �μ��� ���
	cout << "\nlamda lamda" << endl;
	transform(begin(data), end(data), ostream_iterator<double>(cout, " "), [&op](double x) {return op(x)*op(x); });
	
	cout << endl;
	cout << "a is : " << a << endl;

}