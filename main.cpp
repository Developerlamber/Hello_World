#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <iterator>
#include "main.h"

using namespace std;

vector<CountNum> oVecNum;

void CountNum::DeleteInfoByName(char *Name)
{
    vector<CountNum>::iterator oVec;
    oVec = oVecNum.begin();
    for ( ; oVec != oVecNum.end(); oVec++)
    {
       if(0 == strncmp((const char*)Name, (const char*)oVec->GetName(), CODE_LEN_64))
       {
           oVecNum.erase(oVec);
           cout << "Delete success" << endl;
           return;
       }
    }
    cout << "Name is not exist" << endl;
}

void CountNum::ModifyInfoByName(char *Name)
{
    char array[CODE_LEN_64] = {0};
    vector<CountNum>::iterator oVec;
    oVec = oVecNum.begin();
    for ( ; oVec != oVecNum.end(); oVec++)
    {
       if(0 == strncmp((const char*)Name, (const char*)oVec->GetName(), CODE_LEN_64))
       {
           cout << "Please Modfiy Name:";
           cin >> array;
           oVec->WriteName(array);
           cout << "Modify Success" << endl;
           return;
       }
    }

    cout << "Name is not exist" << endl;

}

void CountNum::PrintSignleInfo(char *Name)
{
    vector<CountNum>::iterator oVec;
    oVec = oVecNum.begin();
    for ( ; oVec != oVecNum.end(); oVec++)
    {
       if(0 == strncmp((const char*)Name, (const char*)oVec->GetName(), CODE_LEN_64))
       {
           cout << oVec->GetName() << "---------" << oVec->GetNum() << endl;
       }
    }
}

void CountNum::PrintAllInfo()
{
    vector<CountNum>::iterator oVec;
    oVec = oVecNum.begin();
    for ( ; oVec != oVecNum.end(); oVec++)
    {
        cout << oVec->GetName() << "---------" << oVec->GetNum() << endl;
    }
}

void CountNum::WriteName(char *Name)
{
    if (NULL == Name)
    {
        cout << "Name is empty" << endl;
        return;
    }
    strncpy(this->LinkInfo.PersonName, Name, CODE_LEN_64);
    cout << "Write  Name  End" << endl;
}

void CountNum::WriteNum(long Values)
{
    this->LinkInfo.PersonID = Values;
    cout << "Write Num End" << endl;
}

char* CountNum::GetName()
{
   return this->LinkInfo.PersonName;
}

int CountNum::GetNum()
{
    return this->LinkInfo.PersonID;
}

void CountNum::ADD()
{
    CountNum ContactInfo;
    string Name;
    long   ID;
    char   Buf[CODE_LEN_64] = {0};
    cout << "ADD NAME:";
    cin >> Name;
    strncpy(Buf, Name.c_str(), CODE_LEN_64);
    ContactInfo.WriteName(Buf);
    cout << "ADD ID :";
    cin >> ID;
    ContactInfo.WriteNum(ID);
    oVecNum.push_back(ContactInfo);
    cout << "Add Success" <<endl;
}

void CountNum::DELETE()
{
    CountNum ContactInfo;
    cout << "Tell me What Name you want to Delete:";
    char array[CODE_LEN_64] = {0};
    cin >> array;
    ContactInfo.DeleteInfoByName(array);
}

void CountNum::MODIFY()
{
    CountNum ContactInfo;
    cout << "Tell me What Name you want to Modify:";
    char array[CODE_LEN_64] = {0};
    cin >> array;
    ContactInfo.ModifyInfoByName(array);
}

void CountNum::SEARCH()
{
    CountNum ContactInfo;
    cout << "Tell me What Name you want to Search:";
    char array[CODE_LEN_64] = {0};
    cin >> array;
    cout << "Search List:" << endl;
    ContactInfo.PrintSignleInfo(array);
    cout << "----------end-------------" << endl;
}

int main()
{
    string Commond;
    CountNum ContactInfo;
    cout << "                   *----------------------*" << endl;
    cout << "                   *Welcome Contact System*" << endl;
    cout << "                   *----------------------*" << endl;
    while (1)
    {
        cout << "Please enter your Commond:";
        cin >> Commond;
        if ("exit" == Commond)
        {
            cout << "System will exit, please use system again !" << endl;
            break;
        }
        else if ("Add" == Commond)
        {
            ContactInfo.ADD();
        }
        else if ("Delete" == Commond)
        {
            ContactInfo.DELETE();
        }
        else if ("Modify" == Commond)
        {
            ContactInfo.MODIFY();
        }
        else if ("Search" == Commond)
        {
            ContactInfo.SEARCH();
        }
        else if ("Print" == Commond)
        {
            ContactInfo.PrintAllInfo();
        }
    }
}


