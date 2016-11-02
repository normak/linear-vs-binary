//
//  main.cpp
//  Search Discussion
//
//  Created by Kamron on 09/03/2015.
//  Copyright (c) 2015 Kamron. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;


void linearSearch(int array[], int numOfElements, int item)
{
    for (int i = 0; i < numOfElements; i++) //cycle through array
    {
        if(array[i]==item) //check if item is the one we need
        {
            cout << "Yes" << endl;
            break;
        }
        if (i==numOfElements-1) //if we reach the end of the array without finding it, it does not exist.
        {
            cout << "No" << endl;
        }
    }
}

void binarySearch(int array[], int left, int right, int item)
{
    int position = (left + right)/2; //find the center of the array
    while((array[position] != item) && left <= right)
    {
        if (array[position] > item) //if it is larger than the number we need, change the right bound
        {
            right = position - 1;
        }
        else //if it is smaller than the number we need, change the left bound
        {
            left = position + 1;
        }
        position = (left + right) / 2; //go to new center
    }
    if (left <= right) //if left is the same or greater than right bound, it was found.
    {
        cout << "Yes" << endl;
    }
    else // if left bound is bigger than right bound, it was not found.
    {
        cout << "No" << endl;
    }
}

int main(int argc, const char * argv[])
{
    int numOfElements, numOfSearches; // n, s
    cin >> numOfElements >> numOfSearches;
    int *listOfElements = new int[numOfElements];
    for (int i = 0; i < numOfElements; i++) //put elements into array
    {
        cin >> listOfElements[i];
    }
    int *listOfSearches = new int[numOfSearches];
    for (int i = 0; i < numOfSearches; i++) //put searches into an array
    {
        cin >> listOfSearches[i];
    }
    sort(listOfElements, listOfElements+numOfElements); //sort for binary search
    cout << "Linear Search:" << endl;
    
    //clock_t start, finish;
    //double elapsedtime;
    //start = clock();
    
    
    for (int i = 0; i < numOfSearches; i++) //do linear search for all search elements
    {
        linearSearch(listOfElements, numOfElements, listOfSearches[i]);
    }
    
    //finish = clock();
    //elapsedtime = (double)(finish - start)/CLOCKS_PER_SEC;
    //cout << "Elapsed time: " << elapsedtime << endl << endl;
    
    
    cout << "Binary Search:" << endl;
    
    //start = clock();
    
    for (int i = 0; i < numOfSearches; i++) //do binary search for all search elements
    {
        binarySearch(listOfElements, 0, numOfElements-1, listOfSearches[i]);
    }
    
    //finish = clock();
    //elapsedtime = (double)(finish - start)/CLOCKS_PER_SEC;
    //cout << "Elapsed time: " << elapsedtime << endl;
    
    return 0;
}
