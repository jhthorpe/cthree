/*
  nodes.h 
	JHT, December 24, 2022 : created

  .h file for the node structs. The data is organized as follows:

  A tree contains a set of branches 

  A branch contains an alternating set of operation nodes and data nodes, starting with a "result" node

  A data node has a name, indices, and pointers to the operation node above and below it

  An operation node has a name, indices, and pointers to the data nodes above and below it


  The indices in an operation are contained in a vector of pairs of an index type,
  the index type contains an index which tells us which data the index refers to 

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


struct Data_Node {
  std::string name;
  std::vector<_CCC_INDEX_T_> indices;

  //Equality comparison with another data node
  bool operator==(const Data_Node& rhs) const {
    return (name == rhs.name) && (indices == rhs.indices);
  };

  //returns the rank of the data, which trims out dummy indices
  //could probably be stored as a variable... but for a future day
  int rank() const {
    int r = 0;
    for (auto index : indices) {
      if (index != _CCC_DUM_) {r++;}
    }
    return r;
  } 

};

/* Typedefs for Index Map */
typedef std::pair<Data_Node&, int> Operation_Index;
typedef std::vector<std::array<Operation_Index,2>> Index_Map;

struct Operation_Node {
  std::string name;
  Index_Map index_map; 
};

/* 
  Node Data class
   contains pointers to other nodes, and a varient which contains either 
   a Data_Node or a Operation_Node. 
*/
struct Node {
  public:
  static constexpr std::array<char[10],2> type_names {"Data","Operation"};
  enum {DATA,OPERATION} type;

  std::shared_ptr<Node> parent;
  std::vector<std::shared_ptr<Node>> children;
  std::variant<Data_Node, Operation_Node> N;

  /* Constructors and Destructors */
  Node(Data_Node IN) {type = DATA; N = IN;} 
  Node(Operation_Node IN) {type = OPERATION; N = IN;} 

  //Get a std::string to print info about node
  std::string printf_string() const;
  std::string printf_data_string() const;
  std::string printf_operation_string() const;

  //function that returns const reference to node from an operation index 
  //const Node& node_from_index(const Operation_Index& OP) const; 

  /* specific getters */ 
  const CCC::Data_Node& data() const { return std::get<Data_Node>(N); }
  CCC::Data_Node& data() { return std::get<Data_Node>(N); }
  const CCC::Operation_Node& operation() const { return std::get<Operation_Node>(N); }
  CCC::Operation_Node& operation(){ return std::get<Operation_Node>(N); }
  
};


/*
  Node member functions
*/
std::string Node::printf_string() const {
  /*
  switch (type) {
    case Node::DATA      : return std::get<Data_Node>(N).printf_string(); 
    case Node::OPERATION : return std::get<Operation_Node>(N).printf_string(); 
  }
  */
  switch (type) {
    case Node::DATA      : return printf_data_string(); 
    case Node::OPERATION : return printf_operation_string(); 
  }
}

/*printing in case of Data_Node*/
std::string Node::printf_data_string() const {
  const Data_Node& data = std::get<Data_Node>(N);
  std::string str = "Data: " + data.name + " [";
  for (auto index : data.indices) {
    str += index;
  }
  str += "]"; 
  return str;
}

/*printing in case of Operation_Node*/
std::string Node::printf_operation_string() const {
  const Operation_Node& opr = std::get<Operation_Node>(N);
  std::string str = "Operation: "+ opr.name;
  str += " | Map: ";
  for (auto& index_pair : opr.index_map) {
    str += "("; 
    str += index_pair[0].first.name + "[" 
           + std::to_string(index_pair[0].second) + "]:"; 
    str += index_pair[1].first.name + "[" 
           + std::to_string(index_pair[1].second) + "]" ;
    
    str += ")";
  } 
  return str;
}

/*
  Data_Node member functions
*/
/*
std::string Data_Node::printf_string() const {
  std::string str = "Data: " + name + " [";
  for (auto index : indices) {
    str += index;
  }
  str += "]"; 
  return str;
}
*/

/*
  Operation_Node member functions
*/
/*
std::string Operation_Node::printf_string() const {
  std::string str = "Operation: "+ name;
  return str;
} 
*/

}; //end namespace CCC

#endif
