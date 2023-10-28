#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>

class ListLinked : public List<T>{
	private:
		Node<T> *first; //puntero al siguiente nodo
		int n; //nº de elementos de la lista
	
	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}
		
		~ListLinked(){
			for(int i = 0; i < n; i++){
				Node<T> *aux = first->next;
				delete first;
				first = aux;
			}	
		}
		
		T operator[](int pos){
			if (pos >= 0 && pos < n) { 
                		Node<T> *aux = first;
                		for(int i = 0; i < pos; i++)
                			aux = aux->next;
                		return aux->data;
             		}
			else 
				throw out_of_range("Posición no válida del array\n"); 
			} 
		
		friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
			Node<T> *aux = list.first;
            		out << "List-> [";
            		for(int i = 0; i < list.n; i++){
                		out << aux->data << " "; 
                		aux = aux->next; 
            		}
            		out << "]"; 
			return out;
		}
		void insert(int pos, T e)override{
				if(pos < 0 || pos > n)
					throw out_of_range("Posición introducida fuera de rango");
				else{
					if(pos == 0)//prepend
						first = new Node<T>(e, first);
					else if(pos == n){ //append
						Node<T> *aux = first;
						while(aux->next != nullptr){ //Sale del bucle cuando aux se encuentra en el último nodo
							aux = aux->next;
						}	
						aux->next = new Node<T>(e, aux->next);
					}
					else{
						Node<T> *aux = first;
						for(int i = 0; i < pos; i++)
							aux = aux->next;
						aux->next = new Node<T>(e, aux->next);												
					}
					n++;
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
					throw out_of_range("Posición introducida fuera de rango");
			else{
				T result;
				if(pos == 0){
					Node<T> *aux = first;
					result = aux->data;
					first = first->next;
					delete aux;
				}
				else{
					Node<T>* aux = first->next;
					Node<T>* prev = first;
					for(int i = 1; i < pos; i++){
						aux = aux->next;
						prev = prev->next;
					}
					result = aux->data;
					prev->next = aux->next;
					delete aux; 
				}
				n--;
				return result;
			}
		}
		
		T get(int pos)override{
			if(pos < 0 || pos >= n)
					throw out_of_range("Posición introducida fuera de rango");
			else{
				Node<T>* aux = first;
				for(int i = 0; i < pos; i++)
					aux = aux->next;
				
				return aux->data;
			}
		}
		
		int search(T e)override{
			Node<T>* aux = first;
			for(int i = 0; i < n; i++){ //recorremos todo el array
				if(aux->data == e)
					return i;
				else
					aux = aux->next;
			}
			return -1;
		}
		
		bool empty()override{
			if(n == 0)
				return true;
			else
				return false;
		}
		
		int size()override{
			return n;
		};
				
};

