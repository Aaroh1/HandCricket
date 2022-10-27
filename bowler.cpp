#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>

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
        wickets[m] += w;
    }
    int getWickets(int m){
        return wickets[m];
    }
    void runsConceeded(int m, int runs){
        runs_conceeded[m] += runs;
    }
    void setEconomy(int m, float e){
        economy[m] = e;
    }
    float getEconomy(int m){
        return economy[m];
    }
};