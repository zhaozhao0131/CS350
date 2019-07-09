//
//  main.cpp
//  CS350HW4
//
//  Created by hanyang xiao on 2019/3/10.
//  Copyright © 2019 hanyang xiao. All rights reserved.
//


#include"P.h"
#define SIZE 29
using namespace std;
int main()
{
    
    cout << "Run Instructions: " << endl;
    cout << "Please Enter a vertex as you wish, this vertex will be set as the original vertex" << endl;
    cout << "Then it will give you the result." << endl;
    graph ob;
    ob.read_file();
    //ob.display();
    cout << "Enter the oringinal vertex" << endl;
    char temp[20];
    cin.get(temp, 20, '\n');
    cin.ignore(100, '\n');
    int original_index = ob.Set_origine(temp);
    //cout << "test" << endl;
    ob.Prim(original_index);
    //cout << "test" << endl;
    ob.output();
    return 0;
} 
