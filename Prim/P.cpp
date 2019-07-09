//
//  P.cpp
//  CS350HW4
//
//  Created by hanyang xiao on 2019/3/10.
//  Copyright © 2019 hanyang xiao. All rights reserved.
//
#include"P.h"
#define SIZE 29
using namespace std;
static int weight[SIZE-1];
char *visited[SIZE];
char *departure[SIZE];

//constructor
graph::graph(int size )
{
    adjacency_list = new vertex [size];
    for(int i = 0; i < size; ++i)
    {
        adjacency_list[i].head = NULL;
        adjacency_list[i].course = NULL;
    }
    list_size = size;
}
//distructor
graph::~graph()
{
    for(int i = 0; i < list_size; ++i)
    {
        node * current = adjacency_list[i].head;
        while(current != NULL)
        {
            delete current->adjacent;
            node * temp = current;
            current = current->next;
            delete temp;
        }
    }
}

//insert vertex
int graph::insert_vertex(char * to_add)
{
    int i = 0;
    char * temp = new char[strlen(to_add) + 1];
    strcpy(temp, to_add);
    
    
    while(adjacency_list[i].course != NULL )
    {
        if(i >= 30)
        {
            return 0;
        }
        ++i;
    }
    
    adjacency_list[i].course = temp;
    adjacency_list[i].head = NULL;
    return 1;
    
}

//insert edge
int graph::insert_edge(char * current_vertex, char * to_attach, int distance_toadd)
{
    /* do
     {
     int i = find_location(current_vertex);
     }while(i < 0)*/
    int i = find_location(current_vertex);
    if(i < 0)
        return 0;
    char * temp_adjacent = new char[strlen(to_attach) + 1];
    strcpy(temp_adjacent, to_attach);
    
    node * current = new node;
    current->adjacent = temp_adjacent;
    current->distance = distance_toadd;
    current->next = NULL;
    
    
    
    node * ptr = adjacency_list[i].head;
    
    if(ptr == NULL)
    {
        adjacency_list[i].head = current;
        //cout << adjacency_list[i].head->adjacent << endl;
    }
    
    if(ptr!=NULL)
        //else
    {
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = current;
    }
    
    return 1;
    
    
}
//find location of the adjacency list
int graph::find_location(char * vertex)
{
    for(int i=0; i<list_size; ++i)
    {
        if(strcmp(vertex, adjacency_list[i].course) == 0)
        {
            return i;
        }
    }
    return -1;
}
//display all courses
int graph::display_all(char * vertex)
{
    int i = find_location(vertex);
    if(!adjacency_list)
        return 0;
    
    
    if(adjacency_list[i].course == NULL)
    {
        return 2;
    }
    cout << "The vertex course :" << adjacency_list[i].course << endl;
    
    node * current = adjacency_list[i].head;
    
    while(current!=NULL)
    {
        cout << "The edge course :" << current->adjacent << endl;
        current = current->next;
    }
    
    
    return 1;
}

void graph::read_file()
{
    char name[20];
    char second[20];
    int distance;
    
    ifstream fin;
    fin.open("city-pairs.txt");
    if(fin)
    {
        fin.get(name,20,' ');
        fin.ignore(100,' ');
        
        fin.get(second,20,' ');
        fin.ignore(100,' ');
        
        fin >> distance;
        fin.ignore(100,'\n');
        
        insert_vertex(name);
        insert_edge(name,second,distance);
        
        char * compare = new char[strlen(name)+1];
        strcpy(compare,name);
        
        while(!fin.eof())
        {
            fin.get(name,20,' ');
            fin.ignore(100,' ');
            
            fin.get(second,20,' ');
            fin.ignore(100,' ');
            
            fin >> distance;
            fin.ignore(100,'\n');
            if(name)
            {
                if(strcmp(compare,name)!=0)
                {
                    insert_vertex(name);
                    compare = new char[strlen(name)+1];
                    strcpy(compare,name);
                    //cout<<"Update a new arr line: "<<compare<<endl;
                }
                insert_edge(name,second,distance);
                //cout << "read successfully" << endl;
            }
        }
    }
    else
        fin.close();
    //cout << "read successfully" << endl;
    return;
}
void graph::display()
{
    
    for(int i=0; i<29; ++i)
    {
        if(adjacency_list[i].course)
            cout<<"CHECKING the PLACE: "<<adjacency_list[i].course<<endl;
        node * current = adjacency_list[i].head;
        while(current)
        {
            cout << "edge: "<<current->adjacent << endl;
            current = current->next;
        }
    }
}
int graph::Set_origine(char* index)
{
    int i=find_location(index);
    visited[0] = adjacency_list[i].course;
    departure[0] = adjacency_list[i].course;
    //cout << visited[0] << endl;
    //cout << visited[0];
    //cout << visited[1];
    
    //visited[0] = adjacency_list[i].course;
    return i;
}
void graph::Prim(int origin)
{
    for(int i=1; i<SIZE; ++i)
    {
        
        int min = 500;
        int count = 0;
        int k=0;
        while(visited[k])
        {
            count = count+1;
            k = k+1;
        }
        for(int l=0; l<count; ++l)
        {
        int j = find_location(visited[l]);
   

        node * current = adjacency_list[j].head;
        //node * temp = current;
        while(current)
        {

            if(current->distance < min)
            {
                if(!already_visited(current->adjacent))
                {

                    visited[i] = new char;
                    strcpy(visited[i],current->adjacent);
                    departure[i] = new char;
                    strcpy(departure[i],adjacency_list[j].course);
                    
                    min = current->distance;
                    weight[i-1] = min;

                }
                
            }
            current = current->next;
        }
        }
        
    }
    
    
}

bool graph::already_visited(char *to_check)
{
    int count = 0;
    int j=0;
    while(visited[j])
    {
        count = count+1;
        j = j+1;
    }
     //cout << "test" << endl
    for(int i=0; i<count; ++i)
    {
         //cout << "test1" << endl;
        //cout << visited[i] << endl;
        if(strcmp(visited[i], to_check)==0)
            return true;
    }
    
    return false;
    
}
void graph::output()
{
    cout << "You have visited following places : " << endl;
    for(int i=0; i< SIZE-1; ++i)
    {
        cout << visited[i] << endl;
    }
    cout << "We find the MST : " << endl;
    for(int i=0; i< SIZE-1; ++i)
    {
        cout << departure[i] << "-" <<visited[i+1] << "-" << weight[i]<< endl;
    }
    int sum = 0;
    for(int i=0; i< SIZE-1; ++i)
    {
        sum = sum + weight[i];
    }
    cout << "The total distance is : " << sum << endl;
 
}
