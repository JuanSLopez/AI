//
//  main.cpp
//  Try
//
//  Created by Juan Lopez on 3/22/19.
//  Copyright © 2019 Juan Lopez. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <vector>
#include "Sports.h"

using namespace std;



void readInFrom(string file_name,vector<sport>&list)
{

    fstream fin;
    fin.open(file_name);
    if(!fin.is_open())
    {
        cerr << "Error opening file " << file_name << "\n";
        exit(1);
    }
    
   
    
    while(true)
    {
        string nm;
        getline(fin,nm,' ');
        string s;
        getline(fin,s,' ');
        string i;
        getline(fin,i,' ');
        string r;
        getline(fin,r,' ');
        string c;
        getline(fin, c,' ');
        string a;
        getline(fin,a,' ');
        string g;
        getline(fin,g,' ');
        string w;
        getline(fin,w,' ');
        string m;
        getline(fin, m,' ');
        string ind;
        getline(fin, ind);
        if(fin.eof()){
            break;
        }
        
        list.push_back(sport(nm, s, i, r, c, a, g, w, m,ind));
    }
    
    fin.close();
    
    
    
    
    /*for(int i=0;i<list.size();i++){
        cout << list[i].name << endl;
    }*/
}










void breakdown(string in,vector<string>&commands){
    stringstream ss(in);
    while(ss.good()){
        string singleword;
        getline(ss,singleword,' ');
        commands.push_back(singleword);
        
        
    }
    
   /* for(int i=0;i<commands.size();i++){
        
        cout << commands[i] << "," << endl;
    }*/
    
}


void queryhandler(vector<sport>list){
    
  
    for(int i=0;i<list.size();i++){
        cout << list[i].name << endl;
    }
    string input1;
    string input;
    vector <string> commands;
    
    
   // while(true) {
    
    cout << "Enter a Command you would like to see. " << endl;
    cout << "Commands could be like" << endl;
    cout << "LIST which lists all sports" << endl;
    cout << "WINTER which lists all winter sports" << endl;
    cout << "NWINTER which lists all not winter sports" << endl;
    cout << "INDIVIDUAL which list all individual sports" << endl;
    cout << "NINDIVIDUAL which lists all not individual sports" << endl;
    cout << "RACE which lists all racing sports" << endl;
    cout << "NRACE which lists all not racing sports" << endl;
    cout << "CONTACT which lists all contact sports" << endl;
    cout << "NCONTACT which lists all not contact sports" << endl;
    cout << "AESTHETIC which lists all aesthic sports" << endl;
    cout << "NAESTHETIC which lists all not aesthic sports" << endl;
    cout << "GAME which lists all game sports" << endl;
    cout << "NGAME which lists all not game sports" << endl;
    cout << "WATER which lists all water sports" << endl;
    cout << "NWATER which lists all not water sports" << endl;
    cout << "MARTIAL which lists all martial sports" << endl;
    cout << "NMARTIAL which lists all not martial sports" << endl;
    cout << "INDOOR which lists all indoor sports" << endl;
    cout << "NINDOOR which lists all indoor sports" << endl;
    
    cout << "You can also use multiple of these words with conjuctions like AND ,OR, and NOT, Please directly follow it with another of the listed words" << endl;
    
    cout << " We can also allow one BUT following a word. " << endl;
    cout << "Example:\n I want a sport that is in the WINTER AND CONTACT BUT INDOOR " <<endl;
    
    getline(cin,input);
        /*if(input=="end"){
            break;
        }*/
    breakdown(input,commands);
        
        for(int i=0;i<commands.size();i++){
           ///////////////////////////////////////////////////
            if(commands[i]== "LIST"){
                cout << "LIST OF SPORTS: " << endl;
                for(int i=0;i<list.size();i++){
                    cout << list[i].name << endl;
                }
            }
          //////////////////////////////////////
            if(commands[i]=="WINTER"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                        //BUT
                        if(commands[i+3]=="BUT"){
                            if(commands[i+4]=="RACE"){
                                
                                for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].ind==true && list[i].racing == true){cout << list[i].name <<endl;}
                                    //////
                                }
                                
                            }
                            else if(commands[i+4]=="NRACE"){
                                
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].racing == false){cout << list[i].name <<endl;}
                                //////
                                    }
                                
                            }
                            else if(commands[i+4]=="CONTACT"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].contact == true){cout << list[i].name <<endl;}
                                    //////
                                    }
                                
                            }
                            else if(commands[i+4]=="NCONTACT"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].contact == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="AESTHETIC"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].aesthetic == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NAESTHETIC"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].aesthetic == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="GAME"){
                                for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].ind==true && list[i].game == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NGAME"){
                                for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].ind==true && list[i].game == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="WATER"){
                                for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].ind==true && list[i].water == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NWATER"){
                                for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].ind==true && list[i].water == false){cout << list[i].name <<endl;}
                                //////
                                }
                            }
                            else  if(commands[i+4]=="MARTIAL"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].martial == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NMARTIAL"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].martial == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="INDOOR"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].indoor == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NINDOOR"){
                                for(int i=0;i<list.size();i++){
                            if(list[i].season==false && list[i].ind==true && list[i].indoor == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else{ cout << "ERROR" << endl;}}
                        
                        //BUT
                        else{
                            for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].ind==true){
                                    cout << list[i].name << endl;
                                }
                                
                            }
                            
                        }
                    }
                
                    else if(commands[i+2]=="NINDIVIDUAL"){
                        if(commands[i+3]=="BUT"){
                            if(commands[i+4]=="RACE"){
                                
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].racing == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NRACE"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].racing == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="CONTACT"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].contact == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NCONTACT"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].contact == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="AESTHETIC"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].aesthetic == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NAESTHETIC"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].aesthetic == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="GAME"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].game == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NGAME"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].game == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="WATER"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].water == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NWATER"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].water == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else  if(commands[i+4]=="MARTIAL"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].martial == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NMARTIAL"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].martial == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="INDOOR"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].indoor == true){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else if(commands[i+4]=="NINDOOR"){
                                for(int i=0;i<list.size();i++){
                                    if(list[i].season==false && list[i].ind==false && list[i].indoor == false){cout << list[i].name <<endl;}
                                    //////
                                }
                            }
                            else{ cout << "ERROR" << endl;}}
                        
                        //BUT
                        else{
                            for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].ind==false){
                                    cout << list[i].name << endl;
                                }
                            }
                            
                        }
                        
                         cout << "OTHER SUGGESTIONS WITH SIMILAR QUALITIES " << endl;
                    }
               
                   else  if(commands[i+2]=="RACE"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else  if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].racing==true){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                    else if(commands[i+2]=="NRACE"){
                        
                        if(commands[i+3]=="BUT"){
                            if(commands[i+4]=="INDIVIDUAL"){}
                            else if(commands[i+4]=="NINDIVIDUAL"){}
                            else if(commands[i+4]=="CONTACT"){}
                            else if(commands[i+4]=="NCONTACT"){}
                            else if(commands[i+4]=="AESTHETIC"){}
                            else if(commands[i+4]=="NAESTHETIC"){}
                            else if(commands[i+4]=="GAME"){}
                            else if(commands[i+4]=="NGAME"){}
                            else if(commands[i+4]=="WATER"){}
                            else if(commands[i+4]=="NWATER"){}
                            else  if(commands[i+4]=="MARTIAL"){}
                            else if(commands[i+4]=="NMARTIAL"){}
                            else if(commands[i+4]=="INDOOR"){}
                            else if(commands[i+4]=="NINDOOR"){}
                            else{ cout << "ERROR" << endl;}}
                        
                        //BUT
                        else{
                            for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].racing==false){
                                    cout << list[i].name << endl;
                                }
                            }
                            
                        }
                        
                    }
                    else if(commands[i+2]=="CONTACT"){
                        if(commands[i+3]=="BUT"){
                            if(commands[i+4]=="INDIVIDUAL"){}
                            else if(commands[i+4]=="NINDIVIDUAL"){}
                            else if(commands[i+4]=="RACE"){}
                            else if(commands[i+4]=="NRACE"){}
                            else if(commands[i+4]=="AESTHETIC"){}
                            else if(commands[i+4]=="NAESTHETIC"){}
                            else if(commands[i+4]=="GAME"){}
                            else if(commands[i+4]=="NGAME"){}
                            else if(commands[i+4]=="WATER"){}
                            else if(commands[i+4]=="NWATER"){}
                            else  if(commands[i+4]=="MARTIAL"){}
                            else if(commands[i+4]=="NMARTIAL"){}
                            else if(commands[i+4]=="INDOOR"){}
                            else if(commands[i+4]=="NINDOOR"){}
                            else{ cout << "ERROR" << endl;}}
                        
                        //BUT
                        else{
                            for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].contact==true){
                                    cout << list[i].name << endl;
                                }
                            }
                            
                        }
                        
                    }
                   else if(commands[i+2]=="NCONTACT"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else  if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].contact==false){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                   else if(commands[i+2]=="AESTHETIC"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else  if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].aesthetic==true){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                       
                   }
                   else if(commands[i+2]=="NAESTHETIC"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else  if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].aesthetic==false){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                    else if(commands[i+2]=="GAME"){
                        if(commands[i+3]=="BUT"){
                            if(commands[i+4]=="INDIVIDUAL"){}
                            else if(commands[i+4]=="NINDIVIDUAL"){}
                            else if(commands[i+4]=="RACE"){}
                            else if(commands[i+4]=="NRACE"){}
                            else if(commands[i+4]=="CONTACT"){}
                            else if(commands[i+4]=="NCONTACT"){}
                            else if(commands[i+4]=="AESTHETIC"){}
                            else if(commands[i+4]=="NAESTHETIC"){}
                            else if(commands[i+4]=="WATER"){}
                            else if(commands[i+4]=="NWATER"){}
                            else  if(commands[i+4]=="MARTIAL"){}
                            else if(commands[i+4]=="NMARTIAL"){}
                            else if(commands[i+4]=="INDOOR"){}
                            else if(commands[i+4]=="NINDOOR"){}
                            else{ cout << "ERROR" << endl;}}
                        
                        //BUT
                        else{
                            for(int i=0;i<list.size();i++){
                                if(list[i].season==false && list[i].game==true){
                                    cout << list[i].name << endl;
                                }
                            }
                            
                        }
                    }
                   else if(commands[i+2]=="NGAME"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else  if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].game==false){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                   else if(commands[i+2]=="WATER"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else  if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].water==true){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                   else if(commands[i+2]=="NWATER"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else  if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].water==false){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                  else  if(commands[i+2]=="MARTIAL"){
                      if(commands[i+3]=="BUT"){
                          if(commands[i+4]=="INDIVIDUAL"){}
                          else if(commands[i+4]=="NINDIVIDUAL"){}
                          else if(commands[i+4]=="RACE"){}
                          else if(commands[i+4]=="NRACE"){}
                          else if(commands[i+4]=="CONTACT"){}
                          else if(commands[i+4]=="NCONTACT"){}
                          else if(commands[i+4]=="AESTHETIC"){}
                          else if(commands[i+4]=="NAESTHETIC"){}
                          else if(commands[i+4]=="GAME"){}
                          else if(commands[i+4]=="NGAME"){}
                          else  if(commands[i+4]=="WATER"){}
                          else if(commands[i+4]=="NWATER"){}
                          else if(commands[i+4]=="INDOOR"){}
                          else if(commands[i+4]=="NINDOOR"){}
                          else{ cout << "ERROR" << endl;}}
                      
                      //BUT
                      else{
                          for(int i=0;i<list.size();i++){
                              if(list[i].season==false && list[i].martial==true){
                                  cout << list[i].name << endl;
                              }
                          }
                          
                      }
                  }
                   else if(commands[i+2]=="NMARTIAL"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else  if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else if(commands[i+4]=="INDOOR"){}
                           else if(commands[i+4]=="NINDOOR"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].martial==false){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                   else if(commands[i+2]=="INDOOR"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else  if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].indoor==true){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }

                   }
                   else if(commands[i+2]=="NINDOOR"){
                       if(commands[i+3]=="BUT"){
                           if(commands[i+4]=="INDIVIDUAL"){}
                           else if(commands[i+4]=="NINDIVIDUAL"){}
                           else if(commands[i+4]=="RACE"){}
                           else if(commands[i+4]=="NRACE"){}
                           else if(commands[i+4]=="CONTACT"){}
                           else if(commands[i+4]=="NCONTACT"){}
                           else if(commands[i+4]=="AESTHETIC"){}
                           else if(commands[i+4]=="NAESTHETIC"){}
                           else if(commands[i+4]=="GAME"){}
                           else if(commands[i+4]=="NGAME"){}
                           else  if(commands[i+4]=="WATER"){}
                           else if(commands[i+4]=="NWATER"){}
                           else if(commands[i+4]=="MARTIAL"){}
                           else if(commands[i+4]=="NMARTIAL"){}
                           else{ cout << "ERROR" << endl;}}
                       
                       //BUT
                       else{
                           for(int i=0;i<list.size();i++){
                               if(list[i].season==false && list[i].indoor==false){
                                   cout << list[i].name << endl;
                               }
                           }
                           
                       }
                   }
                   else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){
                        if(commands[i+3]=="BUT"){
                            if(commands[i+4]=="RACE"){}
                            else if(commands[i+4]=="NRACE"){}
                            else if(commands[i+4]=="CONTACT"){}
                            else if(commands[i+4]=="NCONTACT"){}
                            else if(commands[i+4]=="AESTHETIC"){}
                            else if(commands[i+4]=="NAESTHETIC"){}
                            else if(commands[i+4]=="GAME"){}
                            else if(commands[i+4]=="NGAME"){}
                            else if(commands[i+4]=="WATER"){}
                            else if(commands[i+4]=="NWATER"){}
                            else  if(commands[i+4]=="MARTIAL"){}
                            else if(commands[i+4]=="NMARTIAL"){}
                            else if(commands[i+4]=="INDOOR"){}
                            else if(commands[i+4]=="NINDOOR"){}
                            else{ cout << "ERROR" << endl;}}
                        
                        //BUT
                        else{
                            for(int i=0;i<list.size();i++){
                                if(list[i].season==false || list[i].ind==true){
                                    cout << list[i].name << endl;
                                }
                            }
                            
                        }

                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].season == false){
                            cout << "WINTER SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
    
    
            ///////////////////////////////
            if(commands[i]=="NWINTER"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].season == true){
                            cout << "NOT WINTER SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            
           /////////////////////////////////
            
            if(commands[i]=="INDIVIDUAL"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="WINTER"){
                    }
                    else if(commands[i+2]=="NWINTER"){}
                    else  if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else  if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].ind == true){
                            cout << "INDIVIDUAL SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            //////////////////////////////////
            if(commands[i]=="NINDIVIDUAL"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="WINTER"){
                    }
                    else if(commands[i+2]=="NWINTER"){}
                    else  if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else  if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].ind == false){
                            cout << "NOT INDIVIDUAL SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            //////////////////////////////////
            if(commands[i]=="RACE"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].racing == true){
                            cout << "RACE SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            /////////////////////
            if(commands[i]=="NRACE"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].racing == false){
                            cout << "NOT RACING SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            ////////////////////////
            
            if(commands[i]=="CONTACT"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].contact == true){
                            cout << "CONTACT SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            //////////////////////////
            
            if(commands[i]=="NCONTACT"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].contact == false){
                            cout << "CONTACT SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            ///////////////////////////
            if(commands[i]=="AESTHETIC"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].aesthetic == true){
                            cout << "AESTHETIC SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            
            
            
            ///////////////////////////////
            if(commands[i]=="NAESTHETIC"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].aesthetic == false){
                            cout << "NOT AESTHETIC SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            
            
            ///////////////////////////////
            if(commands[i]=="GAME"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].game == true){
                            cout << "GAME SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            
            
            
            ///////////////////////////////////
            if(commands[i]=="NGAME"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].game == false){
                            cout << "NOT GAME SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            /////////////////////////////////////////
            if(commands[i]=="WATER"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].water == true){
                            cout << "WATER SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            
            /////////////////////////////////
            if(commands[i]=="NWATER"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].water == false){
                            cout << "NOT WATER SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            
            
            //////////////////////////////////
            if(commands[i]=="MARTIAL"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].martial == true){
                            cout << "MARTIAL SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            /////////////////////////////////
            if(commands[i]=="NMARTIAL"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="INDOOR"){}
                    else if(commands[i+2]=="NINDOOR"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].martial == false){
                            cout << "NOT MARTIAL SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            //////////////////////////////////
            if(commands[i]=="INDOOR"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].indoor == true){
                            cout << "INDOOR SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            //////////////////////////////////
            if(commands[i]=="NINDOOR"){
                if(commands[i+1]=="AND"){
                    if(commands[i+2]=="INDIVIDUAL"){
                    }
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else{ cout << "ERROR" << endl;}
                }
                else if(commands[i+1]=="OR"){
                    if(commands[i+2]=="INDIVIDUAL"){}
                    else if(commands[i+2]=="NINDIVIDUAL"){}
                    else  if(commands[i+2]=="WINTER"){}
                    else if(commands[i+2]=="NWINTER"){}
                    else if(commands[i+2]=="RACE"){}
                    else if(commands[i+2]=="NRACE"){}
                    else if(commands[i+2]=="CONTACT"){}
                    else if(commands[i+2]=="NCONTACCT"){}
                    else if(commands[i+2]=="AESTHETIC"){}
                    else if(commands[i+2]=="NAESTHETIC"){}
                    else if(commands[i+2]=="GAME"){}
                    else if(commands[i+2]=="NGAME"){}
                    else  if(commands[i+2]=="WATER"){}
                    else if(commands[i+2]=="NWATER"){}
                    else if(commands[i+2]=="MARTIAL"){}
                    else if(commands[i+2]=="NMARTIAL"){}
                    else{ cout << "ERROR" << endl;}
                    
                }
                else{
                    for(int i=0;i<list.size();i++){
                        if(list[i].indoor == false){
                            cout << "NOT INDOOR SPORTS " << list[i].name << endl;}
                    }
                    
                }
                
            }
            
            
            ////////////////////////////////
            
        }
        
    
    
    
    
  
    
    //}
}



void printbool(bool arg1){
    if(arg1 == true){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
}


void moduspones(vector<sport>list){
    cout << "EXAMPLE OF MODUS PONENS" << endl;
    for(int i=0;i <list.size();i++){
       
        if(list[i].name =="Basketball"){
            cout << "I am checking the sport is basketball" << endl;
            if(list[i].indoor == false){
                cout <<"you have basketball " <<endl;
                cout << "If it's not indoor and it's basketball" <<endl;
                cout << "therefore print out true if its summer " <<endl;
                printbool(list[i].season);
            }
        }
        
    }
}

int main() {
    vector<sport> list;

    readInFrom("/Users/JuanLopez/Desktop/sports.txt",list);
    
    
    //queryhandler(list);
    
    
    
    
    moduspones(list);
    
    
    
}
