#include <iostream>
using namespace std;

template<class T>
class Array
{
protected:
	T* arr;
	int maxSize,currentSize;
public:
	Array(int);
	virtual void addValue(T ss)=0;
	virtual T removeValue()=0;
	virtual bool isEmpty()=0;
	virtual bool isFull()=0;
};
template<class T>
Array<T>::Array(int s){
	arr = new T[s];
	maxSize =s;
	currentSize=0;
}