//
//  functions.hpp
//  hw1.1
//
//  Created by Joanna on 4/21/17.
//  Copyright © 2017 Joanna. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// RAII: ifstream (get contents of a file; convert to int)
class ReadFromFile {
    friend void getline(ReadFromFile&, string&);
    friend void getrow(ReadFromFile&, vector<int>&);
    friend ReadFromFile& operator>>(ReadFromFile&, int&);
    
public:
    ReadFromFile(const string& filename);
    bool checkEnd();
    
    ~ReadFromFile();
    
    operator bool();
    
private:
    ifstream fin;
};

// RAII: ofstream (make/update a file)
class OutputToFile{
    friend OutputToFile& operator<<(OutputToFile&, int);
    friend OutputToFile& operator<<(OutputToFile&, const string&);
    
public:
    OutputToFile(const string& filename);
    ~OutputToFile();
    
private:
    ofstream fout;
};


#endif /* functions_hpp */

