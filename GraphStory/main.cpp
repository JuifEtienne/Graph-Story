#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Files.hpp"
#include "Node.hpp"
#include "Graph.hpp"


int main() {

    std::vector<std::string> information;
    information = storyToString(67);
    Graph story(information);
    int choice = 0;

    while(story.getNbNeighbor() != 0){  //Search if the current node as neighbor

        story.printCurrentNode();

        std::cout << "Vers quelle page souhaitez-vous aller ?" << std::endl;
        std::cin >> choice;

        try{
            story.isANextNode(choice);
            story.setCurrentNode(choice);
        }
        catch(const std::string &s){
            std::cerr << "Erreur : " << s << std::endl;
        }

        std::cout << std::endl;
    }

    story.printDescription(); //We print the end of the story (it's the node with no neighbor

    story.freeVect();

    return 0;
}