#ifndef SPORT_H
# define SPORT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct sport {
    
    string name;
    bool season; //1 for summer 0 for winter
    bool ind;
    bool racing;
    bool contact;
    bool aesthetic;
    bool game;
    bool water;
    bool martial;
    bool indoor;
    
    
    
    sport(string nm, string s, string i, string r, string c, string a, string g, string w, string m, string inn)
    {
        name = nm;
        
        if(s == "1")
            season = true;
        else
            season = false;
        
        if(i == "1")
            ind = true;
        else
            ind = false;
        
        if(r == "1")
            racing = true;
        else
            racing = false;
        
        if(c == "1")
            contact = true;
        else
            contact = false;
        
        if(a == "1")
            aesthetic = true;
        else
            aesthetic = false;
        
        if(g == "1")
            game = true;
        else
            game = false;
        
        if(w == "1")
            water = true;
        else
            water = false;
        
        if(m == "1")
            martial = true;
        else
            martial = false;
        if(inn== "1")
            indoor == true;
        else
            indoor = false;
        
    }
    
    
};


#endif

