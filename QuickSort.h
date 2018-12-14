#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include "AlgorithmData.h"


using namespace std;
class QuickSort : public AlgorithmData
{


public:
    QuickSort(DoubleLinkedList<double> *list)
    {
        localCopy = list->copy();
        setStartTime();
        sort();

        setEndTime();


    }

    ~QuickSort()
    {

    }

    void printSortedList()
    {
        std::cout << "==========QuickSort==========" << endl;
        AlgorithmData::printInfo();
        //localCopy->printList();
    }
private:

    void sort()
    {
        /*
        DoubleLinkedList<double> tempList = *localCopy;

        //sortRec(tempList);
        *localCopy = tempList;*/

        sortInPlace(localCopy, 0, localCopy->getSize()-1);

    }

    DoubleLinkedList<double> sortRec(DoubleLinkedList<double> S)
    {
    std:cout << "Started New: "<< S.getSize() << endl;

        S.printList();

        if (S.getSize() <= 1)
        {
            std::cout << "     size <= 1" << endl;

            return S;
        }
        double p = S.getBack();

        DoubleLinkedList<double> L;
        DoubleLinkedList<double> E;
        DoubleLinkedList<double> G;

        while (!S.isEmpty())
        {
            if (S.getBack() < p)
            {
                L.insertBack(S.removeBack());
            }
            else if (S.getBack() == p)
            {
                E.insertBack(S.removeBack());
            }
            else
            {
                G.insertBack(S.removeBack());
            }
        }
        sortRec(L);
        sortRec(G);
        while (!L.isEmpty())
        {
            S.insertBack(L.removeFront());
        }
        while (!E.isEmpty())
        {
            S.insertBack(E.removeFront());
        }
        while (!G.isEmpty())
        {
            S.insertBack(G.removeFront());
        }
        std::cout << "shiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiit" << endl;

        return S;
        

    }


    void sortInPlace(DoubleLinkedList<double> *S, int a, int b)
    {
        if(a>=b)
        {
            return;
        }

        double p = S->returnData(b);
        double l = a;
        double r = b - 1;

        while(l<=r)
        {
            while(l<=r && S->returnData(l)<=p)
            {
                l = l + 1;
            }
            while (r >= l && S->returnData(r) >= p)
            {
                r = r - 1;
            }
            if(l<r)
            {
                S->swap(l, r);
            }
        }
        S->swap(l, b);
        sortInPlace(S, a, l - 1);
        sortInPlace(S, l + 1, b);
    }
};
#endif