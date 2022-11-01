#include <bits/stdc++.h>
using namespace std;
#include "team.h"
#include "Match.h"
#ifndef SERIES_H
#define SERIES_H


class Series{
    private:
    //Data Members
    static int matches_played;
    
    

    public:
    //Constructors
    Team team1;
    Team team2;
    Match match[3];
    Series(Team cteam1, Team cteam2):team1(cteam1),team2(cteam2),match{Match(), Match(), Match()}{
}
    //Member Functions    
    void getSeriesStats();
    void displayLeaderboard();
    void displayMatchScorecard(int m);
    void displayTeamStats(int t);
    void displayPlayerStats(int t, int p);
};

int Series::matches_played = 0;

//Public Member Functions
void Series:: getSeriesStats(){
    if(team1.getNoOfWins() > team2.getNoOfWins()){
        cout<<team1.getTeamName()<<" is leading the series by "<<team1.getNoOfWins()<<" - "<<team2.getNoOfWins()<<endl;
    } else if(team1.getNoOfWins() < team2.getNoOfWins()){
        cout<<team2.getTeamName()<<" is leading the series by "<<team2.getNoOfWins()<<" - "<<team1.getNoOfWins()<<endl;
    } else{
        cout<<"Series is levelled up at "<<team1.getNoOfWins()<<" - "<<team2.getNoOfWins()<<endl;
    }
}
void Series:: displayLeaderboard(){

}
void Series:: displayMatchScorecard(int m){
    // match[m-1].ScoreCard();
}
void Series:: displayTeamStats(int m){
    cout<<team1.getTeamName()<<" Stats"<<endl;
    team1.displayTeamStats(m);
    cout<<team2.getTeamName()<<" Stats"<<endl;
    team2.displayTeamStats(m);
}
void Series:: displayPlayerStats(int t, int p){
    if(t==0 && p>=1 && p<=5) team1.displayPlayerStats(p);
    else if(t==1 && p>=1 && p<=5) team1.displayPlayerStats(p);
    else cout<<"Inappropiate team or player selection"<<endl;
}


#endif