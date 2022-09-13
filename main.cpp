#include "algorithms/binarysearch/binarysearch.h"
#include "algorithms/twopointers/twopointers.h"
#include "algorithms/slidingwindow/slidingwindow.h"
#include "algorithms/depthfirstsearch/depthfirstsearch.h"
#include "datastructures/arrays/arrays.h"
#include "datastructures/strings/strings.h"
#include "datastructures/linkedlists/linkedlists.h"
#include "datastructures/stacks/stacks.h"
#include "datastructures/trees/trees.h"

int main()
{
    DataStructures::Arrays::run();
    DataStructures::Strings::run();
    DataStructures::LinkedLists::run();
    DataStructures::Stacks::run();
    DataStructures::Trees::run();

    Algorithms::BinarySearch::run();
    Algorithms::TwoPointers::run();
    Algorithms::SlidingWindow::run();
    Algorithms::DepthFirstSearch::run();

    return 1;
}