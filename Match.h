#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include "team.h"
#ifndef MATCH_H
#define MATCH_H

using namespace std;
class Match
{
    int target;
    int currentscore;
    int wickets;
    int inningsnum;
    int matchnum;
    int Toss();
    void Bat(int, Team &, Team &);
    void Bowl(int, Team &, Team &);
    void setTarget(int);
    void setCurrentScore(int score);
    void setWickets(int wick);
    int getTarget();
    int getCurrentScore();
    int getWickets();

protected:
    int match;

public:
    Match()
    {
        target=-1;
        currentscore=0;
        wickets=0;
        matchnum=0;
        inningsnum=1;
    }
    void ScoreCard();
    void Playmatch(Team &, Team &);
};
void Match::setTarget(int t)
{
    target=t;
}
void Match::setCurrentScore(int s)
{
    currentscore=s;
}
void Match::setWickets(int w)
{
    wickets=w;
}
int Match::getTarget()
{
    return target;
}
int Match::Toss()
{
    return rand() % 2;
}
void Match::Playmatch(Team &t1, Team &t2)
{
    matchnum=t1.getNoOfWins()+t2.getNoOfWins()+1;
    cout<<"Match "<<matchnum<<" out of 4 in the Series\n";
    cout << "Match about to begin .....\n";
    int teambat, teambowl;
    teambat = Toss();
    teambowl = !teambat;
    cout << "Team " << teambat + 1 << " has won the Toss and decided to bat first!\n";
    cout << "Which team would you like to play as!? ";
    int choice;
    cin >> choice;
    if (choice == teambat + 1)
    {
        if (teambat)
        {
            Bat(teambat, t2, t1);
            Bowl(teambat, t2, t1);
        }
        else
        {
            Bat(teambat, t1, t2);
            Bowl(teambat, t1, t2);
        }
    }
    else
    {
        if (!teambowl)
        {
            Bowl(teambowl, t1, t2);
            Bat(teambowl, t1, t2);
        }
        else
        {
            Bowl(teambowl, t2, t1);
            Bat(teambowl, t2, t1);
        }
    }
}
void Match::Bat(int t, Team &t1, Team &t2)
{
    system("cls");
    int bat, ball, overs = 0, numballs = 0;setCurrentScore(0);setWickets(0);
    cout << "Innings " << inningsnum << endl;
    cout << "Batting : Team " <<t1.getTeamName()<< endl;
    cout << "Bowling : Team " <<t2.getTeamName()<< endl;
    while (wickets < 3 && overs < 4)
    {
        cout << "enter a number between 1 and 6: ";
        cin >> bat;
        if (bat < 1 || bat > 6)
        {
            cout << "Invalid entry. Try again....\n\n";
            continue;
        }
        ball = rand() % 6 + 1;
        numballs++;
        cout << "The cpu picked : " << ball << endl;
        if (ball == bat)
        {
            wickets++;
            t2.updateBowlStats(matchnum,0,1,1+overs%2,1+overs%2);
            cout<< "Oh No! You've lost a wicket....!!\n";
            cout << "On strike: Player " << wickets + 1 << endl;
        }
        else
        {
            switch (bat)
            {
            case 1:
                cout << "A quick single\n";
                currentscore += 1;
                break;
            case 2:
                cout << "Two runs\n";
                currentscore += 2;
                break;
            case 3:
                cout << "Pacy 3 runs\n";
                currentscore += 3;
                break;
            case 4:
                cout << "Cruising out for a four!\n";
                currentscore += 4;
                break;
            case 6:
                cout << "Smashed out for 6 runs!!\n";
                currentscore += 6;
                break;
            }
            t1.updateBatStats(matchnum,bat,wickets+1);
            t2.updateBowlStats(matchnum,bat,0,1+overs%2,1+overs%2);
        }
        // BOX print
        cout << currentscore << " - " << wickets << " \n\n";
        if (target != -1)
        {
            if (currentscore > target)
                break;
            cout << " Team " << t + 1 << " needs " << target - currentscore << " runs in " << 24 - numballs << " balls.\n";
        }
        if (numballs % 6 == 0)
        {
            cout << "End of over " << overs + 1 << endl;
            overs++;
            cout << "On strike: Player " << wickets + 1 << endl;
            cout << "With the Ball: Player " << 4 + overs % 2 << endl;
        }
    }
    if (wickets == 3)
        cout << "All OUT!!\n";
    cout << "End of Innings " << inningsnum << "\n";
    if (target > -1)
    {
        if (currentscore >= target)
        {
            cout << "Hurray! Team " << t + 1 << " has completed the chase and won the match by " << 3 - wickets << " wickets!\n";
            t1.updateNoOfWins(t1.getNoOfWins() + 1);
        }
        else
        {
            cout << "Alas! You could not achieve the target :( \nTeam " << t + 1 << " has lost the match!\n";
            cout << "Team " << !t + 1 << " won by " << target - currentscore << " runs.\n";
            t2.updateNoOfWins(t2.getNoOfWins() + 1);
        }
    }
    else
    {
        inningsnum++;
        cout << "Team " << t + 1 << " has scored " << currentscore << " runs.\n";
        setTarget(currentscore + 1);
        cout << "Target for Team " << !t + 1 << " : " << getTarget() << " runs.\n";
        cout << "You need to defend " << getTarget() << " runs in 4 overs.\n";
    }
    cout<<"\nEnter any number to continue......";
    cin>>t;
}
void Match::Bowl(int t, Team &t1, Team &t2)
{
    system("cls");
    int bat, ball, overs = 0, numballs = 0;setCurrentScore(0);setWickets(0);
    cout << "Innings " << inningsnum << endl;
    cout << "Batting : Team " <<t2.getTeamName()<< endl;
    cout << "Bowling : Team " <<t1.getTeamName()<< endl;
    while (wickets < 3 && overs < 4 && (target == -1) ? 1 : target > currentscore)
    {
        cout << "Enter a number between 1 and 6: ";
        cin >> ball;
        if (bat < 1 || bat > 6)
        {
            cout << "Invalid entry. Try again\n\n";
            continue;
        }
        bat = rand() % 6 + 1;
        numballs++;
        cout << "The cpu picked : " << bat << endl;
        if (ball == bat)
        {
            wickets++;
            t1.updateBowlStats(matchnum,0,1,1+overs%2,1+overs%2);
            cout << "Beautiful delivery! The CPU lost a wicket....!!\n";
        }
        else
        {
            currentscore += bat;
            t2.updateBatStats(matchnum,bat,wickets+1);
            t1.updateBowlStats(matchnum,bat,0,1+overs%2,1+overs%2);
        }
        // BOX print
        cout << currentscore << " - " << wickets << " \n";
        if (target != -1)
        {
            if (currentscore > target)
                break;
            cout << " Team " << !t + 1 << " needs " << target - currentscore << " runs in " << 24 - numballs << " balls.\n";
        }
        if (numballs % 6 == 0)
        {
            cout << "End of over " << overs + 1 << endl;
            overs++;
            cout << "On strike: Player " << wickets + 1 << endl;
            cout << "With the Ball: Player " << 4 + overs % 2 << endl;
        }
    }
    if (wickets == 3)
        cout << "All OUT!!\n";
    cout << "End of Innings " << inningsnum << "\n";
    if (target > -1)
    {
        if (currentscore >= target)
        {
            cout << "Tough Luck! Team " << !t + 1 << " has completed the chase and won the match by " << 3 - wickets << " wickets!\n";
            t2.updateNoOfWins(t2.getNoOfWins() + 1);
        }
        else
        {
            cout << "Good work done! Team " << t + 1 << " has successfully defended " << target << " runs!\n";
            cout << "Team " << t + 1 << " won by " << target - currentscore << " runs.\n";
            t1.updateNoOfWins(t1.getNoOfWins() + 1);
        }
    }
    else
    {
        inningsnum++;
        cout << "Team " << !t + 1 << " has amassed a score of " << currentscore << " runs.\n";
        setTarget(currentscore + 1);
        cout << "Target for Team " << !t + 1 << " : " << getTarget() << " runs.\n";
        cout << "You need to score " << getTarget() << " run in 4 overs.\n";
    }
    cout<<"\nEnter any number to continue......";
    cin>>t;
}
#endif