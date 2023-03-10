//Assignment 2
/*
Group Member List
Member Name 1: Mohamad Azri Hadif bin Mohammad Rizal
Matric Number: A21EC0054
Section: 02

Group Member List
Member Name 2: Nurunnajwa Binti Zulkifli
Matric Number: A21EC0121
Section: 02

Group Member List
Member Name 3:Nur Shuhada Safiah binti Ayob
Matric Number: A21EC0114
Section: 02


Group Member List
Member Name 4: Umar Haziq bin Muhamad Norhisham
Matric Number: A21EC0235
Section: 02
*/


#include<iostream>
#include <iomanip>
#include <string>
using namespace std;


class ItemNode
{
    public:
    string name;
    float price;
    ItemNode* aft;
    ItemNode* bef;

    ItemNode( string n= NULL, float p=0.0)
    {
        name=n;
        price =p;
        aft=NULL;
        bef=NULL;
    }
};

class List
{
    private:
    ItemNode* head; //head of the list
    ItemNode* tail; // tail of the list

    public:
    void task1(ItemNode*);
    void task2(ItemNode*);
    void task3();
    void task4(ItemNode*, int);
    void task5(int);
    void task6();

};


//Task 1 : insert a new item node into an empty list.
void List :: task1(ItemNode* barang)
{
    //pass the whole node 
    //get value of node
    head =barang;
    tail=barang;

};


//Task 2: insert a new item node in front of the list.
void List :: task2(ItemNode* barang)
{

    barang->aft=head; //prev equal to
    head -> bef = barang;
    head = head -> bef;

};

//Task 3: print all data in the list in backward order
void List :: task3()
{
    cout<<"Print backward: \n";
    ItemNode *currNode;
    for(currNode =tail; currNode != NULL; currNode = currNode-> bef)
    {
        cout<<"["<<currNode -> name <<" "<<currNode->price <<"] ";

    }

cout<<"\n\n"<<endl;
};

//Task 4: insert a new item node at the middle of the list
void List :: task4(ItemNode *barang, int posisi)
{
    if(posisi ==1)
            task2(barang);
    else
    {
        posisi--;
        ItemNode *currNode =head;
        while(currNode != NULL && posisi-- )
        {
            if(posisi==0)
            {
                if(currNode ->aft == NULL)
                {
                    currNode->aft=barang;
                    barang->bef= currNode;
                    tail = tail->aft;
                }
            
            else
            {
                ItemNode *next = currNode->aft;
                barang->bef = currNode;
                barang->aft = next;

                next->bef=barang;
                currNode->aft=barang;
            }
            return;
        }
        currNode=currNode->aft;
    }
}

};



//Task 5: delete the item node at the middle of the list

void List :: task5(int posisi)
{
    if (posisi ==1)
    {
        ItemNode *currNode = head; 
        head = head->aft;
        head->bef=NULL;
        delete currNode;
    }

    else

    {
        ItemNode *currNode=head;
        while(currNode && posisi--)

        {
            if(posisi==0)
            {
                if(currNode -> aft ==NULL)
                {
                    ItemNode *currNode = tail;
                    tail = tail -> bef;
                    tail -> aft =NULL;
                    delete currNode;
                }

                else
                {
                    ItemNode *next= currNode->aft;
                    ItemNode *prev=currNode->bef;

                    prev-> aft = next;
                    next -> bef = prev;

                    currNode->aft=NULL;
                    currNode->bef=NULL;
                    delete currNode;

                }

                return;

            }

            currNode =currNode -> aft;
        }
    }


};


//Task 6: delete the last node in the list

void List::task6(){

    ItemNode *currNode = tail;
    tail=tail->bef;
    tail->aft=NULL;
    delete currNode;


};


int main()
{

    List ItemList;
    ItemNode *n1 = new ItemNode("Book", 9.59);
    ItemNode *n2 = new ItemNode("Ruler", 3.45);
    ItemNode *n3 = new ItemNode("Pen", 5.69);
    ItemNode *n4 = new ItemNode("Eraser", 2.25);

  cout << fixed << setprecision(2) << left;
    ItemList.task1(n1);
    ItemList.task2(n2);
    ItemList.task3();
    ItemList.task4(n3, 2);
    ItemList.task4(n4, 2);
    ItemList.task3();
    ItemList.task5(3);
    ItemList.task3();
    ItemList.task6();
    ItemList.task3();
  
    return 0;

}
