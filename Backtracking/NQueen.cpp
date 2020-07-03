#include <bits/stdc++.h>
using namespace std;
int size=5;
char line[14];
bool placeable[14][14]; // Description lies, is not size 15
int cd=0;

void SearchByRow(int rowNum, int columnTaken, int upDiagonalChallenged, int downDiagonalChallenged)
{
    if (rowNum == size)
    {
        ++cd;
        return;
    }
    
    int allBasePossible = (1 << size) - 1; // Will be all 1 for the rows
    
    int possiblePositions = allBasePossible & ~(columnTaken | upDiagonalChallenged | downDiagonalChallenged);
    for (int c = 0; c < size; ++c)
    {
        if (((possiblePositions >> c) & 1))
        {
            cout<<((possiblePositions >> c) & 1)<<endl;
            SearchByRow(rowNum + 1, columnTaken | (1 << c), 
                (upDiagonalChallenged | (1 << c)) >> 1, // Add current, then shift down by 1
                (downDiagonalChallenged | (1 << c)) << 1); // Add current, then shift up by 1
        }
    }
}
int main(void)
{
    SearchByRow(0,0,0,0);
    cout<<cd<<endl;
}