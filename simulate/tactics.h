#ifndef TACTIC_H
#define TACTIC_H

#include<iostream>
#include<algorithm>
#include<math.h>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
enum Ptype {
        shunzi,
        three_one,
        three_two,
        three,
        four_one_one,
        four_two_two,
        four,
        two,
        one,
        Rockets,
        Unknown
};
struct play_pokers
{
        int poker[15];
        Ptype pt;
        int number;
        int main_card;
        int length;
        int itv;
        int multi;
};
class tactics
{
    private:
            int enemy_upperbound[15];
            int enemy_poker_num;
            vector<vector<int>>records;
            vector<vector<int>>predictions;
    public:
            int poker[15];
            int poker_num;
            string name;
            vector<vector<int>>poker_another_repre;
            tactics(){};
            tactics(int* pokers,string s);
            //double score();
            //bool operator<(const tactics& other);
            bool methods(struct play_pokers* in, struct play_pokers* out, bool randoms);
 
};

#endif