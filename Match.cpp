#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>

class Match
{
    int target;
    int currentscore;
    int wickets;
    static int inningsnum;
    int Toss();
    void Bat(int);
    void Bowl(int);
    void setTarget(int target);
    void setCurrentScore(int score);
    void setWickets(int wick);
    int getTarget();
    int getCurrentScore();
    int getWickets();

protected:
    int match;
    int innings;

public:
    void ScoreCard();
    void Playmatch();
};
int Match::inningsnum = 1;
int Match::Toss()
{
    return rand() % 2;
}
void Match::Playmatch()
{
    cout << "Match about to begin .....\n";
    int teambat, teambowl;
    teambat = Toss();
    teambowl = !teambat;
    cout << "Team " << teambat + 1 << " has won the Toss and decided to bat first!\n";
    cout << "Which team would you like to play as!? ";
    int choice;
    cin >> choice;
    if (choice == teambat + 1)
        Bat(teambat);
    else
        Bowl(teambat);
}
void Match::Bat(int t)
{
    system("cls");
    int bat, ball;
    while (wickets < 3)
    {
        cout << "enter a number between 1 and 6(except 5): ";
        cin >> bat;
        if (bat < 1 || bat > 6 || bat==5 )
        {
            cout << "Invalid entry. Try again";
            continue;
        }
        ball = rand() % 6 + 1;
        cout<<"The bowler picked : "<<ball<<endl;
        if(ball==bat)
        {
            wickets++;
            cout<<"Oh No! You've lost a wicket....!!";
        }
        else
        {
            switch(bat)
            {
                case 1:
                cout<<"A quick single\n";
                currentscore+=1;
                break;
                case 2:
                cout<<"Two runs\n";
                currentscore+=2;
                break;
                case 3:
                cout<<"Pacy 3 runs\n";
                currentscore+=3;
                break;
                case 4:
                cout<<"Cruising out for a four!\n";
                currentscore+=4;
                break;
                case 6:
                cout<<"Smashed out for 6 runs!!\n";
                currentscore+=6;
                break;
            }
        }
    }
}
using namespace std;
int main()
{
    return 0;
}