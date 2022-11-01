#include <bits/stdc++.h>
using namespace std;
#include "series.h"
#include "batsman.h"
#include "bowler.h"
#include "team.h"
#include "Match.h"
#ifndef TERMINAL_H
#define TERMINAL_H
class Matchterminal
{
public:
    Matchterminal() {}
    void WELCOME()
    {
        cout << "Welcome to the tri match Hand-Cricket Series!\n";
    }
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
        Batsman *b1 = new Batsman[3];
        Batsman *b2 = new Batsman[3];
        Bowler *bo1 = new Bowler[2];
        Bowler *bo2 = new Bowler[2];
        string name;
        cout << "Enter name of team 1 : ";
        cin >> name;
        Team team1(name, b1, bo1);
        cout << "Enter name of team 2 : ";
        cin >> name;
        Team team2(name, b2, bo2);
        Series s(team1, team2);
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
                s.team1.displayTeam();
                cout<<"Team 2:- \n";
                s.team2.displayTeam();
                break;
                case 2:
                s.match[s.getMatchesPlayed()].Playmatch(s.team1, s.team2);
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

        int c;
        cout << "Enter 1 to play ";
        cin >> c;
        s.displayTeamStats(1);
        cout << "\n";
        s.displayPlayerStats(1, 3);
        s.displayPlayerStats(1, 4);
        s.team1.displayMatchStats(1);
        s.team2.displayMatchStats(1);
    }
};
#endif