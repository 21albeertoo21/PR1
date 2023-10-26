#include <ostream>
#include <iostream>
#include "List.h"

using namespace std;

template <typename T>

class ListArray : public List<T>{
private:
        T* arr;
        int max; //tamaño actual del array
        int n; //número de elementos de la lista
        static const int MINSIZE = 2;
        void resize(int new_size){
        	T* arr_aux = new T[new_size];
        	if(new_size < n){ //caso remove
		        for(int i = 0; i < new_size; i++)
			        arr_aux[i] = arr[i];
			
			n--;
		}
		else{ //caso insert
			for(int i = 0; i < n; i++)
				arr_aux[i] = arr[i];
			for(int i = n; i < new_size; i++)
				arr_aux[i] = 0;
			
			n++;
		}
		delete[] arr; //liberamos el espacio de memoria de arr, para el nuevo array.
		arr = arr_aux;
		max  = new_size; //nuevo tamaño de arr
        }
public:
        ListArray(){
                arr = new T[MINSIZE];
                max = 2;
                n = 0;
        }
        ~ListArray(){
                delete[] arr;
        }

        T operator[](int pos){
                if(pos < 0 || pos >= n)
                        throw out_of_range("Numero introducido fuera de rango");
                else
                        return arr[pos];
        }
        friend ostream& operator<<(ostream &out, const ListArray<T> &list){
		out << "List -> [";
		for(int i = 0; i < list.n; i++)
			out << list.arr[i] << "  ";

		out << "]";
		return out;
	}
	
	void insert(int pos, T e) override{
		if(pos < 0 || pos > n)
                        throw out_of_range("La posición está fuera del intérvalo permitido");
		resize(n + 1);
		//tres casos posibles
		if(pos == n - 1){//append
                        arr[pos] = e;
		}
                else{
			for(int i = n - 1; i > pos; i--){
				arr[i] = arr[i - 1];
			}
			arr[pos] = e;
			for(int i = 0; i < n; i++)
				cout << arr[i] << " ";
			cout << endl;
                }
        }

        void append(T e)override{
		insert(n, e);
	}

	void prepend(T e)override{
		insert(0, e);
	}

	T remove(int pos)override{
		if(pos < 0 || pos >= n)
                        throw out_of_range("La posición está fuera del intérvalo permitido");
		else{	
			if(pos == n - 1){
				T aux = arr[pos];
				resize(n - 1);
				return aux;
			}
			else{
				T aux = arr[pos];
				for(int i = pos; i < n - 1; i++) //ponemos el valor que queremos eliminar en el último elemento del array y luego hacemos resize para eliminarlo
					arr[i] = arr[i + 1];
				
				arr[n - 1] = arr[pos];
				resize(n - 1);
				
				return aux;
			}	
		}
	}

	T get(int pos)override{
		if(pos < 0 || pos >= n)
			throw out_of_range("La posición está fuera del intérvalo permitido");
		else
			return arr[pos];
	}

	int search(T e)override{
		for(int i = 0; i < n; i++){
			if(arr[i] == e)
				return i;
		}
		return -1;
	}

	bool empty()override{
		if(size() == 0)
			return true;
		else
			return false;
	}

	int size()override{
		return n;
	}
};

