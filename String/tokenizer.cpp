#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    char a[]="Ami vat khai.Ami bari zai,tumi'o ki vat khaw? ami- ze vat khai na xD";
    char *ptr;
    ptr=strtok(a," -,?.'");
    while(ptr!=NULL)
    {
        cout<<ptr<<endl;
        ptr=strtok(NULL," -,?.'");
    }
}