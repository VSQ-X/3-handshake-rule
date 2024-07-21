#include "Graph.h"
Graph::Graph()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    usersCount = 0;
}
void Graph::addUser(std::string user)
{
    users[usersCount++] = user;
}
int Graph::getUserIndex(std::string user)
{
    for (int i = 0; i < usersCount; i++)
        if (users[i] == user)
            return i;
    return -1;
}
void Graph::addFriendship(std::string user1, std::string user2)
{
    int index1 = getUserIndex(user1);
    int index2 = getUserIndex(user2);

    if ((index1 * index2) < 0) 
        return;

    matrix[index1][index2] = 1;
    matrix[index2][index1] = 1;
}
void Graph::findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; 
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (i == j)
                weights[i][j] = 0;
            else
                if (matrix[i][j] == 0)
                    weights[i][j] = VERYBIGINT;
                else
                    weights[i][j] = matrix[i][j];


    for (int k = 0; k < usersCount; k++) 
    {
        int ck = getUserIndex(users[k]); 

        for (int i = 0; i < usersCount; i++)
        {
            if (i == k)
                continue;

            int ci = getUserIndex(users[i]);

            for (int j = 0; j < usersCount; j++)
            {
                if (j == k)
                    continue;

                int cj = getUserIndex(users[j]);

                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
                {
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    for (int i = 0; i < usersCount; i++)
    {
        for (int j = 0; j < usersCount; j++)
            std::cout << weights[i][j] << ", ";

        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < usersCount; i++)
        for (int j = i; j < usersCount; j++)
            if (weights[i][j] == 3)
                std::cout << users[i] << "  and  " << users[j] << " know each other after 3 handshakes " << std::endl;
}
void Graph::printUsers()
{
    for (int j = 0; j < usersCount; j++)
        std::cout << "user[" << j << "] = " << users[j] << std::endl;
}
void Graph::printMatrix()
{
    for (int i = 0; i < usersCount; i++)
    {
        for (int j = 0; j < usersCount; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}