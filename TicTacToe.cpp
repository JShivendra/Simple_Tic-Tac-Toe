#include <iostream>
using namespace std;
char gspace[3][3]={{'1','4','7'},{'2','5','8'},{'3','6','9'}};
bool tie1 = false;
char turn ='X';
int choice;
int r,c;
void display()
{
cout << "\t"<<gspace[0][0]<<"\t" << "|" <<"\t"<< gspace[1][0] <<"\t" << "|" <<"\t"<< gspace[2][0]<<endl;
cout << "\t" << gspace[0][1] << "\t" << "|" << "\t" << gspace[1][1] << "\t" << "|" << "\t" << gspace[2][1] << endl;
cout << "\t" << gspace[0][2] << "\t" << "|" << "\t" << gspace[1][2] << "\t" << "|" << "\t" << gspace[2][2] << endl;
}
 
bool check()
{
    for(int i=0;i<3;i++)
    { 
        if(((gspace[0][i]==gspace[1][i])&&(gspace[1][i] == gspace[2][i]))||((gspace[i][0] == gspace[i][1]) && (gspace[i][1] == gspace[i][2])))
            return true;
    } 
    if (((gspace[0][0] == gspace[1][1]) && (gspace[1][1] == gspace[2][2])) || ((gspace[2][0] == gspace[1][1]) && (gspace[1][1] == gspace[0][2])))
        return true;

    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            if ((gspace[i][j] != 'X') && (gspace[i][j] != 'O'))
                return false;
           
        }
    }
    tie1 = true;
    return true;
}
void input()
{
    retry: if (turn == 'X')
        cout << "\n Player 1 (X) Plays : ";
    else if (turn == 'O')
        cout << "\n Player 2 (O) Plays : ";
    cout<<"Enter a valid position !";
    cin>>choice;

    switch (choice)
    {
    case 1: r = 0; c = 0; break;
    case 2: r = 1; c = 0; break;
    case 3: r = 2; c = 0; break;
    case 4: r = 0; c = 1; break;
    case 5: r = 1; c = 1; break;
    case 6: r = 2; c = 1; break;
    case 7: r = 0; c = 2; break;
    case 8: r = 1; c = 2; break;
    case 9: r = 2; c = 2; break;
    default:
        {
            cout<<"Invalid, TRY AGAIN ";
            goto retry;
        }
    }
    if((turn=='X')&&(gspace[r][c]!='X')&&(gspace[r][c]!='O'))
        {
            gspace[r][c]='X';
            turn='O';
        }
    else if ((turn == 'O') && (gspace[r][c] != 'X') && (gspace[r][c] != 'O'))
        {
            gspace[r][c] = 'O';
            turn='X';
        }
    else
        {
            cout<<"INVALID: Slot is already taken, pick another slot";
            input();
        }

}

void result()
{
    if((turn=='X')&&(tie1==false))
    {
        cout << "PLAYER 2 [O] WINS !!!\n";
        display();
    }
    else if((turn == 'O') && (tie1 == false))
    {
        cout << "PLAYER 1 [X] WINS !!!\n";
        display();
    }
    else
    {
        cout << "IT'S A TIE \n";
        display();
    }
}

int main()
{
cout<<"\n\n \t\t TIC-TAC-TOE  \t\t";
cout<<"Press Enter to Start";
cin.get();
while (!check())
{
    display();
    input();
    check();
}
result();
return 0;
}
