#include <ostream>
#include <vector>
#include "List.h"

using namespace std;

template <typename T>

class ListArray : public List<T>{
private:
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
		int arr_aux = new int[new_size];
		for(int i = 0; i < new_size; i++)
			arr_aux[i] = arr[i];
		delete arr[];
		arr = new int[new_size];
		for(int i = 0; i < new_size; i++)
			arr[i] = arr_aux[i];

		max = new_size; //nuevo tamaño máximo de arr

public:
	ListArray(){
		arr = new int[MINSIZE];
		max = 2;
		n = 0;
	}	
	~ListArray(){
		delete[] arr;
	}

	T operator[](int pos){
		if(pos < 0 || pos > arr.size() - 1)
			throw out_of_range("Numero introducido fuera de rango");		
		else
		 	return arr[pos];
	}
}
	//friend ostream& operator<<(ostream &out, const ListArray<T> &list)

:w
:!g++ -c ListArray.h

