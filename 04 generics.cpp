#include<iostream>
#include<string>
using namespace std;
//defining tempelate
template<class T>
// generic function
void test(T a){
	cout << a;
}

//using generic with class
template<class Y>
class TestClass{
	private:
		Y a, b;
	public:
		void inputA(Y x){
			a = x;
		}
		void inputB(Y y){
			b = y;
		}
		void show(){
			cout << a<< endl;
			cout << b<< endl;
			
		}
};

//main
main (){
	// we are calling the function with two different data types and it is working
	test(2);
	test("\n akram");
	cout << "\n\n";
	TestClass<int> abc;
	abc.inputA(4);
	abc.show();
}
