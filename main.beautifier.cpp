//
// Compilation without OMP flags:
// g++ -O3 kmeans.beautifier.cpp kmeansplusplus.beautifier.cpp main.beautifier.cpp
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include "kmeans.beautifier.h"
#include "kmeansPlusPlus.beautifier.h"

int
main ()
{
  std::clock_t start;
  double duration;

  Kmeans kmeans (15);
  kmeans.InitPoints ("S1.txt");
  start = std::clock ();
  kmeans.InitCenters ();
  //kmeans.InitSpecifiedCenters();
  kmeans.RunKmean ();
  duration = (std::clock () - start) / (double) CLOCKS_PER_SEC;
  std::cout << "calculate time " << duration << std::endl;
  kmeans.SaveEPS ("S1.eps");

  std::cout << "----------------- kmeans Plus Plus -----------------" << std::
    endl;
  KmeansPlusPlus kmeansPlusPlus (15);
  kmeansPlusPlus.InitPoints ("S1.txt");
  start = std::clock ();
  kmeansPlusPlus.InitCenters ();
  //kmeans.InitSpecifiedCenters();
  kmeansPlusPlus.RunKmean ();
  duration = (std::clock () - start) / (double) CLOCKS_PER_SEC;
  std::cout << "calculate time " << duration << std::endl;
  kmeansPlusPlus.SaveEPS ("S1_++.eps");
  kmeansPlusPlus.SaveSVG ("S1_++.svg");
  //system("pause");
  return 1;
}
