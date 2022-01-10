#include <iostream>

using namespace std;

struct clue
{
    char value;
    clue *next;
    clue(){};
    clue(char val){value = val;}
};

void clear_clues(clue *lst)
{

}

int check_exists(clue *lst, char look_for)
{

    return -1;
}

clue* list_init(char start, char end, int n)
{
    int i = -1;
    char val,link;
    clue *lst = new clue[n];
    while (++i < n)
    {
        cin>>val;
        cin>>link;
        lst[i] = new clue(val);

    }
    return lst;
}

int main()
{
    int t;
    cin>>t;
    int i = 0,n;
    char start,end;
    clue *list;
    while (i < t)
    {
        cin>>n;
        list = list_init(start,end,n);



        clear_clues(list);
        i++;
    }
    
    return 0;
}