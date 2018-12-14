#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <iostream>
#include "AlgorithmData.h"


using namespace std;
class BubbleSort : public AlgorithmData
{

        
    public:
        BubbleSort(DoubleLinkedList<double> *list)
        {
            localCopy = list->copy();
            setStartTime();
            sort();

            setEndTime();
            

        }

        ~BubbleSort()
        {

        }

        void printSortedList()
        {
            std::cout << "==========BubbleSort==========" << endl;
            AlgorithmData::printInfo();
        }
    private:
        void sort()
        {

            int size = localCopy->getSize();
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                {
                    if (localCopy->returnData(j) > localCopy->returnData(j + 1))
                    {
                        localCopy->swap(j, j + 1);
                    }
                }
            }
        }
};
#endif