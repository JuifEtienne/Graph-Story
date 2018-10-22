//
// Created by Etienne on 27/11/2017.
//


#include <iostream>
#include <vector>
#include <sstream>

#include "Files.hpp"
#include "Node.hpp"
#include "Graph.hpp"

Graph::Graph(std::vector<std::string> &information){
    std::string temp;
    std::istringstream iss(information[0]);
    std::getline(iss, temp, ';');
    m_nbNode = std::stoi(temp);
    m_currentNode = 0;
    for(int i=0; i< information.size(); ++i){
        if(isAStoryNode(information[i]) == 1){
            m_vecNode.push_back(new Node(information[i]));
        }
        else{
            m_vecNode.push_back(new QuestionNode(information[i]));
        }
    }
}

void Graph::setNbNode(const int nbNode){
    m_nbNode = nbNode;
}
void Graph::setCurrentNode(const int currentNode){
    m_currentNode = currentNode;
}

int Graph::getNbNode() const{
    return m_nbNode;
}
int Graph::getCurrentNode() const{
    return m_currentNode;
}

void Graph::freeVect(){
    int i;
    for(i=0; i< m_nbNode ; ++i){
        delete m_vecNode[i];
        m_vecNode[i] = nullptr;
    }
}

int Graph::getNbNeighbor() const{
    return m_vecNode[m_currentNode] -> getNbNeighbor();
}

void Graph::printCurrentNode() const{
    m_vecNode[m_currentNode] -> printNode();
}

int Graph::isANextNode(int choice) const{
    if(m_vecNode[m_currentNode] -> inTheNode(choice) == 1){
        return 1;
    }
    else{
        throw std::string("It's not a neighbor of the current Node !");
    }
}

void Graph::printDescription() const{
    std::cout << m_vecNode[m_currentNode] -> getDescription() << std::endl;
}

/*void Graph::printIdNeighbor() const{
    int i;
    for(i=0; i<getNbNeighbor(); ++i){
        std::cout << m_vecNode[m_currentNode]->getIdNeighbors()[i] << std::endl;
    }
}*/