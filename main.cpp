#include "algorithms/binarysearch/binarysearch.h"
#include "algorithms/twopointers/twopointers.h"
#include "algorithms/slidingwindow/slidingwindow.h"
#include "algorithms/depthfirstsearch/depthfirstsearch.h"
#include "algorithms/backtracking/backtracking.h"
#include "algorithms/dynamicprogramming/dynamicprogramming.h"
#include "algorithms/bitmanipulation/bitmanipulation.h"
#include "algorithms/counting/counting.h"
#include "algorithms/divideandconquer/divideandconquer.h"
#include "datastructures/arrays/arrays.h"
#include "datastructures/strings/strings.h"
#include "datastructures/linkedlists/linkedlists.h"
#include "datastructures/stacks/stacks.h"
#include "datastructures/trees/trees.h"
#include "datastructures/hashmaps/hashmaps.h"

int main()
{
    DataStructures::Arrays::run();
    DataStructures::Strings::run();
    DataStructures::LinkedLists::run();
    DataStructures::Stacks::run();
    DataStructures::Trees::run();
    DataStructures::HashMaps::run();

    Algorithms::BinarySearch::run();
    Algorithms::TwoPointers::run();
    Algorithms::SlidingWindow::run();
    Algorithms::DepthFirstSearch::run();
    Algorithms::Backtracking::run();
    Algorithms::DynamicProgramming::run();
    Algorithms::BitManipulation::run();
    Algorithms::Counting::run();
    Algorithms::DivideAndConquer::run();

    return 1;
}