#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <iostream>
#include "AlgorithmData.h"


using namespace std;
class SelectionSort : public AlgorithmData
{


public:
    SelectionSort(DoubleLinkedList<double> *list)
    {
        localCopy = list->copy();
        setStartTime();
        sort();

        setEndTime();


    }

    ~SelectionSort()
    {

    }

    void printSortedList()
    {
        std::cout << "==========SelectionSort==========" << endl;
        AlgorithmData::printInfo();
    }
private:
    void sort()
    {

        int size = localCopy->getSize();
        double tmp;
        int minIndex;


        for (int i = 0; i < size - 1; i++)
        {
            minIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                double curr = localCopy->returnData(j);
                if (curr < localCopy->returnData(minIndex))
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                localCopy->swap(i, minIndex);
            }
        }
    }
};
#endif