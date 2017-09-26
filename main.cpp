//
//  main.cpp
//  McDoom
//
//  Created by Jaume on 25/08/15.
//  Copyright (c) 2015 Jaume. All rights reserved.
//
// To Do Municipalities and account for multiple polygons and holes.
// Inconsistent Area

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include<climits>


using namespace std;



const double FACTOR = 12365; //  factor, esta malament, busca quin numero hauria d'anar aqui per passar de "graus quadrats" a km2

struct point {
    double x, y;
    point() {}
    point(double xx, double yy) : x(xx), y(yy) {}
    double operator^ (point p) {
        return x * p.y - y * p.x;
    }
    point operator- (point p) {
        return point(x - p.x, y - p.y);
    }
    point operator+ (point p) {
        return point(x + p.x, y + p.y);
    }
    
};


/*
double polygon() {
    string L;
    vector<point> v;
    double sgn = +1;
    while (getline(cin, L) and L != "") {
        if (L == "Hole=Yes") 
            sgn = -1;
            continue;
        }
        stringstream ss(L);
        point p;
        ss >> p.x >> p.y;
        v.push_back(p);
    }
    point q = v[0];
    long int n = v.size();
    double area = 0;
    for (int i = 2; i < n; ++i) {
        area += (v[i - 1] - q) ^ (v[i] - q);
    }
    area = abs(area);
    return area * sgn / 2.0 * FACTOR;
}

 */

string find (string r) {
    string anchor ("=");
    size_t found=r.find(anchor);

    if (found!=std::string::npos) {
        r.erase(0,found);
    }
    r.erase(0,2);
    
    return r;
}

string replace (string read) {
    // 012801001

    int aux=0, sum2=0, sum3=0, sum4=0, sum5=0;
    string zero="0";
    for (int i=0; i<read.size(); i++) {
        if(sum2==2) {break;}
       
        if (read[i]==' ') {sum2++;}
        sum3++;
        if (sum2==1 and read[i]!=' ') sum5++;
        if (sum2==0) sum4++;
    }
    //cout<<sum3<<endl;

    for (int i = 0; i < read.length(); ++i) {
        aux++;
        if (read[i]== ' ' and aux==2) {read.insert(0,zero);} else {if (aux==2) sum3++;}
        if (i==2 and sum3>=5) {read.erase(read.begin()+2);
            if (sum4==2 and sum5==1) {read.insert(2,zero);}
        }
            if (read[i] == ' ' and i>=2) {
            read[i] = '0';
        }
    }
        int aux2=5;
        int sum=0;
        while (read[aux2]!='0') {
            sum++;
            aux2++;
        }
    //cout<<sum<<endl;
    if (read[7]=='0') sum++;
        if(sum>=2) read.erase(read.begin()+4);
    string str=read;
    str.erase(0,6);
    //cout<<str<<endl;
    //cout<<str.size()<<endl;
    if (str.size()==3) read.insert(6, zero);
    if (str.size()>4) read.erase(read.begin()+6);
    //if(read.size()!=10) {read.erase(read.begin()+6);}
    
    
    return read;
}


int counter( const std::string& input )
{
    int iSpaces = 0;
    
    for (int i = 0; i < input.size(); ++i)
        if (input[i] == ' ') ++iSpaces;
    
    return iSpaces;
}

 


int main() {
    
    string read,read2,read22, str;
    string anchor ("AreaStructure");
    string anchor2;
    string anchor3 ("X");
    string anchor4 ("=");
  //  double area=1;
  //  bool previous=false;

    int count=0,aux=0,aux2=0, sqr, sum=0, sums=0;
    
    //open file
    ifstream filentry;
    filentry.open("PHL_CPH.map.txt");
    
    ifstream names;
    names.open("PHL_CPH.anm.txt");
    
    //exit file
    ofstream filexit;
    filexit.open("Codes.txt");
    
    ofstream filexit2;
    filexit2.open("Name.txt");
    
    ofstream filexit3;
    filexit3.open("GeoCoord.txt");
    
    ofstream filexit4;
    filexit4.open("output data.txt");
    
    
    ofstream xcel;
    xcel.open("data.csv");
    
    
    
    for (int i=0; i<=10; i++) {
        getline(names,read2);
    }
    
    
    if (filentry.is_open() and names.is_open()) {
        
    while ( getline (filentry, read) )
    {
        
     size_t found=read.find(anchor);
        
        if (found!=std::string::npos) {
            
            count++;
            
            sqr=counter( read );

            if (sqr==3) {
            
                cout<<read<<endl;
                
                str=read.erase(0,14);
                
                
               cout<<replace(str)<<endl;
                if(replace(str).size()!=10) cout<<" *******************************************************";
                    
                
                xcel<<replace(str)<<endl;
                
              //  filexit<<replace(str)<<",";
                
               // cout<<count<<endl;
            
                for (int i=1; i<=count-aux2; i++) {
                    
                    getline(names,read2);

            
                    if (i>count-aux2-1) {
                        
                        size_t found=read2.find(anchor3);
                        
                        if (found!=std::string::npos) {}
                        else {

                            read22=find(read2);
                            
                            cout<<read22<<endl;
                            
                           // filexit<<read22;
                            
                            xcel<<read22<<"*";
                    }
                    }
                    aux++;
                   
                }
                
               // cout<<aux<<endl;
                aux2=aux;
                
                string L;
                
                vector<point> v;
                
                double sgn = +1;
                
                getline(filentry, anchor2);
                getline(filentry, anchor2);
                getline(filentry, anchor2);
                
                sums++; sum++;
                filexit<<replace(str);
                filexit2<<read22;
                filexit3<<anchor2;
                cout<<anchor2<<" S "<<endl;
                
                while (getline(filentry, read) and read!="") {
                    
                    size_t found=read.find(anchor2);
                    
                    if (found!=std::string::npos) {sums++; sum++;
                        
                        filexit<<replace(str);
                        filexit2<<read22;
                        filexit3<<read;
                        cout<<"SS"<<endl;
                        cout<<read<<endl;
                        break;}
                    
                    else { sums++; sum++;
                        filexit<<replace(str);
                        filexit2<<read22;
                        filexit3<<read;
                        cout<<read<<endl;
                    

                        if (read == "Hole=Yes") {
                                   sgn = -1;
                                   continue;
                               }
                               stringstream ss(read);
                               point p;
                               ss >> p.x >> p.y;
                               v.push_back(p);
                    
                        }
                    
                    }
                
                //Fuentes has the same three coordinates!!!
                if (v.size()==0) {double area=0; xcel<<area<<"*";}
                else {
                point q = v[0];
                
                long int n = v.size();
                
                double area = 0;
                
                for (int i = 2; i < n; ++i) {
                    area += (v[i - 1] - q) ^ (v[i] - q);
                           }
                
                area = abs(area);
                
                area=area * sgn / 2.0 * FACTOR;
              
                //  cout<<area<<endl;
                
                xcel<<area<<"*";
                }
        }
        }
      
      //if (count==400) break;
    }
        
}

    
    filentry.close();
    names.close();
    filexit.close();
    xcel.close();
    
    int c;
    cin>> c;
    
    
}
