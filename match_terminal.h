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
    Matchterminal(){}
    void WELCOME()
    {
        cout<<"WELCOME!\n";
    }
    void choices()
    {
        Batsman *b1=new Batsman[3];
        Batsman *b2=new Batsman[3];
        Bowler *bo1=new Bowler[2];
        Bowler *bo2=new Bowler[2];
        Team team1("CSK",b1,bo1);
        Team team2("KKR",b2,bo2);
        Series s(team1,team2);
        int c;
        cout<<"Enter 1 to play ";
        cin>>c;
        s.match[0].Playmatch(s.team1,s.team2);
        s.match[1].Playmatch(s.team1,s.team2);
    }
};
#endif