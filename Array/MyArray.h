#include"Array.h"

template<class T>
class MyArray:public Array<T>
{
public:
	MyArray(int);
	void addValue(T ss);
	T removeValue();
	bool isEmpty();
	bool isFull();
	void display();
};
template <class T>
MyArray<T>::MyArray(int ss):Array<T>(ss)
{

}

template<class T>
bool MyArray<T>::isFull(){
	if(Array<T>::maxSize==Array<T>::currentSize){
		return true;
	}
	return false;
}

template<class T>
bool MyArray<T>::isEmpty(){
	if(Array<T>::currentSize==0){
		return true;
	}
	return false;
}

template <class T>
void MyArray<T>::display()
{
	cout << "Maximum Size: " << Array<T>::maxSize << endl;
	cout << "Current Size: " << Array<T>::currentSize << endl;

	for (int i = 0; i < Array<T>::currentSize; i++)
		cout << i << ". " << Array<T>::arr[i] << endl;
}

template<class T>
void MyArray<T>::addValue(T v){
	if(!isFull()){
		Array<T>::arr[Array<T>::currentSize] = v;
		Array<T>::currentSize++;
	}
	else
		cout << "Array is already FULL" << endl;
}

template<class T>
T MyArray<T>::removeValue(){
	if (isEmpty())
	{
		cout << "Array is Empty, returning ZERO" << endl;
		return 0;
	}
	Array<T>::currentSize--;
	return Array<T>::arr[Array<T>::currentSize];
}