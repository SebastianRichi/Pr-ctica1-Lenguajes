#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{;
       string username, pwd;
       struct nodo *sgte;
};
 
typedef struct nodo *Tlist;
 
void insertStart(Tlist &lista, string username, string pwd){
     Tlist q;
     q = new(struct nodo);
     q->username = username;
     q->pwd = pwd;
     q->sgte = lista;
     lista = q;
}
 
void insertFinish(Tlist &lista, string username, string pwd){
     Tlist t, q = new(struct nodo);
     q->username = username;
     q->pwd = pwd;
     q->sgte = NULL;
     if(lista==NULL){
             lista = q;
     }else{
           t = lista;
           while(t->sgte!=NULL){
                 t = t->sgte;
           }
           t->sgte = q;
     }
}
 
int insertBeforeAfter()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n\t Opcion : "; cin>> _op;
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}
 
void insertElement(Tlist &lista, string username, string pwd, int pos){
     Tlist q, t;
     int i;
     q = new(struct nodo);
     q->username = username;
     q->pwd = pwd;
 
     if(pos==1){
         q->sgte = lista;
         lista = q;
     }else{
           int x = insertBeforeAfter();
           t = lista;
           for(i=1; t!=NULL; i++){
               if(i==pos+x){
                   q->sgte = t->sgte;
                   t->sgte = q;
                   return;
               }
               t = t->sgte;
           }
     }
}
 
void searchElement(Tlist lista, string username){
     Tlist q = lista;
     int i = 1, band = 0;
 
     while(q!=NULL){
           if(q->username==username){
               cout<<"\n\t Encontrado en la posicion : "<<i+1<<endl;
               band = 1;
           }
           q = q->sgte;
           i++;
     }
     if(band==0)
         cout<<"\n\t Usuario no encontrado...!"<<endl;
}
 
void showListUsers(Tlist lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->username << endl;
          lista = lista->sgte;
          i++;
     }
}

void showListPwd(Tlist lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->pwd << endl;
          lista = lista->sgte;
          i++;
     }
}
 
 
void deleteElement(Tlist &lista, string username){
    Tlist p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->username==username)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;

            cout<<"\n\t Usuario eliminado"<<endl;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 
void deleteRepeats(Tlist &lista, string username)
{
    Tlist q, ant;
    q = lista;
    ant = lista;
 
    while(q!=NULL)
    {
        if(q->username==username)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }
 
    }// fin del while
   
    cout<<"\n\n Usuarios eliminados!"<<endl;
}
 
void menu1()
{
    cout<<"\n\tLISTA ENLAZADA\n\n";
    cout<<" 1. Insertar al inicio               "<<endl;
    cout<<" 2. Insertar al final                "<<endl;
    cout<<" 3. Insertar en una posicion         "<<endl;
    cout<<" 4. Mostrar usuarios                 "<<endl;
    cout<<" 5. Mostrar contrasenas              "<<endl;
    cout<<" 6. Mostrar usuarios y contrasenas   "<<endl;
    cout<<" 7. Buscar elemento                  "<<endl;
    cout<<" 8. Eliminar elemento 'V'            "<<endl;
    cout<<" 9. Eliminar elementos con valor 'V' "<<endl;
    cout<<" 10. Salir                            "<<endl;
 
    cout<<"\n INGRESE UNA OPCION: ";
}
 





 
int main()
{
    Tlist lista = NULL;
    int op;     // Opcion del menu
    string _dato;  // Elemenento que se va a ingresar
    string _dato2;  // Elemenento 2 que se va a ingresar
    int pos;    // Posicion en la que se va a insertar
 
 
    system("color 0b");
 
    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n Username: "; cin>> _dato;
                 cout<< "\n Password: "; cin>> _dato2;
                 insertStart(lista, _dato, _dato2);
            break;
 
 
            case 2:
 
                 cout<< "\n Username: "; cin>> _dato;
                 cout<< "\n Password: "; cin>> _dato2;
                 insertFinish(lista, _dato, _dato2);
            break;
 
 
            case 3:
 
                 cout<< "\n Username: "; cin>> _dato;
                 cout<< "\n Password: "; cin>> _dato2;
                 cout<< "\n Posicion : ";       cin>> pos;
                 insertElement(lista, _dato, _dato2, pos);
            break;
 
 
            case 4:
 
                 cout << "\n\n Mostrando usuarios\n\n";
                 showListUsers(lista);
            break;

            case 5:
 
                 cout << "\n\n Mostrando contrasenas\n\n";
                 showListPwd(lista);
            break;

            case 6:
 
                 cout << "\n Mostrando usuarios\n";
                 showListUsers(lista);
                 cout << "\n Mostrando contrasenas\n";
                 showListPwd(lista);
            break;
 
 
            case 7:
 
                 cout<<"\n Usuario a buscar: "; cin>> _dato;
                 searchElement(lista, _dato);
            break;
 
            case 8:
 
                cout<<"\n Usuario a eliminar: "; cin>> _dato;
 
                deleteElement(lista, _dato);
            break;
 
            case 9:
 
                cout<<"\n Usuario repetido a eliminar: "; cin>> _dato;
 
                deleteRepeats(lista, _dato);
            break;
 
                    }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=10);
 
 
   system("pause");
   return 0;
}