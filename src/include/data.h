/* data.h
  September 22, 2022 : JHT, created

  Header file for the ccc::data struct, which contains information about a data type

*/

#ifndef _CCC_DATA_H_
#define _CCC_DATA_H_

#include <string>
#include <array>
#include <vector>

#include "typedef.h"

namespace ccc {

/* Data struct
   This contains the name of the data, and information 
   about it's index types.

   Note that the members are all const, so this must be
   list initialized
*/
struct Data {
  const std::string base_name;
  const std::vector<_CCC_OCCVRT_T_> index_types;
   
  //get a print string of this vector
  std::string printf_string() const;
  
  /*Potentially store infomration about permutations,
    cost to read, etc
  */   

  _CCC_INT_T_ num_index() const {return index_types.size();}

};

/* Return a string for printing info about this type */
std::string Data::printf_string() const {
  std::string str;
  str.append("Base Type : ");
  str.append(base_name);
  str.append("\n");
  str.append("Indices   : [");
  for (const auto& idx : index_types) {
    str.push_back(_CCC_LABELS_[idx]);
  }
  str.append("] \n");
  return str;
};


//Comparison operatior
bool operator==(const Data& first, const Data& second) {
  //Check they have the same MBE order:
  if (first.num_index() != second.num_index()) {
    return false;
  } else { 

    //check if they have the same name
    if (first.base_name != second.base_name) { return false; }
  
    //check their index types are the same
    auto&& f = first.index_types.begin();
    auto&& s = second.index_types.begin();
    while (f != first.index_types.end()) {
      if (f != s) return false; 
      ++f; ++s;
    };
  }
  return true;
    
}

}; //end ccc namespace

#endif
