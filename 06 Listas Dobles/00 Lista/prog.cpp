#include <iostream>

using namespace std;

template <class T>
class ListaDoble
{
    class Nodo
    {
    public:
        T info;
        Nodo *ant;
        Nodo *sig;
    };
    Nodo *Raiz;
    int tam;

public:
    ListaDoble()
    {
        Raiz = NULL;
        tam = 0;
    }
    ~ListaDoble()
    {
        eliminarTodos();
    }

    void agregarInicio(T dato)
    {
        Nodo *nuevo;
        // crear nuevo nodo
        nuevo = new Nodo;
        nuevo->info = dato;
        nuevo->ant = NULL;
        nuevo->sig = NULL;

        nuevo->sig = Raiz; // Coloca nodo al inicio de lista

        if (Raiz != NULL)      // Si no esta vacía
            Raiz->ant = nuevo; // Hacer referencia al nuevo primer

        Raiz = nuevo; // El inicio de lista cambia al nuevo
        tam++;
    }

    T eliminarInicio()
    {
        Nodo *primero, *temp;
        T dato;
        primero = Raiz;
        if (primero != NULL)
        {
            temp = primero->sig; // Guarda dirección el segundo nodo
            dato = primero->info;
            delete primero; // Libera la memoria del primer nodo
            primero = temp; // El segundo nodo pasa a ser el primero
            if (primero != NULL)
            {                   // Pregunta si no quedo vacía
                Raiz = primero; // Cambia la dirección del inicio de lista
                primero->ant = NULL;
            }
            else
            {
                Raiz = NULL;
            }
            tam--;
        }
        return dato;
    }
    void imprimir()
    {
        Nodo *aux;
        aux = Raiz;

        while (aux != NULL)
        {
            cout << aux->info << " ";
            aux = aux->sig;
        }
        cout << endl;
    }

    void eliminarTodos()
    {
        Nodo *aux;
        while (Raiz != NULL)
        {
            aux = Raiz;
            Raiz = Raiz->sig;
            delete aux;
        }
        tam = 0;
    }

    void invertir()
    {
        Nodo *temp = NULL;
        Nodo *aux = Raiz;
        while (aux != NULL)
        {
            Nodo *nuevo;
            // crear nuevo nodo
            nuevo = new Nodo;
            nuevo->info = aux->info;
            nuevo->ant = NULL;
            nuevo->sig = NULL;

            nuevo->sig = temp;     // Coloca nodo al inicio de lista
            if (temp != NULL)      // Si no esta vacía
                temp->ant = nuevo; // Hacer referencia al nuevo primer

            temp = nuevo; // El inicio de lista cambia al nuevo
            aux = aux->sig;
        }
        eliminarTodos();
        Raiz = temp;
    }
    int obtenerNumElementos()
    {
        return tam;
    }

    bool esVacia()
    {
        return Raiz == NULL ? true : false;
    }

    int obtenerNumElementos()
    {
        return tam;
    }

    bool esVacia()
    {
        // return tam == 0?true:false;
        return Raiz == NULL ? true : false;
    }
};

int main()
{

    ListaDoble<int> miLista;

    miLista.agregarInicio(6);
    miLista.agregarInicio(8);
    miLista.agregarInicio(7);
    miLista.agregarInicio(1);
    miLista.agregarInicio(5);
    miLista.imprimir();
    miLista.invertir();
    cout << "nueva lista " << endl;
    miLista.imprimir();
    miLista.eliminarInicio();
    cout << "nueva lista " << endl;
    miLista.imprimir();
    miLista.eliminarInicio();
    cout << "nueva lista " << endl;
    miLista.imprimir();

    return 0;
}