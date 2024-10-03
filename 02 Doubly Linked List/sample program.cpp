#include<iostream>
#include<stdlib.h>
#include "List.cpp"

using namespace std;
int main(int argc, char *argv[]) {
	//create list
List list;
//adding items
list.add(11);
//list.add(11);
list.add(25);
//list.add(3);
//list.add(100);
//list.add(88);
// putting current to start
list.start();
cout << "List Element : " << list.get()  << endl;
list.next();
cout << "List Element : " << list.get()  << endl;
list.next();
cout << "List Element : " << list.get()  << endl;
//to display list
//while(list.next()){
//	cout << "List Element : " << list.get()  << endl;
//}
return 0;
}
