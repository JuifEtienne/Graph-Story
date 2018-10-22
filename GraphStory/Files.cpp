/***
 * Functions which have an effect on my .txt files
 *
 * -fileToString transform the information of one on my file in a string
 * -isAStoryNode look at the first element of a string and look if it's the same than the one for Story Node
 *     => If a Node is a StoryNode, the file/String has a 1 for its first element
 * -storyToString transform all of my story in a vector of string
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Files.hpp"

std::string fileToString(const std::string filepath){
    std::ifstream m_read;
    m_read.open(filepath);


    std::string line;
    std::string res = "";
    if(m_read.is_open()){
        while( std::getline (m_read, line) ){
            res += line;
        }
    }
    else{
        return "";
    }

    m_read.close();
    return res;
}

int isAStoryNode(const std::string information){
    std::string temp;
    std::istringstream iss(information);
    std::getline(iss, temp, ';');
    int test = std::stoi(temp);
    if(test == 1){
        return 0;
    }
    else{
        return 1;
    }
}

std::vector<std::string> storyToString(int nbNode){
    int i;
    std::vector<std::string> information;
    for(i = 0; i < nbNode; i++){
        information.push_back(fileToString("../story/" + std::to_string(i) + ".txt"));
    }
    return information;
}