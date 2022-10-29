#include <bits/stdc++.h>
using namespace std;
#include "batsman.h"
#include "bowler.h"

class Team{
    private:
    string name;
    int no_of_Wins;
    int bestBatsman;
    int bestBowler;
    Batsman batsmen[3];
    Bowler bowlers[2];

    public:
    void displayTeam(){
        cout<<"Playing team"<<endl;
        cout<<"Player 1(Batsman)"<<endl;
        cout<<"Player 2(Batsman)"<<endl;
        cout<<"Player 3(Batsman)"<<endl;
        cout<<"Player 4(Bowler)"<<endl;
        cout<<"Player 5(Bowler)"<<endl;
    }
    void updateBatStats(int m, int runs, int i){
        batsmen[i-1].setRuns(m,runs);
    }
    void updateBowlStats(int m, int runs, int w, int i, float overs){
        bowlers[i-1].setRunsConceeded(m,runs);
        bowlers[i-1].setWickets(m,w);
        bowlers[i-1].setEconomy(m,overs);
    }
    void displayMatchStats(int m){
        
    }


};
