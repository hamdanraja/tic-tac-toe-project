#include<iostream>
#include<conio.h>
using namespace std;
string p1,p2;
char A[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row ,column;
bool draw = false;

void display()
{
system("cls");
cout<<"\n\t  T i c - T a c - T o e   G a m e \n\n";  
cout<<" Player-1 [X] is: "<<p1<< "\n Player-2 [O] is: "<<p2<<endl<<endl;
cout<<"\t      |       |      "<<endl;  
cout<<"\t   "<<A[0][0]<<"  |   "<<A[0][1]<<"   |   "<<A[0][2]<<endl;
cout<<"\t      |       |      "<<endl;
cout<<"\t------|-------|------"<<endl;
cout<<"\t      |       |      "<<endl;
cout<<"\t   "<<A[1][0]<<"  |   "<<A[1][1]<<"   |   "<<A[1][2]<<endl;
cout<<"\t      |       |      "<<endl;
cout<<"\t------|-------|------"<<endl;
cout<<"\t      |       |      "<<endl;
cout<<"\t   "<<A[2][0]<<"  |   "<<A[2][1]<<"   |   "<<A[2][2]<<endl;
cout<<"\t      |       |      \n"<<endl;
}
void player_turn()
{
    if(turn=='X')
    cout<<p1<<" [X] your turn: ";
    if(turn=='O')
    cout<<p2<<" [O] your turn: ";
int choice;
cin>>choice;
switch(choice)
{
case 1: row=0,column=0;break;
case 2: row=0,column=1;break;
case 3: row=0,column=2;break;
case 4: row=1,column=0;break;
case 5: row=1,column=1;break;
case 6: row=1,column=2;break;
case 7: row=2,column=0;break;
case 8: row=2,column=1;break;
case 9: row=2,column=2;break;
 default:
 cout<<"\n invalid choice\n";
 cout<<"Enter a choice between 1 & 9: "<<endl;
 player_turn();
 break;
}
if(turn=='X' && A[row][column]!='X' && A[row][column]!='O' && choice>0 && choice<10)
 {
 A[row][column] = 'X';
 turn='O';
 }
else if(turn=='O' && A[row][column]!='X' && A[row][column]!='O')
 {
 A[row][column] = 'O';
 turn='X';
 }
 else
 {
 cout<<"\nBox Is Already Filled\n "<<"Plz Try Another Intger\n\n";
 player_turn();
 }
display();
}
bool game_over()
{
//for win
for(int i=0;i<3;i++)
{
if(A[i][0]==A[i][1] && A[i][0]==A[i][2] || A[0][i]==A[1][i] && A[0][i]==A[2][i] || A[0][0]==A[1][1] && A[0][0]==A[2][2] || A[0][2]==A[1][1] && A[0][2]==A[2][0])
 {
return false;
 }
}
//for check row and column
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
  {
if(A[i][j] != 'X' && A[i][j] != 'O')
     {
      return true;
     }
  }
}
//for draw
draw=true;
return false;
}
int main()
{
cout<<"Enter Player-1 Name: ";
cin>>p1;
cout<<"Enter Player-2 Name: ";
cin>>p2;
 while(game_over())
  {
   display();
   player_turn();
   game_over();
  }
if(turn=='X' && draw==false)
{
cout<<p2<<" you Win!!    Congradulations!";
}
else if(turn=='O' && draw==false)
{
cout<<p1<<" you Win!!    Congradulations!";
}
else 
{
cout<<"    GAME DRAW!!\n\n";
}
return 0;
}
