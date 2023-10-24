#include <ostream>

using namespace std;

template <typename T>
class Node{
	public:
		//atributos
		T data; 
		Node<T>* next; //puntero al siguiente nodo
		
		//métodos
		Node(T data, Node<T>* next = nullptr){
			this->data = data;
			this->next = next;
		}

		friend ostream& operator<<(ostream &out, const Node<T> &node){
		       out << "Node -> [ ";
	       		out << node.data << " ]";
	 		return out;
		}		
};		
