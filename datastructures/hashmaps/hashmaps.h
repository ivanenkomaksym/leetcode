#include <vector>
#include <iostream>
#include <cassert>
#include "../../common/hashmap.h"

namespace DataStructures::HashMaps
{
    void run()
    {
        std::cout << "[DataStructures][HashMaps]  Start" << std::endl;

        {
            HashMap hashMap;
            hashMap.put(1, 100);
            hashMap.put(2, 200);
            assert(hashMap.get(1) == 100);
            assert(hashMap.get(3) == -1);
            hashMap.put(2, 300);
            assert(hashMap.get(2) == 300);
            hashMap.remove(2);
            assert(hashMap.get(2) == -1);

            std::cout << "  [PASSED] Implement basic Hash Map" << std::endl;
        }

        std::cout << "[DataStructures][HashMaps]  End" << std::endl;
    }
}