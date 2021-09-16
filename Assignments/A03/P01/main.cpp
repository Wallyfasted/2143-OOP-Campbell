/*****************************************************************************
*                    
*  Author:           Samuel Campbell
*  Email:            Sccampbell1019@my.msutexas.edu
*  Label:            P01
*  Title:            MyVector Class
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        Makes a My vector class that has a double linked class, 
*        and has several functions to transverse and modify the list. 
* 
*  Usage:
*        how to use the program if necessary
* 
*  Files:            (list of all source files used in this program)
*****************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x){
    data =x;
    next =NULL;
    }
};

class MyVector
{
    private:
    Node* head;
    Node* tail;
    int size;

public:
    MyVector (){
     head =NULL;
     tail =NULL;
     size =0;
    }
    //constructor reads array and pushes into back of list
    MyVector(int* Arr, int size){
        head =NULL;
        tail =NULL;
        size =0;

        for (int i=0;i<size;i++){
            PushRear(Arr[i]); 
        }
    }
    MyVector(string filename){
        head =NULL;
        tail =NULL;
        size =0;
        
        ifstream fin;
        int x;
        fin.open(filename);
        while (!fin.eof()) {
            fin >> x;
            PushRear(x);
        }
    }
   void PushFront(int val){
       Node* Temp =new Node(val);
       if (head == NULL){
           head = Temp;
           tail = head;
           size++;
        } else {
            Temp -> next = head;
            head = Temp;
            size++;
       }


    }
    //Takes in MyVector and pushes to the front of the list
    void PushFront(MyVector V2){
        int x = V2.PopRear(); 
        while (x != -1){
            PushFront(x);
            x = V2.PopRear();
            cout<<x;
        }
    }
    void PushRear(int val){
        Node* Temp =new Node(val);
       if (head == NULL){
           head = Temp;
           tail = head;
           size++;
       }else{
           tail -> next = Temp;
           tail = Temp;

       }
    }
    //Takes in MyVector and pushhes to the back of the list
    void PushRear(MyVector V2){
        int x = V2.PopFront(); 
        while (x != -1){
            PushRear(x);
            x = V2.PopFront();
            //cout<<x;
        }


    }
    //takes in a index and puts at that location in list(use size for this then loop index amount of times then place node there)
    bool PushAt(int index, int val){

        Node* prev = head;            // get previous and next pointers
        Node* current = head;
        Node* Temp = head;

        if (index >= size){
            return false;
        }

        while (index > 0){
            prev = current;
            current = current -> next;
            index--;
        }

        Temp -> next = prev -> next;
        prev -> next = Temp;

        size ++;

        return true;
        
        
    }
    int PopFront(){
        if(head == NULL){
          //cout<<"empty\n";
            return -1;
        }else{
            int value = head->data;
           Node* Temp = head;
           head = head -> next;
           delete Temp;
           return value;
        }
    }
    int PopRear(){
         if(head == NULL){
          //cout<<"empty\n";
            return -1;
        }else{
            int value = tail->data;
           Node* Temp = tail;
           tail = tail -> next;
           delete Temp;
           return value;
    }}//takes in a index and pops at that location in list(use size for this then loop index amount of times then place node there)
    int PopAt(int index){
        return -1;
    }
    //trys to see if the value is in list if not return -1
    int Find(int val){
        return -1;
    }
    void Print(){
        Node* Temp = head;
        while (Temp != NULL){
            cout<< Temp -> data << "->";
            Temp = Temp -> next;
        }
    }

    ~MyVector(){
        
    }

};

int main()
{   
    //MyVector test("in1.dat");
    MyVector test;
  //  MyVector test2;
  //  test2.PushFront(12);
   // test2.PushFront(13);
   // test2.PushFront(14);
   
    test.PushFront(0);
    test.PushFront(1);
    test.PushRear(10);
    test.PushRear(20);
     test.PushAt(2,2);
   // test.PushFront(test2);
    test.Print();

    return 0;
}