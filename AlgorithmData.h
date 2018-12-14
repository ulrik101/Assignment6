#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include "time.h"

#include "DoubleLinkedList.h"
#pragma warning(disable : 4996)

using namespace std;
class AlgorithmData
{
protected:
    DoubleLinkedList<double> *localCopy = new DoubleLinkedList<double>;

    /*const void setStartTime() { time_t startTime = time(NULL); }
    const void setEndTime() { time_t endTime = time(NULL); }*/
    const void setStartTime()
    {
        time_t startTime = time(0);
        time1 = ctime(&startTime);
        finalTime = finalTime - startTime;
        //std::cout << "Start Time: \t" << time1 << endl;
    }
    const void setEndTime() {
        time_t endTime = time(0);
        time2 = asctime(localtime(&endTime));
        finalTime = finalTime + endTime;
    }

private:
    int finalTime = 0;
    std::string time1 = "";
    std::string time2 = "";


public:
    AlgorithmData()
    {
    }

    ~AlgorithmData()
    {
        localCopy = NULL;
        delete localCopy;
    }

    void printInfo()
    {
        std::cout << "Start Time: \t"<< time1;
        std::cout << "End Time: \t" << time2;
        std::cout << "Seconds: \t" << finalTime<<endl;
    }
};
#endif