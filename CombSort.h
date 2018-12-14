#ifndef COMBSORT_H
#define COMBSORT_H
#include <iostream>
#include "AlgorithmData.h"


using namespace std;
class CombSort : public AlgorithmData
{


public:
    CombSort(DoubleLinkedList<double> *list)
    {
        localCopy = list->copy();
        setStartTime();
        sort();

        setEndTime();


    }

    ~CombSort()
    {

    }

    void printSortedList()
    {
        std::cout << "==========Comb==========" << endl;
        AlgorithmData::printInfo();
    }
private:
    void sort()
    {
        combSort(localCopy->getSize());
    }
    
    void combSort(int newGap)
    {
        int combGap = newGap;
        bool swapped = true;
        while(combGap != 1 || swapped == true)
        {
            combGap = (combGap * 10) / 13;
            if(combGap < 1)
            {
                combGap = 1;
            }

            swapped = false;

            for(int i=0; i<newGap - combGap;i++)
            {
                if(localCopy->returnData(i) > localCopy->returnData(i + combGap))
                {
                    localCopy->swap(i, i + combGap);
                    swapped = true;
                }
            }
        }
    }
};
#endif