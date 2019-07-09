//
//  P.h
//  CS350HW4
//
//  Created by hanyang xiao on 2019/3/10.
//  Copyright © 2019 hanyang xiao. All rights reserved.
//
#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>
struct vertex
{
    char * course;
    struct node * head;
};

struct node
{
    char * adjacent;
    int distance;
    node * next;
};

class graph
{
public:
    graph(int size = 29);
    ~graph(void);
    int insert_vertex(char * to_add);
    int insert_edge(char * current_vertex, char * to_attach,int distance);
    int display_all(char *);
    int find_location(char *);             //to find the index of the array
    void read_file();
    void display();
    int Set_origine(char *);
    void Prim(int);
    //char transfer(string);
    bool already_visited(char *to_check);
    void output();
private:
    vertex * adjacency_list;
    int list_size;
};
