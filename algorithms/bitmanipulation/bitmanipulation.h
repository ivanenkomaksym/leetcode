#include <cstdint>
using namespace std;

namespace Algorithms::BitManipulation
{
    /*
    231. Power of Two
    Easy

    Given an integer n, return true if it is a power of two. Otherwise, return false.

    An integer n is a power of two, if there exists an integer x such that n == 2x.

    Example 1:

    Input: n = 1
    Output: true
    Explanation: 20 = 1
    */
    bool isPowerOfTwo(int n) {  
        if (n <= 0)
            return false;
        
        return (n & (n - 1)) == 0;
    }

    /*
    191. Number of 1 Bits
    Easy

    Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

    Note:

        Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
        In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

    

    Example 1:

    Input: n = 00000000000000000000000000001011
    Output: 3
    Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
    */
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n)
        {
            n = n & (n - 1);
            count++;
        }
        
        return count;
    }

    /*
    190. Reverse Bits
    Easy

    Reverse bits of a given 32 bits unsigned integer.

    Note:

        Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
        In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

    

    Example 1:

    Input: n = 00000010100101000001111010011100
    Output:    964176192 (00111001011110000010100101000000)
    Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
    */
    uint32_t reverseBits(uint32_t n) {
        unsigned int rev = 0;
        for (auto i = 0; i < 32; i++) 
        {
            rev <<= 1;
                
            if (n & 1 == 1)
                rev ^= 1;
                
            n >>= 1;
        }
        return rev;
    }

    /*
    136. Single Number
    Easy

    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:

    Input: nums = [2,2,1]
    Output: 1
    */
    int singleNumber(vector<int>& nums) {
       int ans = 0;
	   for(auto x:nums)
          ans ^= x;
	   return ans;
    }

    void run()
    {
        std::cout << "[Algorithms][BitManipulation]  Start" << std::endl;

        {
            auto result = isPowerOfTwo(16);

            assert(result == true);

            std::cout << "  [PASSED] 231. Power of Two" << std::endl;
        }
        
        {
            auto result = hammingWeight(11);

            assert(result == 3);

            std::cout << "  [PASSED] 191. Number of 1 Bits" << std::endl;
        }
        
        {
            auto result = reverseBits(43261596);

            assert(result == 964176192);

            std::cout << "  [PASSED] 190. Reverse Bits" << std::endl;
        }
        
        {
            auto v = std::vector<int>{2,2,1};
            auto result = singleNumber(v);

            assert(result == 1);

            std::cout << "  [PASSED] 136. Single Number" << std::endl;
        }

        std::cout << "[Algorithms][BitManipulation]  End" << std::endl;
    }
}