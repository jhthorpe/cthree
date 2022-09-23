
#include <stdio.h>
#include "structs.h"

int main() {

//  ccc::Data_List DATA; 
  
  ccc::Data Fai   = {"F", {_CCC_VRT_,_CCC_OCC_}};
  ccc::Data Fij   = {"F", {_CCC_OCC_,_CCC_OCC_}};
  ccc::Data Gabjc = {"G", {_CCC_VRT_,_CCC_VRT_,_CCC_OCC_,_CCC_VRT_}};

  printf("%s \n",Fai.printf_string().c_str());
  printf("%s \n",Fij.printf_string().c_str());
  printf("%s \n",Gabjc.printf_string().c_str());

  (Fai == Gabjc) ? printf("Fai, Gabjc are same \n") : printf("Not same \n");
  (Fai == Fai) ? printf("Fai, Fai are same \n") : printf("Not same \n");
  (Fai == Fij) ? printf("Fai, Fij are same \n") : printf("Not same \n");


  return 0;
}
