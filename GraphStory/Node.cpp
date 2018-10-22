#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "Node.hpp"

/***NODE***/

Node::Node(std::string &information) {
    //The string is taken from the file so she is in the good format
    std::string temp;
    std::istringstream iss(information);
    std::getline(iss, temp, ';');
    if(stoi(temp) == 0){
        m_nbNeighbor = 0;
    }
    else{
        m_nbNeighbor = 1;
    }
    std::getline(iss, temp, ';');
    setDescription(temp);
    std::getline(iss, temp, ';');
    m_idNeighbors.push_back(stoi(temp));
}

void Node::setDescription(const std::string description){
    m_description = description;
}

void Node::setNbNeighbor(const int nbNeighbor){
    m_nbNeighbor = nbNeighbor;
}

std::string Node::getDescription() const{
    return m_description;
}

int Node::getNbNeighbor() const{
    return m_nbNeighbor;
}

void Node::printNode() const{
    std::cout << getDescription() << std::endl;
    std::cout << "Pour acceder au chapitre suivant, ecrivez " << m_idNeighbors[0] << "." << std::endl << std::endl;
}

void Node::setIdNeighbors(const std::vector<int> id){
    int i;
    for(i=0; i<getNbNeighbor(); ++i){
        m_idNeighbors.push_back(id[i]);
    }
}

std::vector<int> Node::getIdNeighbors(){
    return m_idNeighbors;
}

int Node::inTheNode(int choice){
    std::vector<int>::iterator it;
    it = std::find(m_idNeighbors.begin(), m_idNeighbors.end(), choice);
    if(it != m_idNeighbors.end()){
        return 1;
    }
    else{
        return 0;
    }
}


/***QUESTION NODE***/

QuestionNode::QuestionNode(std::string &information){
    std::string temp;
    std::istringstream iss(information);
    std::getline(iss, temp, ';'); //The first int is used in CreateNode and not here !
    std::getline(iss, temp, ';');
    setDescription(temp);
    std::getline(iss, temp, ';');
    setNbNeighbor(std::stoi(temp));
    for(int i = 0; i < getNbNeighbor(); ++i){
        std::getline(iss, temp, ';');
        m_questions.push_back(temp);
    }
    std::vector<int> neighbor;
    for(int i = 0; i < getNbNeighbor(); ++i){
        std::getline(iss, temp, ';');
        neighbor.push_back(std::stoi(temp));
    }
    setIdNeighbors(neighbor);
}


void QuestionNode::setQuestions(const std::string* questions){
    int i;
    for(i=0; i<getNbNeighbor(); ++i){
        m_questions.push_back(questions[i]);
    }
}

std::vector<std::string> QuestionNode::getQuestions(){
    return m_questions;
}

void QuestionNode::printNode() const{
    std::cout << getDescription() << std::endl;
    for(int i=0; i< getNbNeighbor(); ++i){
        std::cout << "     - " << m_questions[i] << std::endl;
    }
    std::cout << std::endl;
}









