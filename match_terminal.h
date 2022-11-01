#include <bits/stdc++.h>
#include <conio.h>
#include <cstdlib>
using namespace std;
#include "series.h"
#include "batsman.h"
#include "bowler.h"
#include "team.h"
#include "Match.h"
#ifndef TERMINAL_H
#define TERMINAL_H
class Matchterminal : public Series
{
public:
    Matchterminal(Team cteam1, Team cteam2) : Series(cteam1, cteam2) {}
    void menu()
    {
        cout << "\n******************************************************************************************\n";
        cout << "                                     MATCH TERMINAL                                         \n\n";
        cout << "Select one option..\n";
        cout << "1.Display Teams\n";
        cout << "2.Play next Match\n";
        cout << "3.Display Scorecard of any match\n";
        cout << "4.Display Stats of a Team\n";
        cout << "5.Display Overall Stats of a Player\n";
        cout << "6.Display MatchWise Stats of a Player\n";
        cout << "7.Display Series Stats\n";
        cout << "8.Exit\n";
        cout << "\n******************************************************************************************\n";
    }
    void choices()
    {
        int c = 0;
        char d = 0;
        do
        {
            system("cls");
            menu();
            cout << "Enter your choice: ";
            cin >> c;
            cout << "\n";
            switch (c)
            {
            case 1:
                cout << "Team 1:- \n";
                team1.displayTeam();
                cout << "Team 2:- \n";
                team2.displayTeam();
                cout << "\nEnter any char to continue: ";
                cin >> d;
                break;

            case 2:
                match[getMatchesPlayed()].Playmatch(team1, team2);
                updateMatchesPlayed();
                break;

            case 3:
                int n;
                cout << "Enter match number(Matches played till now = " << getMatchesPlayed() << ") : ";
                cin >> n;
                if (n >= 1 && n <= getMatchesPlayed())
                    displayMatchScorecard(n);
                else
                    cout << "Invalid input try again";
                cout << "\nEnter any char to continue: ";
                cin >> d;
                break;

            case 4:
                if (getMatchesPlayed())
                {
                    int m;
                    cout << "Enter match number(Matches played till now = " << getMatchesPlayed() << ") : ";
                    cin >> m;
                    if (m >= 1 && m <= getMatchesPlayed())
                        displayTeamStats(m);
                    else
                        cout << "No matches played yet!\n";
                }
                else
                    cout << "No matches played yet!\n";
                cout << "\nEnter any char to continue: ";
                cin >> d;
                break;

            case 5:
                if (getMatchesPlayed())
                {
                    int t, p;
                    cout << "Enter team number : ";
                    cin >> t;
                    cout << "Enter player number : ";
                    cin >> p;
                    displayPlayerStats(t, p);
                }
                else
                    cout << "No matches played yet!\n";
                cout << "\nEnter any char to continue: ";
                cin >> d;
                break;

            case 6:
                if (getMatchesPlayed())
                {
                    int t, p, m;
                    cout << "Enter team number : ";
                    cin >> t;
                    cout << "Enter player number : ";
                    cin >> p;
                    cout << "Enter match number (Matches played till now = " << getMatchesPlayed() << ") : ";
                    cin >> m;
                    if (t == 1)
                    {
                        if (p >= 1 && p <= 3)
                            team1.batsmen[p - 1].displayMatchWiseStats(m);
                        else
                            team1.bowlers[p - 4].displayBestFigures();
                    }
                    else
                    {
                        if (p >= 1 && p <= 3)
                            team2.batsmen[p - 1].displayMatchWiseStats(m);
                        else
                            team2.bowlers[p - 4].displayBestFigures();
                    }
                }
                else
                    cout << "No matches played yet!\n";
                cout << "\nEnter any char to continue: ";
                cin >> d;
                break;

            case 7:
                if (getMatchesPlayed())
                    getSeriesStats();
                else
                    cout << "No matches played yet!\n";
                cout << "\nEnter any char to continue: ";
                cin >> d;
                break;

            case 8:
                cout << "                                         ADIOS!!                                     ";
                c = -2;
                break;
            default:
                cout << "Invalid input try again";
                c = 8;
                break;
            }
        } while (c > -1);
        SeriesResult();
    }
    void SeriesResult()
    {
        cout<<"\n                 The Series has ended!..\n";
        displayLeaderboard();
    }
};
#endif