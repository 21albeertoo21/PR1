#include <ostream>
#include <vector>
#include "List.h"

using namespace std;

template <typename T>

class ListArray : public List<T>{
private:
	T* arr;
	T* arr_aux;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
		arr_aux = new int[new_size];
		for(int i = 0; i < new_size; i++)
			arr_aux[i] = arr[i];
		
		delete[] arr; //liberamos el espacio de memoria de arr, para el nuevo array.

		arr = new int[new_size];
		for(int j = 0; j < new_size; j++)
			arr[j] = arr_aux[j];

		max = new_size; //nuevo tamaño máximo de arr
	}
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

	//friend ostream& operator<<(ostream &out, const ListArray<T> &list){

	virtual void insert(int pos, T e) override{
		if(pos < 0 || pos > arr.size() - 1)
			throw out_of_range("La posición está fuera del intervalo permitido");				//tres casos posibles
		if(pos == 0) //prepend
			prepend(e);
		else if(pos == n)//append
			append(e);
		else{
			resize(arr.size() + 1);
			for(int i = pos; i < max; i++){
				arr[i] = arr[i + 1];
			}
			arr[pos] = e;
		}
	}

	//virtual void append(T e)

};
