#ifndef GRAPH
#define GRAPH

#include <iostream>

#define SIZE 10
#define VERYBIGINT 10000

class Graph
{
private:
    int matrix[SIZE][SIZE];          
    std::string users[SIZE];         
    int usersCount;                  

    bool FriendshipExists(std::string u1, std::string u2);
    int getUserIndex(std::string user);

public:
    Graph();
    void addUser(std::string user);
    void addFriendship(std::string u1, std::string u2);
    void findMinDistancesFloyd();
    void printUsers();
    void printMatrix();
};

#endif 