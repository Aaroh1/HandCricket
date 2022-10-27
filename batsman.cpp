#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Batsman{
    private:
    vector<pair<int,int>> runs_scored;
    float strike_rate[3];
    float batting_avg;

    void setStrikeRate(){

    }
    protected:
    int highest_score;

    public:
    Batsman(){
        for(int i=0;i<3;i++){
            strike_rate[i] = 0;
        }
        batting_avg = 0;
        highest_score = 0;
    }
    void setRuns(int m, int runs){
        runs_scored.emplace_back(make_pair(m,runs));
    }
    int getRuns(int m){
        return runs_scored[m].second;
    }
    float getStrikeRate(int m){
        return strike_rate[m];
    }
    float getBattingAvg(){
        return batting_avg;
    }
    void displayMatchWiseStats(){

    }
};