/* BraKet.h
   header file for the BraKet struct, which constains a list of
   the unique combinations of Bra/Ket mode excitations. Note that
   this requires C++14 or later 

   For instance, a <D| x |S> block has the following sets of unique
   excitation combinations:

   <1 1 0| , |1 0 0>
   <1 1 0| , |0 0 1>

    And all the other combinatios can be reduced to one of those
    two forms. 

    Currently, the code generates a single LHS state, then iterates
    through all RHS state permutations to find the unique ones. 

    A better implementation would be to just inspect every permutation as
    it is generated, but this is not a computationally expensive subroutine
    anyways 

*/ 

#ifndef BraKet_H
#define BraKet_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility> //for std::pair
#include <functional>

//BraKet <L| |R>
/* LX is the LHS excitation count
   RX is the RHS excitation count
*/

namespace cthree {

template<typename T, const int N>
using array_pair = std::pair<std::array<T,N>,std::array<T,N>>;

template<const int LX, const int RX>
struct BraKet {
 
  //vector of tuples of arrays of unique excitation 
  static constexpr int N = std::max(1,LX+RX); //this requires c++14
  std::vector<array_pair<int,N>> unique_types;
  std::vector<std::array<int,N>> unique_AND;
  
  static constexpr int total_excitation() {return LX + RX;}  
  static constexpr int num_unique_modes() {return N;}

  static constexpr int LHS_excitation() {return LX;}
  static constexpr int RHS_excitation() {return RX;}
  static constexpr int TOT_excitation() {return LX+RX;}

  void add_if_unique(const std::array<int,N>& LHS,
                     const std::array<int,N>& RHS);

  //Constructor
  BraKet();

};

/* initialize state array */
template<const int N, const int X>
void initialize_state(std::array<int,N>& state) {
  for (auto idx=0; idx < X; idx++) {
    state[idx] = 1;
  }
  for (auto idx=X; idx < state.size(); idx++) {
    state[idx] = 0;
  }
}

/* add to unique_types and unique_list if LHS and RHS has not been 
   seen before */
template<const int LX, const int RX>
void BraKet<LX,RX>::add_if_unique(const std::array<int,N>& LHS, 
                                  const std::array<int,N>& RHS) {
  std::array<int,N> AND;
  std::transform(LHS.begin(),LHS.end(),RHS.begin(),AND.begin(),std::equal_to<int>()); 
  std::sort(AND.begin(),AND.end());
  
  //add to existing types if it doesn't exist in the AND vector 
  if (std::find(unique_AND.begin(),unique_AND.end(),AND) == unique_AND.end() ) {
     unique_AND.push_back(AND); 
     unique_types.push_back(std::make_pair(LHS,RHS));
  }

}

/* Initailizer 
   Note that only a single LHS state is generated. All the
   rest can be determined from permutations of this one */

template<const int LX, const int RX>
BraKet<LX,RX>::BraKet() {

  //LHS and RHS temporary arrays
  std::array<int,N> LHS;
  std::array<int,N> RHS;

  //initialize states, sort
  initialize_state<N,LX>(LHS); std::sort(LHS.begin(),LHS.end());
  initialize_state<N,RX>(RHS); std::sort(RHS.begin(),RHS.end());

  //Go through permutations of RHS, and add if unique
  do {
    add_if_unique(LHS,RHS);      
  } while (std::next_permutation(RHS.begin(),RHS.end()));

  printf("At end of unique search version 2, we got the following: \n");
  for (int type=0;type<unique_types.size();type++) {
    printf("type #%d : ",type);
    for (auto const& i : unique_types[type].first) { printf(" %d",i); } printf(" | ");
    for (auto const& i : unique_types[type].second) { printf(" %d",i); } printf(" | ");
    for (auto const& i : unique_AND[type])  { printf(" %d",i); } printf(" \n");
  }
}

}//end cthree namespace

#endif
