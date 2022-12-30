/*
  nodes.h 
	JHT, December 24, 2022 : created

  .h file for the node structs. The data is organized as follows:

  A tree contains a set of branches 

  A branch contains an alternating set of operation nodes and data nodes, starting with a "result" node

  A data node has a name, indices, and pointers to the operation node above and below it

  An operation node has a name, indices, and pointers to the data nodes above and below it

*/

#ifndef _CCC_NODES_H_
#define _CCC_NODES_H_

#include "typedef.h"
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <variant>

namespace CCC {

struct index_pair {
  _CCC_INDEX_T_ parent;
  _CCC_INDEX_T_ child;
};

struct Data_Node {
  std::string name;
  std::vector<_CCC_INDEX_T_> indices;

  ~Data_Node() {
    printf("in data node destructor....\n");
  }

  std::string printf_string() const;
};

struct Operation_Node {
  std::string name;
  //std::vector<index_pair> index_map; 

  /*utilities*/
  std::string printf_string() const;
};

/* 
  Node Data class
   contains pointers to other nodes, and 
   a union structure N which is either a Data_Node 
   or a Operation_Node
*/
struct Node {
  public:
  static constexpr std::array<char[10],2> type_names {"Data","Operation"};
  enum {DATA,OPERATION} type;

  std::shared_ptr<Node> parents;
  std::vector<std::shared_ptr<Node>> children;

//  std::variant<Data_Node, Operation_Node> data, operation;

/*
  union {
    Data_Node data;
    Operation_Node operation;
  };
*/

  /* Constructors and Destructors */
  //Node(Data_Node IN) {type = DATA;  data = IN;}
  Node(Data_Node IN) {type = DATA; printf("made as data\n");} 
  //Node(Operation_Node IN) {type = OPERATION; operation = IN;}
  Node(Operation_Node IN) {type = OPERATION; printf("made as opr\n"); } 
  ~Node() {
    printf("at destructor...\n");
//    data.~Data_Node();
/*
    switch (type) {
      case DATA : printf("about to call des? %s \n",data.printf_string().c_str()); data.~Data_Node(); break;//data.~Data_Node(); break; 
      case OPERATION : printf("ffffffff"); break;//operation.~Operation_Node(); break;
      default : printf("at exit...\n"); exit(1); break; 
    } 
    */
    printf("now we here\n");
  }

  std::string printf_string() const;
};

/*
Node make_data_node(const std::string& name, 
                    const std::vector<_CCC_INDEX_T_>& indices) {
  Data_Node data = {name,indices};
  Node node(data);
  return node; 
};
*/

struct Branch {
  std::string name;
  //Data_Node result;

  std::string printf_string() const;
};

struct Tree {
  std::string name;
  std::vector<Branch> branches;

  std::string printf_string() const; 
};

/* printing operations */
std::string Tree::printf_string() const {
  std::string str = "Tree: " + name;
  return str; 
}

std::string Branch::printf_string() const {
  std::string str = "Branch: " + name;
  return str;
}

std::string Node::printf_string() const {
  switch (type) {
    case Node::DATA      : return data.printf_string() ;
    case Node::OPERATION : return operation.printf_string();
  }
}

std::string Data_Node::printf_string() const {
  std::string str = "DATTTTAAAA";
  return str;
/*
  std::string str = "Data: " + name + "["; 
  for (auto index : indices) {
    str += _CCC_LABELS_[index]; 
  }
  str += "]";
  return str;
*/
}

std::string Operation_Node::printf_string() const {
  std::string str = "OPERRRR";
  return str;
/*
  std::string str = "Operation: " + name;
  str += "[";
  for (auto& pair : index_map) {
    str.push_back(_CCC_LABELS_[pair.parent]);
    str.push_back('-');
    str.push_back(_CCC_LABELS_[pair.child]);
//    str += _CCC_LABELS_[pair.parent] + "-" + _CCC_LABELS_[pair.child];
  }
  str += "]";
  return str;
  */
} 

}; //end namespace CCC

#endif
