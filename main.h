#ifndef MAIN
#define MAIN

#define CODE_LEN_256 256
#define CODE_LEN_128 128
#define CODE_LEN_64 64
#define Success  0
#define Failed   1

typedef struct PersonInfo
{
    long  PersonID;
    char PersonName[CODE_LEN];
}stPerson;

class CountNum
{
public:
    CountNum() {}
    ~CountNum() {}
    void WriteNum(long Values);

    int  GetNum();

    void WriteName(char *Name);

    char *GetName();

    void PrintAllInfo();

    void PrintSignleInfo(char *Name);

    void WriteToList();

    void ModifyInfoByName(char *Name);

    void DeleteInfoByName(char *Name);

    void ADD();

    void DELETE();

    void MODIFY();

    void SEARCH();

private:
    stPerson LinkInfo;
};

#endif // MAIN

