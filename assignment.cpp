#include<bits/stdc++.h>   
using namespace std; 
float corrCoeff(int X[], int Y[], int N) 
{ 
    int sumX = 0, sumY = 0, sumXY = 0, squareSumX = 0, squareSumY = 0; 
    float corrcoe;
    for (int i = 0; i < N; i++) 
    { 
        sumX = sumX + X[i]; 
        sumY = sumY + Y[i]; 
        sumXY = sumXY + X[i] * Y[i]; 
        squareSumX = squareSumX + X[i] * X[i]; 
        squareSumY = squareSumY + Y[i] * Y[i]; 
    } 
    corrcoe = (float)(N * sumXY - sumX * sumY) / sqrt((N * squareSumX - sumX * sumX) * (N * squareSumY - sumY * sumY)); 
    return corrcoe; 
} 

int main() 
{   
    int X[] = {43, 21, 25, 42, 57, 59}; 
    int Y[] = {99, 65, 79, 75, 87, 81}; 
    int N = sizeof(X)/sizeof(X[0]); 
    cout<<corrCoeff(X, Y, N); 
    return 0; 
} 
