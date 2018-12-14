#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <iostream>
#include "AlgorithmData.h"


using namespace std;
class InsertionSort : public AlgorithmData
{


public:
    InsertionSort(DoubleLinkedList<double> *list)
    {
        localCopy = list->copy();
        setStartTime();
        sort();

        setEndTime();


    }

    ~InsertionSort()
    {

    }

    void printSortedList()
    {
        std::cout << "==========InsertionSort==========" << endl;
        AlgorithmData::printInfo();
    }
private:
    void sort()
    {

        int size = localCopy->getSize();


        for (int j = 1; j < size; ++j)
        {
            double temp = localCopy->returnData(j);

            int k = j;

            while(k > 0 && (localCopy->returnData(k - 1) >= temp) )
            {
                --k;
            }

            localCopy->deletePos(j);
            localCopy->insertPos(temp,k);
        }
    }
};
#endif