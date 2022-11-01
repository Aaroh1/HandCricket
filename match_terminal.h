#include <bits/stdc++.h>
using namespace std;
#include "series.h"
#include "batsman.h"
#include "bowler.h"
#include "team.h"
#include "Match.h"
#ifndef TERMINAL_H
#define TERMINAL_H
class Matchterminal:public Series
{
public:
    Matchterminal(Team cteam1, Team cteam2):Series(cteam1,cteam2){}
    void menu()
    {
        cout << "\n******************************************************************************************\n";
        cout << "                                     MATCH TERMINAL                                         \n\n\n\n";
        cout << "Select one option..\n";
        cout << "1.Display Teams\n";
        cout << "2.Play next Match\n";
        cout << "3.Display Scorecard of any match\n";
        cout << "4.Display Stats of a Team\n";
        cout << "5.Display Stats of a Player\n";
        cout << "6.Display Series Stats\n";
        cout << "7.Exit\n";
        cout << "\n******************************************************************************************\n";
    }
    void choices()
    {
        int c=0;
        do
        {
            menu();   
            cout<<"Enter your choice: ";
            cin>>c;
            switch(c)
            {
                case 1:
                cout<<"Team 1:- \n";
                team1.displayTeam();
                cout<<"Team 2:- \n";
                team2.displayTeam();
                break;
                case 2:
                match[getMatchesPlayed()].Playmatch(team1, team2);
                updateMatchesPlayed();
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                break;
                case 6:
                break;
                case 7:
                cout<<"                                         ADIOS!!                                     " ;
                c=-1; 
                break;
                default:
                cout<<"Invalid input try again";
                c=8;
                break;
            }
        } while (c>-1);
    }
};
#endif