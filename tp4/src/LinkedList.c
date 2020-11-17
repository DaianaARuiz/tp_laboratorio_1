#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica e inicializa sus atributos
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
      this->size=0;
      this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
       returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode=NULL;

    if(this !=NULL && nodeIndex>=0 && nodeIndex < ll_len(this))
    {
        pNode= this->pFirstNode;

        for(int i=0;i<nodeIndex;i++)
        {
             pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
/*
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    Node* pNode;
    Node* newNode;

    int returnAux = -1;
    int len=ll_len(this);

    if(this != NULL && nodeIndex>-1 && nodeIndex<len)
    {
        //for(int i=0;i<nodeIndex;i++)
        //{
        if(pNode->pNextNode == NULL) //si es el ultimo
        {
            newNode=(Node*)malloc(sizeof(Node));

            if(newNode!=NULL)
            {
                newNode->pElement=pElement;
                newNode->pNextNode=NULL;
                pNode->pNextNode=newNode;
                this->size++;
                returnAux = 0;
            }else
            {
                if(nodeIndex==0)
                {
                    newNode->pElement=pElement;
                    newNode->pNextNode=NULL;
                    this->size++;
                    returnAux = 0;
                }
            }
        }
        //}
    }

    return returnAux;
}
*/

/*
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    Node* newNode= NULL;
    Node* previousNode= NULL;
    Node* nextNode=NULL;
    int returnAux = -1;
    int len=ll_len(this);

    if(this != NULL)
    {
       if( nodeIndex > -1 && nodeIndex > len)
       {
            newNode=(Node*)malloc(sizeof(Node));

            if(newNode!=NULL)
            {
                 newNode->pElement=pElement;

                 if(previousNode->pNextNode == NULL) //si es el ultimo
                 {
                    newNode->pNextNode=NULL;
                    previousNode->pNextNode=newNode;
                 }

                 if(nodeIndex==0)
                 {
                    newNode->pNextNode=NULL;
                    this->pFirstNode=newNode;
                 }else
                 {
                    previousNode = getNode(this,nodeIndex-1);
                    nextNode=
                    newNode->pNextNode=NULL;
                    this->pFirstNode = newNode;

                 }
            }
        }
        returnAux = 0;
        this->size++;
    }
    return returnAux;
}
*/

/*
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    Node* newNode= NULL;
    Node* previousNode= NULL;
    Node* nextNode=NULL;
    int returnAux = -1;

    if(this != NULL)
    {
       if(nodeIndex>=0 && nodeIndex < ll_len(this))
       {
            newNode=(Node*)malloc(sizeof(Node));

            if(newNode!=NULL)
            {
                 newNode->pElement=pElement;

                 if(nodeIndex==0)
                 {
                    nextNode= this->pFirstNode;
                    newNode->pNextNode=nextNode;
                    this->pFirstNode=newNode;

                 }else
                 {
                    previousNode = getNode(this,nodeIndex-1);
                    nextNode = getNode(this,nodeIndex);
                    newNode->pNextNode=nextNode;
                    previousNode->pNextNode=newNode;
                }
            }
        }
        returnAux = 0;
        this->size++;
    }
    return returnAux;
}
*/
/*
static int addNode(LinkedList* lista, int nodeIndex,void* pElement){ //size de la lista es la cantidad de nodos //index nodo es donde esta el nodo en la lista.
    int returnAux = -1;
    Node* newNode = malloc(sizeof(Node));
    if(lista != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(lista)){
       //estoy en condiciones de agregar un nodo.
       //para agregar un nodop tengo que preguntar en que posicion esta.
        if(lista->pFirstNode == NULL && nodeIndex == 0){
            //agregar el primer nodo.
            lista->pFirstNode = newNode;
            newNode->pElement = pElement;
            lista->size = ll_len(lista) + 1;
            returnAux = 0;
        }
        else{
            if(lista->pFirstNode != NULL && nodeIndex == 0){
                //agrego un nodo al principio de la lista
                Node* oldFirstNode = lista->pFirstNode;
                lista->pFirstNode = newNode;
                lista->pFirstNode->pNextNode = oldFirstNode;
                newNode->pElement = pElement;
                lista->size = ll_len(lista) + 1;
                returnAux = 0;
            }
            else{
               if(lista->pFirstNode != NULL && nodeIndex > 0 && nodeIndex < ll_len(lista)){
                    //agrego entre dos nodos
                    Node* oldNodeInIndex = getNode(lista,nodeIndex);//traigo al ocupa de nodeIndex
                    newNode->pNextNode = oldNodeInIndex;   //el nuevo nodo tiene como siguiente al ocupa
                    Node* previousNode = getNode(lista,nodeIndex - 1);  //traigo el nodo anterior a nodeIndex
                    previousNode->pNextNode = newNode;   //el nodo anterior a nodeIndex  tiene como siguiente al nuevo
                    newNode->pElement = pElement;
                    lista->size = ll_len(lista) + 1;
                    returnAux = 0;
                }
                else{
                    if(lista->pFirstNode != NULL && nodeIndex == ll_len(lista)){
                        //agrego al final
                        Node* lastNode = getNode(lista,nodeIndex - 1);//traigo al ultimo nodo
                        lastNode->pNextNode = newNode;   //el ultimo nodo tiene como siguiente al nuevo
                        newNode->pElement = pElement;
                        lista->size = ll_len(lista) + 1;
                        returnAux = 0;
                    }
                }
            }
        }
    }
    return returnAux;
}
*/
/*
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    Node* newNode= NULL;
    Node* previousNode= NULL;
    Node* oldNode=NULL;
    Node* lastNode=NULL;
    int returnAux = -1;

    if(this != NULL)
    {
       if(nodeIndex>=0 && nodeIndex <= ll_len(this))
       {
            newNode=(Node*)malloc(sizeof(Node));

            if(newNode!=NULL)
            {

                if(this->pFirstNode == NULL && nodeIndex == 0) //para agregar el primer nodo
                {
                    this->pFirstNode=newNode;
                    newNode->pElement=pElement;
                    returnAux = 0;
                    this->size++;

                }else
                {
                    if(this->pFirstNode != NULL && nodeIndex == 0)
                    {
                        oldNode= this->pFirstNode;
                        this->pFirstNode = newNode;
                        newNode->pNextNode = oldNode;
                         newNode->pElement=pElement;
                        returnAux = 0;
                        this->size++;
                    }else
                    {
                        if(this->pFirstNode != NULL && nodeIndex > 0 && nodeIndex < ll_len(this))
                        {
                             oldNode=getNode(this,nodeIndex);
                             newNode->pNextNode = oldNode;
                             previousNode = getNode(this,nodeIndex - 1);
                             previousNode->pNextNode = newNode;
                             newNode->pElement=pElement;
                             returnAux = 0;
                             this->size++;
                        }else{
                            if(this->pFirstNode != NULL && nodeIndex == ll_len(this))
                            {
                                 lastNode = getNode(lista,nodeIndex - 1);
                                lastNode->pNextNode = newNode;
                                newNode->pElement = pElement;
                                this->size++;
                                returnAux = 0;
                            }
                        }
                    }
                }
            }
       }

    }
    return returnAux;
}
*/
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node *newNode = NULL;
    Node *prevNode = NULL;
    Node *nextNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex<=ll_len(this))
    {
        newNode = (Node*) malloc (sizeof(Node));

        if(nodeIndex == 0)
        {
            if(ll_len(this)==0)
            {
                newNode->pNextNode = NULL;
            }
            else if(ll_len(this)>0)
            {
                nextNode = getNode(this, nodeIndex);
                newNode->pNextNode = nextNode;

            }
            newNode->pElement = pElement;
            this->pFirstNode = newNode;

        }else if(nodeIndex>0 && ll_len(this)>0)
        {
            prevNode = getNode(this, nodeIndex-1);
            newNode->pNextNode = prevNode->pNextNode;
            newNode->pElement = pElement;
            prevNode->pNextNode = newNode;

        }
        this->size++;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);
        addNode(this, len, pElement);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_get(LinkedList* this, int index)
{
    Node* pNode;
    void* returnAux = NULL;

     if(this != NULL)
    {
       if( index>=0 && index < ll_len(this))
       {
            pNode=getNode(this,index);

            if(pNode!=NULL)
            {
               returnAux = pNode->pElement;
            }
       }
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */int ll_set(LinkedList* this, int index,void* pElement)
{
    Node* pNode;
    int returnAux =-1;
    int len=ll_len(this);
    if(this!=NULL && index>-1 && index<len)
    {
        pNode=getNode(this,index);

        if(pNode!=NULL)
        {
            pNode->pElement=pElement;
            returnAux=0;
        }

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
/*
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAEliminar = NULL;
    Node* previuosNode = NULL;

     if(this != NULL && index >= 0 && index < ll_len(this))
    {
           nodoAEliminar=getNode(this,index);
           if(nodoAEliminar!=NULL)
           {
               if(index==0)
               {
                   this->pFirstNode=nodoAEliminar->pNextNode;
               }else
               {
                   previuosNode=getNode(this,index-1);
                   nodoAEliminar=previuosNode->pNextNode;
                   previuosNode->pNextNode= nodoAEliminar->pNextNode;
               }
               free(nodoAEliminar);
               this->size--;
               returnAux=0;
           }
        //free(nodoAEliminar);
    	//this->size--;
    }
    return returnAux;
}
*/
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeAux = NULL;
    Node* pNodeAuxSup = NULL;

     if(this != NULL && index >= 0 && index < ll_len(this))
    {
           pNodeAux=getNode(this,index);
           if(pNodeAux!=NULL)
           {
               if(index==0)
               {
                   this->pFirstNode=pNodeAux->pNextNode;
               }else
               {
                   pNodeAux=getNode(this, index - 1 );
                   pNodeAuxSup= pNodeAux->pNextNode;
                   pNodeAux->pNextNode= pNodeAuxSup->pNextNode;
               }
               free(pNodeAuxSup);
               this->size--;
               returnAux=0;
           }

    }
    return returnAux;
}



/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this!=NULL)
    {
        len= ll_len(this);
        for(int i=0;i<len;i++)
        {
           ll_remove(this, i);
        }

        this->pFirstNode = NULL;
        this->size = 0;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_clear(this)==0)
        {
            free(this);
        }
        this->size = 0;
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    void* auxElement=NULL;
    int returnAux = -1;
    int len;
    if(this!=NULL)
    {
       len= ll_len(this);
       for(int i=0;i<len;i++)
       {
           auxElement=ll_get(this,i);
           if(pElement==auxElement)
           {
              returnAux=i;
              break;
           }
       }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

