#ifndef GRAPHSTORY_NODE_HPP
#define GRAPHSTORY_NODE_HPP



/* One mother class: Node
 * 1 daughter class: QuestionNode
 *
 * Node is a node which only has scenario and has only one neighbor. IF nbNeighbor == 0, it's an end for the story !
 * QuestionNode is a node which has scenario and (max) three questions so (max) three neighbors
 *
 *
 * In this file, there is :
 *      -class Node
 *      -class QuestionNode
 *
 */


class Node{
public:
    Node() = default;
    Node(std::string &information);
    ~Node() = default;

    void setDescription(const std::string description);
    void setNbNeighbor(const int nbNeighbor);
    void setIdNeighbors(const std::vector<int> id);

    std::string getDescription() const;
    int getNbNeighbor() const;
    std::vector<int> getIdNeighbors();

    virtual void printNode() const;
    int inTheNode(int choice);

    /*int & operator[](int i){
        if(i >= 0 && i < getNbNeighbor()){
            return m_idNeighbors[i];
        }
        else{
            throw std::string("Problem with the iterator");
        }
    }*/

private:
    std::string m_description;
    std::vector<int> m_idNeighbors;
    int m_nbNeighbor; //The number of Node which have an edge with this Node
};







class QuestionNode : public Node {
public:
    QuestionNode() = default;
    QuestionNode(std::string &information);
    ~QuestionNode() = default;

    void setQuestions(const std::string* questions);

    std::vector<std::string> getQuestions();

    void printNode() const override;

    //friend std::ostream &operator<<(std::ostream & os, const QuestionNode & qs);

private:
    std::vector<std::string> m_questions;
};



#endif //GRAPHSTORY_NODE_HPP
