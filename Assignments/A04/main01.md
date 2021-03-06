```cpp
/*****************************************************************************
*                    
*  Author:           Samuel Campbell
*  Email:            Sccapmpbell1019@my.msutexas.edu
*  Label:            A04
*  Title:            circular array que
*  Course:           CMPS 2143
*  Semester:         Spring 2021
* 
*  Description:
*        This program creates a circular array from a que. 
* 
*  Files:            main.cpp: driver program
*****************************************************************************/


#include <iostream>

using namespace std;


/**
 * CircularArrayQue
 * 
 * Description:
 *      Contains the constructor and commands to set size and fill array
 * 
 * Public Methods:
 *      -           CircularArrayQue()
 *      -           CircularArrayQue(int size)
 *      - void      Push(int item)
 *      - int       Pop()
 * Private Methods:
 *      - void      init(int size)
 *      - bool      full()
 
 *      - 
 * Usage: 
 * 
 *      -within main enter in ythe values to fill the array with the push command
 *      (C1.push(#))
 *      
 */

class CircularArrayQue
{
private:
    int *Container;
    int Front;                          //Needed for to create a circular linked array
    int Rear;                           //Needed ... linked array
    int QueSize;                        // items in the queue
    int CurrentSize;    
    void init(int size = 0)
    {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full()
    {
        return CurrentSize == QueSize;   //returns a true or false
    }

public:
    CircularArrayQue()
    {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size)
    {
        Container = new int[size];
        init(size);
    }

    void Push(int item)
    {
        if (!Full())
        {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else
        {
            cout << "FULL!!!!" << endl; 
        }
    }

    int Pop()
    {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
     * Public/Private/Protected : ostream &operator<<
     * 
     * Description:
     *      Fills in the array?
     * 
     * Params:
     *      - Char      ostream &os
     *      - const     CircularArrayQue
     *      - &         other
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
ostream &operator<<(ostream &os, const CircularArrayQue &other)
{

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize)
    {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main()
{
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
```
