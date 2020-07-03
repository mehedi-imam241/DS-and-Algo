#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int coins[]={1,2};
    int size=2;
    int SumToMake=5;
    int way[SumToMake+1];
    memset(way,0,sizeof(way));
    way[0]=1;
    for(int i=0;i<size;i++)  //iterate through all coins
    {
        for(int j=coins[i];j<=SumToMake;j++)  //solve all the ways to make sums
        {
            way[j]+=way[j-coins[i]]; //কয়েন স্ট্যাটিক না হয়, মানে ইনপুটে বারবার কয়েনের মান চেঞ্জ হইতেই থাকে
                                    //তখন কয়েনের মধ্য দিয়ে ইটারেশনটা লাগবে না । শুধু কয়েনের ওই মানটা থেকে সাম পর্যন্ত 
                                    //ইটারেশনটায় ওয়ে আপডেট করে দিলেই হবে। লক্ষনীয় কয়েনের সর্টিং এর কোন প্রয়োজন হচ্ছে না। 
                                    //শুধু আপডেটিংটা ঠিকঠাক করতে হবে ।
        }
    }
    cout<<way[SumToMake]<<endl;
}