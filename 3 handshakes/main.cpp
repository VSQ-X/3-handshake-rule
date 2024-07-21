#include "graph.h"
auto main() -> int{
	Graph g;
    std::string user1 = "oleg";
    std::string user2 = "nikita";
    std::string user3 = "nastya";
    std::string user4 = "ivan";
    std::string user5 = "zhenya";
    std::string user6 = "lena";
    std::string user7 = "dima";

    g.addUser(user1);
    g.addUser(user2);
    g.addUser(user3);
    g.addUser(user4);
    g.addUser(user5);
    g.addUser(user6);
    g.addUser(user7);

    std::cout<<"Users:\n";
    g.printUsers();

    g.addFriendship(user1, user5);
    g.addFriendship(user5, user2);
    g.addFriendship(user2, user6);
    g.addFriendship(user6, user3);
    g.addFriendship(user3, user4);
    g.addFriendship(user4, user7);

    std::cout << "friend matrix:\n";
    g.printMatrix();

    std::cout<<"meet matrix\n";
    g.findMinDistancesFloyd();

    return 0;
}