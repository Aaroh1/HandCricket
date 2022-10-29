#include <bits/stdc++.h>
using namespace std;

class Batsman{
    private:
    int runs_scored[3];
    float strike_rate[3];
    float batting_avg;
    static int balls_faced[3];

    void setStrikeRate(int m){
        strike_rate[m-1] = runs_scored[m-1]/balls_faced[m-1];
    }
    void setBattingAvg(int m){
        int runs = 0;
        for(int i=0;i<m;i++){
            runs += runs_scored[i];
        }
        batting_avg = runs/m;
    }
    protected:
    int highest_score;

    public:
    Batsman(){
        for(int i=0;i<3;i++){
            runs_scored[i] = 0;
            strike_rate[i] = 0;
        }
        batting_avg = 0.0;
        highest_score = 0;
    }
    void setRuns(int m, int runs){
        runs_scored[m-1] += runs;
        balls_faced[m-1] += 1;
        setStrikeRate(m);
        setBattingAvg(m);
    }
    int getRuns(int m){
        return runs_scored[m-1];
    }
    float getStrikeRate(int m){
        return strike_rate[m-1];
    }
    float getBattingAvg(){
        return batting_avg;
    }
    void displayMatchWiseStats(int m){
        cout<<"Runs Scored in Match "<<m<<" : "<<getRuns(m)<<endl;
        cout<<"Balls faced in Match "<<m<<" : "<<balls_faced[m-1]<<endl;
        cout<<"Strike Rate in Match "<<m<<" : "<<getStrikeRate(m)<<endl;
        cout<<"Batting Average till Match "<<m<<" : "<<getBattingAvg()<<endl; 
    }
};