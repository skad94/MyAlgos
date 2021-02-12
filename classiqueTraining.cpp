
// classiqueTraining.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"test.h"
#include "..\simulation\Simulation.h"
#include "..\algos\linkedList.h"
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>

int
divide(int dividend, int divisor)
{
    /*Given two integers dividend and divisor, divide two integers without using multiplication, division,
 and mod operator. Return the quotient after dividing dividend by divisor.
 The integer division should truncate toward zero, which means losing its fractional part.
 For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.*/

    int remain = dividend;
    int quotient = 0;
    while (remain >= divisor)
    {
        remain -= divisor;
        quotient++;
    }
    return quotient;
    //while (remain >= divisor || remain < 0 )
    //{
    //	remain = dividend - quotient * divisor;
    //	if remain >= divisor
    //		quotient /= 2;
    //	if remain < 0

    //}
}
bool
isAlreadyThere(const std::vector<int>& data, int val)
{
    auto iterNum = data.begin();
    while (iterNum != data.end())
    {
        if (*iterNum == val)
            return true;
        ++iterNum;
    }
    return false;
}
std::vector<std::string>
cycleDetector(const std::vector<int>& data)
{
    // l'algorithme doit retourner l'ensemble des cycles d'un ensemble sous forme de (cycle 1, cycle 2, ..., cycle n)
    //sachant qu'en input nous avons toutes les permutations et que l'ensemble est [1,2,3,...n] 

    // solution1 with no extra space
    std::vector<std::string> res;
    int idxPermut = 0;
    std::set<std::string> memo;
    while (idxPermut < data.size())
    {
        std::string cycle;
        int idxCycle = idxPermut+1;
        while (memo.find(std::to_string(idxCycle-1)) == memo.end())
        {
            memo.insert(std::to_string(idxCycle-1));
            cycle.push_back(idxCycle);
            idxCycle = data[idxCycle-1];
        }
        if (cycle.size() != 0)
            res.push_back(cycle);//<< "\n";
        idxPermut++;
    }
    return res;
}


 // Definition for singly-linked list.
  struct ListNode
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        // Leetcode 21
        //Merge two sorted linked lists and return it as a sorted list. 
        //The list should be made by splicing together the nodes of the first two lists
        // (ham-)merger two list that are already sorted
        if (l1 == 0)
            return l2;
        if (l2 == 0)
            return l1;
        bool isL1SmallerThanL2 = true;
        int start = 0;
        ListNode* tmp;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        if (l1->val > l2->val)
            isL1SmallerThanL2 = false;
        if (isL1SmallerThanL2)
        {
            tmp = tmp1;
            tmp1 = tmp->next;
        }
        else
        {
            tmp = tmp2;
            tmp2 = tmp2->next;
        }
        ListNode* res = tmp;
        /*if
            si la taille est 1 on ne peux plus
        */
        while (tmp1 != 0 && tmp2!=0)
        {
            if (tmp1->val > tmp2->val)
            {
                tmp->next = tmp2;
                tmp = tmp->next;
                tmp2 = tmp2->next;
            }
            else
            {
                tmp->next = tmp1;
                tmp = tmp->next;
                tmp1 = tmp1->next;
            }
        }
        if (!tmp1)
        {
            tmp->next = tmp2;
        }
        else if (!tmp2)
            tmp->next = tmp1;
        else
        {
            std::cout << " returné 0 " << std::endl;
            delete(tmp);
            return 0;
        }
        return res;
    }
//std::vector<std::vector<int>> allSubset(const std::vector<int>& data)
//{
//    //from a set of non duplicate integer
//    // output all the subset
//    std::vector<std::vector<int>> res;
//    if (data.size() == 1)
//    {
//        std::vector<int> empty;
//    }
//}
int main()
{/*
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };*/
    ListNode r1(1);
    ListNode r2(4);
    ListNode r3(6);
    ListNode r4(8);
    r1.next = &r2;
    r2.next = &r3;
    r3.next = &r4;

    ListNode r5(2);
    ListNode r6(3);
    ListNode r7(5);
    ListNode r8(92);
    r5.next = &r6;
    r6.next = &r7;
    r7.next = &r8;

    ListNode* data;

    data = mergeTwoLists(&r1, &r5);
    int u = 94;

    /* std::vector<int> data = { 2,1,9,8,5,4,6,7,3 };
    auto res = cycleDetector(data);*/

 /*   std::vector<int> data = { -100,-101,94,13,6,88};

    std::vector<std::vector<int>> rt = threeSum(data);
    data.push_back(10);*/
    //LoggerFile* logo = new LoggerFile("doedoe.txt");
    //logo->logFile("tu ecris...arretez Despo!");
    //LoggerScreen* logo02 = new LoggerScreen();
    //logo02->logScreen("soso maness sososo maness!");
    //std::vector<int> nums = { 1,1,1,1,1 };// , 2, 2, 5, 6, 9, 9, 9, 94};
    //int idxNextSpot;
    //int lastValueSaved = nums[0];
    //idxNextSpot = 0;
    //if (nums.size() >= 2)
    //{
    //    idxNextSpot = 1;
    //}
    //int currValue = lastValueSaved;
    //for (int i = 0; i < nums.size(); ++i)
    //{
    //    currValue = nums[i];
    //    if (currValue != lastValueSaved)
    //    {
    //            lastValueSaved = currValue;
    //            nums[idxNextSpot] = currValue;
    //            idxNextSpot++;
    //    }
    //}
    //idxNextSpot *= 1;
    //
    
    /*
    srand(time(NULL));
    BS_Process a(0.1,0.1,100.0);
    std::vector<double> z1 = a.BS_Simul_milstein(50);
    std::vector<double> z12 = a.BS_Simul_milstein(50);
    std::vector<double> b = a.Simul_Brownian(50);
    std::vector<double> z2 = a.BS_Simul_milstein(50,b);
    std::vector<double> z22 = a.BS_Simul_milstein(19,b);
    const std::string nomFichier("C:\\Users\\Skad\\dev\\output\\test.txt");
    std::ofstream monFlux(nomFichier.c_str());
    */



    //leetcode swap pairs
    //Llist* rr = new Llist(1.);
    //rr->addNode(2.);
    //rr->addNode(3.);
    //rr->addNode(4.);
    //rr->addNode(5.);
    //rr->addNode(6.);
    //rr->addNode(7.);
    //rr->display();
    //auto tt = rr->swapPairs(rr);
    //tt->display();
 	//std::cin.get();
	return 94;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
