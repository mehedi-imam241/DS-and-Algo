#include<bits/stdc++.h>
using namespace std;
  
int main() 
{ 
    // Take any two strings 
    char s1[] = "Fun with STL"; 
    char s2[] = "with"; 
    char* p; 
  
    // Find first occurrence of s2 in s1 
    p = strstr(s1, s2); 
    //cout<<p;
  
    // Prints the result 
    if (p) { 
        strcpy(p, "Strings"); 
        printf("%s", s1); 
    } else
        printf("String not found\n"); 
  
    return 0; 
}