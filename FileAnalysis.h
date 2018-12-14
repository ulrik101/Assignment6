#ifndef FILEANALYSIS_H
#define FILEANALYSIS_H
#include <iostream>
#include<fstream>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"


#include "DoubleLinkedList.h"
#include "QuickSort.h"
#include "CombSort.h"
using namespace std;

class FileAnalysis
{
    private:

        std::string fileName = "";
        unsigned int linesToAnalyze = 1;
        DoubleLinkedList<double> *unsortedInfo = new DoubleLinkedList<double>;

        void createLinkedList(std::string newFileName)
        {
            //set line count
            //start tracking line count
            //

            int counter = 0;
            ifstream file(fileName);
            if(file.is_open())
            {
                while(!file.eof() && counter <= linesToAnalyze)
                {
                    counter++;
                    std::string local_string;
                    file >> local_string;
                    //cout << local_string << endl;

                    if(counter == 1)
                    {
                        linesToAnalyze = std::stoi(local_string);
                    }
                    else
                    {
                        if (counter == linesToAnalyze / 4)
                        {
                            std::cout << "25%...";
                        }if (counter == 2 * (linesToAnalyze / 4))
                        {
                            std::cout << "50%...";
                        }if (counter == 3 * (linesToAnalyze / 4))
                        {
                            std::cout << "75%...";
                        }
                        



                        double num = ::atof(local_string.c_str());
                        unsortedInfo->insertBack(num);
                    }
                }
            }
            std:cout<< "Size: " << unsortedInfo->getSize() << endl;
        }


        void analyzeAndPrint()
        {
            BubbleSort bubble(unsortedInfo);
            bubble.printSortedList();


            SelectionSort selectionSort(unsortedInfo);
            selectionSort.printSortedList();

            InsertionSort insertionSort(unsortedInfo);
            insertionSort.printSortedList();

            CombSort combSort(unsortedInfo);
            combSort.printSortedList();

            QuickSort quickSort(unsortedInfo);
            quickSort.printSortedList();

        }


    public:
        FileAnalysis(std::string newFileName = "")
        {
            fileName = newFileName;
            createLinkedList(fileName);
            analyzeAndPrint();
        std:cout << "+++++++++++++++++++++++++++++++++++" << endl;
            //unsortedInfo->printList();
        }


        ~FileAnalysis()
        {

            unsortedInfo = NULL;
            delete unsortedInfo;
        }

};
#endif
