#include <ostream>
#include <vector>
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
                for(int i = 0; i < max; i++)
                        arr_aux[i] = arr[i];

                delete[] arr; //liberamos el espacio de memoria de arr, para el nuevo array.
		
		arr = arr_aux;
         
                max = new_size; //nuevo tamaño de arr
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
                if(pos < 0 || pos > max - 1)
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
	
	virtual void insert(int pos, T e) override{
		if(pos < 0 || pos > max - 1)
                        throw out_of_range("La posición está fuera del intervalo permitido");
                
		if(size() == max)
			resize(max + 1);

		//tres casos posibles
                if(pos == 0) //prepend
                        prepend(e);
                else if(pos == max - 1)//append
                        append(e);
                else{	
			resize(max + 1);
			for(int i = pos; i < max; i++){
				arr[i] = arr[i + 1];
			}
			arr[pos] = e;
			n++;
                }
        }

        virtual void append(T e)override{
		resize(max + 1);
		arr[max - 1] = e;
		n++;
	}

	virtual void prepend(T e)override{
		resize(max + 1);
		for(int i = 0; i < max; i++){
			arr[i] = arr[i + 1];
		}
		arr[0] = e;
		n++;
	}

	virtual T remove(int pos)override{
		if(pos < 0 || pos > max - 1)
                        throw out_of_range("La posición está fuera del intervalo permitido");
		else{	
			if(pos == max - 1){
				T aux = arr[pos];
				resize(max - 1);
				n--;
				return aux;
			}
			else{
				T aux = arr[pos];
				for(int i = pos; i < max - 1; i++)
					arr[i] = arr[i + 1];

				resize(max - 1);
				n--;
				return aux;
			}	
		}
	}

	virtual T get(int pos)override{
		if(pos < 0 || pos > max - 1)
			throw out_of_range("La posición está fuera del intérvalo permitido");
		else
			return arr[pos];
	}

	virtual int search(T e)override{
		for(int i = 0; i < max; i++){
			if(arr[i] == e)
				return i;
		}
		return -1;
	}

	virtual bool empty()override{
		if(size() == 0)
			return true;
		else
			return false;
	}

	virtual int size()override{
		return n;
	}
};

