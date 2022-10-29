#include <bits/stdc++.h>
#ifndef BOWLER_H
#define BOWLER_H

using namespace std;

class Bowler{
    private:
    int wickets[3];
    int runs_conceeded[3];
    float economy[3];

    public:
    Bowler(){
        for(int i=0;i<3;i++){
            wickets[i] = 0;
            runs_conceeded[i] = 0;
            economy[i] = 0;
        }
    }
    void setWickets(int m, int w){
        wickets[m-1] += w;
    }
    int getWickets(int m){
        return wickets[m-1];
    }
    void setRunsConceeded(int m, int runs){
        runs_conceeded[m-1] += runs;
    }
    int getRunsConceeded(int m){
        return runs_conceeded[m-1];
    }
    void setEconomy(int m, float overs){
        economy[m-1] = runs_conceeded[m-1]/overs;
    }
    float getEconomy(int m){
        return economy[m-1];
    }
    void displayBestFigures(){
        int runs = INT_MAX, wicket = INT_MIN;
        for(int i=0;i<3;i++){
            if(wickets[i]>=wicket || runs_conceeded[i]<runs){
                runs = runs_conceeded[i];
                wicket = wickets[i];
            }
        }
        cout<<"Best Figures: "<<runs<<"-"<<wicket<<endl;
    }
};

#endif