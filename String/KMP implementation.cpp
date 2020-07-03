#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char pattern[],int patternlen,int lps[])
{
    int len=0;
    lps[0]=0;
    int i=1;
    while (i<patternlen)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
        
    }
    
}

void KMPSearch(char pattern[],char text[])
{
    int patternlen=strlen(pattern);
    int textlen=strlen(text);
    int lps[patternlen];
    computeLPSArray(pattern,patternlen,lps);
    int i=0;
    int j=0;
    while (i<textlen)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==patternlen)
        {
            cout<<"Found pattern at index"<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<textlen && pattern[j]!=text[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
            
        }
    }
    
}

int main(void)
{
    char text[]="ABCABAABCABAC";
    char pattern[]="CAB";
    KMPSearch(pattern,text);
    return 0;
}
