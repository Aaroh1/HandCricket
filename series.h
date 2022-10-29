#include <bits/stdc++.h>
using namespace std;
#include "team.h"
#include "Match.cpp"

class Series{
    private:
    //Data Members
    static int matches_played;
    Team team1;
    Team team2;
    Match match[3];

    public:
    //Constructors
    Series(Team cteam1, Team cteam2);
    //Member Functions    
    void getSeriesStats();
    void displayLeaderboard();
    void displayMatchScorecard(int m);
    void displayTeamStats(int t);
    void displayPlayerStats(int m);
};

int Series::matches_played = 0;

//Public Member Functions
Series:: Series(Team cteam1, Team cteam2):team1(cteam1),team2(cteam2){

}
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
    match[m-1].ScoreCard();
}
void Series:: displayTeamStats(int m){
    cout<<team1.getTeamName()<<" Stats"<<endl;
    team1.displayTeamStats(m);
    cout<<team2.getTeamName()<<" Stats"<<endl;
    team2.displayTeamStats(m);
}
void Series:: displayPlayerStats(int m){
    
}