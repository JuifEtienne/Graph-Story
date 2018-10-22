#ifndef GRAPHSTORY_GRAPH_HPP
#define GRAPHSTORY_GRAPH_HPP

/*In this file, there is the Graph Class.
 *There are the getter and the setter. And a method to delete the elements of the vector of Node*.
 *
 * I have a std::vector<Node*> because I use polymorphism !
 * CurrentNode is here to know where the player is in the graph.
 */

class Graph{
public:
    Graph() = default;
    Graph(std::vector<std::string> &information);

    void setNbNode(const int nbNode);
    void setCurrentNode(const int currentNode);

    int getNbNode() const;
    int getCurrentNode() const;

    int getNbNeighbor() const;
    void printCurrentNode() const;
    int isANextNode(int choice) const;
    void printDescription() const;

    //void printIdNeighbor() const; //For the debug

    /*Node* & operator[](int i){
        if(i >= 0 && i < m_nbNode){
            return m_vecNode[i];
        }
        else{
            throw std::string("Problem with the iterator");
        }
    }*/

    void freeVect();

private:
    std::vector<Node *> m_vecNode;
    int m_nbNode;
    int m_currentNode;
};

#endif //GRAPHSTORY_GRAPH_HPP
