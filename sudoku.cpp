#include<bits/stdc++.h>
using namespace std;



void print(vector<vector<int>>&V)
{
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[0].size();j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
}



bool valid(vector<vector<int>>&V,int row,int col,int val)
{

    //check in row
  for(int i=0;i<V.size();i++)
  {
      if(V[row][i]==val)return false;
  }
  //check in col
  for(int i=0;i<V[0].size();i++)
  {
      if(V[i][col]==val)return false;
  }
  row=row-row%3;
  col=col-col%3;
  for(int i=row;i<row+3;i++)
  {
      for(int j=col;j<col+3;j++)
      {
          if(V[i][j]==val)return false;
      }
  }
  return true;
}
bool sudoku(vector<vector<int>>&V,int row,int col)
{
   
    if(row>8) return true;
    if(V[row][col]!=0)
    {
        col++;
        if(col==9)
        {
            row++;
            col=0;
        }
        return sudoku(V,row,col);
    }
    for(int i=1;i<=9;i++)
    {
        if(valid(V,row,col,i))
        {
            V[row][col]=i;
            col++;
            if(col==9)
            {
                row++;
                col=0;
            }
            bool ret=sudoku(V,row,col);
            if(ret)return true;
           
            col--;
        
            if(col==-1)
            {
                row--;
                col=8;
            }
            V[row][col]=0;
        }
    }
    return false;
    
}

int main()
{
    vector<vector<int>>V{  {3, 0, 6, 5, 0, 8, 4, 0, 0},
                           {5, 2, 0, 0, 0, 0, 0, 0, 0},
                           {0, 8, 7, 0, 0, 0, 0, 3, 1},
                           {0, 0, 3, 0, 1, 0, 0, 8, 0},
                           {9, 0, 0, 8, 6, 3, 0, 0, 5},
                           {0, 5, 0, 0, 9, 0, 6, 0, 0},
                           {1, 3, 0, 0, 0, 0, 2, 5, 0},
                           {0, 0, 0, 0, 0, 0, 0, 7, 4},
                           {0, 0, 5, 2, 0, 6, 3, 0, 0}};
     
     if(sudoku(V,0,0))
       print(V);
}