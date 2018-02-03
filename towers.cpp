/*
   COPYRIGHT (C) 2017 Huy Nguyen (2653922 ) All rights reserved.
   CS assignment
   Author.  Huy Nguyen
            hmn8@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program ... Towers of Hanoi Recursion
*/

#include <iostream>
#include "towers.h"
#include "mystack.h"
#include <cstdlib>

using namespace std;
//YOUR CODE
//......

Towers::~Towers()
{
    delete peg1;
    delete peg2;
    delete peg3;
}

Towers::Towers(int diskSize)
{

    MyStack<int> temp(diskSize);
    MyStack<int> temp2(diskSize);
    MyStack<int> temp3(diskSize);

    peg1 = &temp;
    peg2 = &temp2;
    peg3 = &temp3;

    setDisks();
    move(diskSize,peg1,peg2,peg3);
    //plotPegs();
}

Towers::Towers(const Towers& obj)
{
    numDisk = obj.numDisk;
}

Towers& Towers::operator=(const Towers& obj)
{
    this->numDisk = obj.numDisk;
    return *this;
}

void Towers::setDisks()
{

    for(int i = 4; !peg1->isFull(); --i)
    {
        std::cout << "Setting Disk [ " << (5-i) << " ]\n";
        peg1->push(i);
    }

    while(!peg2->isEmpty())
    {
        std::cout << "NOT EMPTY POPPING\n";
        peg2->pop();
    }

    while(!peg3->isEmpty())
    {
        std::cout << "NOT EMPTY POPPING\n";
        peg2->pop();
    }

    plotPegs();

}

void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d)
{
    //plotPegs();
    //std::cout << "\n N IS " << n << "\n";

    if(n == 0)
    {   //std::cout << "\nMove 0 Called N IS " << n << "\n";
        moveOne(s,t); plotPegs();
        if(t->isFull())
        {
            std::cout << "\n\n ***GAME OVER*** \n\n";
            exit(0);
        }
    }

    if(n >= 1)
    {

        //std::cout << "\nRecursion 1 Called N IS " << n << "\n";
        move(n-1, s, d, t);
        //plotPegs();
        //std::cout << "\nMove 1 Called N IS " << n << "\n";
        moveOne(s,t);
        //std::cout << "\nMove 1 Called N IS " << n << "\n";
        plotPegs();
        //std::cout << "\nRecursion 2 Called N IS " << n << "\n";
        move(n-1,d, t, s);
    }


}

void Towers::moveOne(MyStack<int>* s, MyStack<int>* d)
{
    int catchVar;

    catchVar = s->pop();
    d->push(catchVar);
}



//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

  	//std::cout << "Size Is " << peg1->size() << "\n";
	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);


	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	cout << "_________________________________________\n";

}
