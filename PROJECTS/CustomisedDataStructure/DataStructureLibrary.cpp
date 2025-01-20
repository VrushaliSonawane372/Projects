#include<iostream>
using namespace std;

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    public:
        struct nodeSL<T> * head;
        int iCount;

        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no , int ipos);
        void DeleteFirst(); 
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct nodeSL<T> * newn = NULL;
    newn = new nodeSL<T>;    
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;

    newn = new nodeSL<T>;   
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no , int ipos)
{
    int i = 0;
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = NULL;

    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new nodeSL<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for(i =1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        head = head -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    int i = 0;
    struct nodeSL<T> * temp = NULL;
    struct nodeSL<T> * target = NULL;

    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;

        for(i =1; i< ipos -1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp -> next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = head;

    cout<<"Elements of LinkedList are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}



//nodeSC(SinglyCircular)
template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;

};

template <class T>
class SinglyCL
{
    public:
    int iCount;
    struct nodeSC<T> * head;
    struct nodeSC<T> * tail;
 
    SinglyCL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no,int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
    
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct nodeSC<T> * newn = NULL;
    newn = new nodeSC<T>;

    newn->next = NULL;
    newn->data = no;

    if((head == NULL) && (tail == NULL))
    {
    head = newn;
    tail = newn;
    }
    else
    {
    newn->next = head;
    head = newn;
    }
    tail->next = head;
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeSC<T> * newn = NULL;
    newn = new nodeSC<T>;

    newn->next = NULL;
    newn->data = no;

    if((head == NULL) && (tail == NULL))
    {
    head = newn;
    tail = newn;
    }
    else
    {
    tail->next = newn;
    tail = newn;

    }
    tail->next = head;
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T no,int ipos)
{
    int i = 0;
    if((ipos < 1) && (ipos > iCount))
    {
    cout<<"Invalid Position..\n";
    }
    if(ipos == 1)
    {
    InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
    InsertLast(no);
    }
    else
    {
    struct nodeSC<T> * temp = NULL;
    struct nodeSC<T> * newn = NULL;
    newn = new nodeSC<T>;
    newn->next = NULL;
    newn->data = no;

    temp = head;
    for(i = 1; i < ipos - 1; i++)
    {
    temp = temp -> next;
    }
    newn->next = temp->next;
    temp->next = newn;
    iCount++;
    }
}

template <class T>
void SinglyCL<T> ::  DeleteFirst()
{
    struct nodeSC<T> * temp = NULL;
    cout<<"Delete First element..\n";
    if((head == NULL) && (tail == NULL))
    {
    return;
    }
    else if(head == tail)
    {
    free(head);
    head = NULL;
    tail = NULL;
    }
    else
    {
    temp = head;

    head = head->next;
    free(temp);
    tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeSC<T> * temp = NULL;
    cout<<"Delete Last element..\n";
    if((head == NULL) && (tail == NULL))
    {
    return;
    }
    else if(head == tail)
    {
    free(head);
    head = NULL;
    tail = NULL;
    }
    else
    {
    temp = head;
    while(temp->next != tail)
    {
    temp = temp->next;
    }
    free(temp->next);
    tail = temp;
    tail -> next = head;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>:: DeleteAtPos(int ipos)
{
    int i = 0;
    if((ipos < 1) && (ipos > iCount))
    {
    cout<<"Invalid Position..\n";
    }
    if(ipos == 1)
    {
    DeleteFirst();
    }
    else if(ipos == iCount)
    {
    DeleteLast();
    }
    else
    {
    struct nodeSC<T> * temp = NULL;
    struct nodeSC<T> * target = NULL;
    temp = head;
    for(i = 1; i < ipos - 1; i++)
    {
    temp = temp -> next;
    }
    target = temp->next;
    temp->next = target->next;
    delete target;


    iCount--;
    }
}

template <class T>
void SinglyCL<T> :: Display()
{
    if((head == NULL) && (tail == NULL))
    {
    cout<<"LinkedList is Empty..\n";
    }
    if(head == tail)
    {
    cout<<"Linked List Contains one node..\n";
    }
    do
    {
    cout<<"| "<<head->data<<"|->";
    head = head->next;
    }while(head != tail->next);
    cout<<"\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iCount;  
    cout<<"\n"; 
}



//DoublyLL

 
template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
    struct nodeDL<T>* head;
    int iCount;
    public:
    DoublyLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no,int iPos);  
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos); 
    void Display(); 
    int Count();
    
   
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    head = NULL;
    iCount  = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeDL<T> * newn = NULL; 


    newn = new nodeDL<T>;
    newn->prev = NULL;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeDL<T> *newn = NULL;
    struct nodeDL<T> * temp = NULL;
    newn = new nodeDL<T>;
    newn->prev = NULL;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
        iCount++;
}

template <class T>  
void DoublyLL<T> :: InsertAtPos(T no,int iPos)
{
    struct nodeDL<T> * temp = NULL;
    struct nodeDL<T> * newn = NULL;
    int i = 0;
    // iCount = Count();
    cout<<"Insert At Pos..\n";
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position..\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeDL<T> *newn = NULL;
        newn = new nodeDL<T>;
        newn->next = NULL;
        newn->data = no;

        temp = head;
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}   

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    struct nodeDL<T> * temp = NULL;
    cout<<"Delete First: \n";
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        head = temp->next;
        delete temp;
        temp = NULL;
    }
        iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct nodeDL<T> * temp = NULL;
    cout<<"Delete Last: \n";
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
      iCount--;
}

template <class T>   
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    cout<<"Delete At Posiion..\n";
    struct nodeDL<T> * temp = NULL;
    struct nodeDL<T> * target = NULL;
        int  i = 0;
    
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position..\n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp->next;

        free(target);

        iCount--;
            
    }
} 

template <class T>
void DoublyLL<T> :: Display()
{
    struct nodeDL<T> * temp = NULL;
    temp = head;
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}


//DoublyCL

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;

};

template <class T>
class DoublyCL
{
    public:
    int iCount;
    struct nodeDC<T> *head;
    struct nodeDC<T> *tail;
    DoublyCL();
    
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no,int ipos) ;  
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos); 
    void Display();
    int Count();
     
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    iCount = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct nodeDC<T> *newn = NULL;
    newn = new nodeDC<T>;
    newn->prev = NULL;
    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    tail->next = head;
    head = tail->next;

    iCount++;
}


template <class T>
void DoublyCL<T> ::  InsertLast(T no)
{
    struct nodeDC<T> * newn = NULL;
    newn = new nodeDC<T>;
    newn->prev = NULL;
    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;

        tail->next = head;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;

        tail = newn;

    }
    tail->next = head;
    head->prev = tail;

    iCount++;

}

template <class T>
void DoublyCL<T> ::  InsertAtPos(T no,int ipos)
{
    int i = 0;

    if((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid Position..\n";
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeDC<T> *newn = NULL;
        newn = new nodeDC<T>;
        newn->prev = NULL;
        newn->data = no;
        newn->next = NULL;

        struct nodeDC<T> *temp = NULL;
        temp = head;

        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp->next;
        temp->next = newn;

    iCount++;
    } 
}

template <class T>
void DoublyCL<T> ::  DeleteFirst()
{
    if((head == NULL) && (tail == NULL))
    {
        cout<<"LinkedList is Empty..\n";
        return;
    }
    else if(head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete tail->next;

        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((head == NULL) && (tail == NULL))
    {
        //cout<<"Linked list is Empty..\n";
        return;
    }
    else if(head == tail)
    {
        cout<<"Linked listcontains 1 node..\n";
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        free(tail->next);

    }
        tail->next = head;
        head->prev = tail;

        iCount--;
}

template <class T>
void DoublyCL<T> ::  DeleteAtPos(int ipos)
{
    int i = 0;

    if((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid Position..\n";
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDC<T> *target = NULL;
        struct nodeDC<T> *temp = NULL;
        temp = head;

        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        free(target);

    iCount--;
    }
}

template <class T>
void DoublyCL<T> :: Display()
{
    cout<<"\n";
    do{
        cout<<"|"<<head->data<<"|<=>";
        head = head->next;
    }while(head != tail->next);
    cout<<"NULL\n";
}

template <class T>
int DoublyCL<T> :: Count()
{   
    cout<<"Number of Nodes are :  ";
    return iCount;
    cout<<"\n";
}


int main()
{

    return 0;
}