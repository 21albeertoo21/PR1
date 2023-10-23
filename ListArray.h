#include <ostream>
#include <vector>
#include "List.h"

using namespace std;

template <typename T>

class ListArray : public List<T>{
private:
	static const int MINSIZE = 2;
	vector<T> arr[MINSIZE];;
	vector<T> arr_aux[MINSIZE];
	int max; //tamaño actual del array
	int n; //numero de elementos que contiene la lista
	
	void resize(int new_size){
		arr.resize(new_size);
	}
	
public:
	ListArray(){
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
		if(pos < 0 || pos > arr.size())
			throw out_of_range("La posición está fuera del intervalo permitido");				//tres casos posibles
		if(pos == 0) //prepend
			prepend(e);
		else if(pos == n)//append
			append(e);
		else
			arr.insert(arr.begin() + pos, e);
	}

	virtual void append(T e)override{
		arr.push_back(e); //funcion que inserta elemento al final de la lista
	}

	virtual void prepend(T e)override{
		arr.insert(arr.begin(), e);
	}

	virtual T remove(int pos)override{
		if(pos < 0 || pos > arr.size())
                        throw out_of_range("La posición está fuera del intervalo permitido");
		vector<T> aux[1];
		aux[1] = arr[pos];
		arr.erase(arr.begin() + pos);

		return aux[1];
	}

	virtual T get(int pos)override{
		if(pos < 0 || pos > arr.size())
                        throw out_of_range("La posición está fuera del intervalo permitido");

		return pos;
	}
	
	virtual int search(T e)override{
		for(int i = 0; i < arr.size(); i++){
			if(arr[i] = e)
				return i;
		}
		return -1; //Si ha llegado a este return es que no ha encontrado el elemento e
	}

	virtual bool empty()override{
		if(arr.size() == 0)
			return true;
		else
			return false;
	}

	virtual int size()override{
		return arr.size();
	}


};
