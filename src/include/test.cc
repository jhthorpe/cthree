
#include <stdio.h>
#include "structs.h"

int main() {

  ccc::Data_List DATA; 
  ccc::Data Fai = {"F",{_CCC_VRT_,_CCC_OCC_}};
  ccc::Data Fij = {"F",{_CCC_OCC_,_CCC_OCC_}}; 
  ccc::Data Gabjc = {"G",{_CCC_VRT_,_CCC_VRT_,_CCC_OCC_,_CCC_VRT_}};

  //Add data to list and get references back
  DATA.reserve(10);
  DATA.add_if_unique(Fai);
  DATA.add_if_unique(Fij);
  /* The following is equivilant to adding Gabjc defined above */
  DATA.add_if_unique({"G",{_CCC_VRT_,_CCC_VRT_,_CCC_OCC_,_CCC_VRT_}});

  /* these will do nothing since Fai matches them */ 
  DATA.add_if_unique({"F",{_CCC_VRT_,_CCC_OCC_}}); 
  DATA.add_if_unique({"F",{_CCC_VRT_,_CCC_OCC_}});

  //testing print string
  printf("Full data set: \n");
  printf("%s\n",DATA.printf_string().c_str());

  //Find a reference within Data 
  // Note that if this reference doesn't exist, it will return one element beyond the 
  // actual end
  // 
  // THIS IS NOT THREAD SAFE!!
  // There is no gaurentee that the data you think XX points to actually exists where
  //    the XX data references.
  const ccc::Data& XX = DATA.cfind({"F",{_CCC_VRT_,_CCC_OCC_}});
  if (DATA.is_within_upper_bound(XX)) {
    printf("Found Fai! It was ...\n");
    printf("%s\n",XX.printf_string().c_str());
  } else {
    printf("We did not find Fai...\n");
  }

  bool ex = DATA.exists(Gabjc);
  if (ex) {
    printf("test exists in data\n");
  } else {
    printf("test does not exist\n");
  }

  return 0;
}
