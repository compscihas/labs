#include <iostream>
#include <cmath>
#include "./nth_root.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        try{
            nth_root(2, 1);}
        catch(...){}
        try{
            nth_root(0,7.5);}
        catch(...){}
        try{
            nth_root(2,-5);}
        catch(...){}
        try{
            nth_root(1,1);}
        catch(...){}
        try{
            nth_root(1,4);}
        catch(...){}
        try{
            nth_root(-1,0);}
        catch(...){}
        try{
            nth_root(-1,1);}
        catch(...){}
        try{
            nth_root(-1,10);}
        catch(...){}
        try{
            nth_root(-1,4.5);}
        catch(...){}
        try{
            nth_root(-2,2);}
        catch(...){}
        try{
            nth_root(-7,4);}
        catch(...){}
        try{
            nth_root(-7,1);}
        catch(...){}
        try{
            nth_root(-3,1);}
        catch(...){}
        try{
            nth_root(-3,4.5);}
        catch(...){}
        try{
            nth_root(7,1.5);}
        catch(...){}
        try{
            nth_root(7,4.5);}
        catch(...){}
        try{
            nth_root(5,1);}
        catch(...){}
        try{
            nth_root(5,1);}
        catch(...){}
        for(int i = -10; i<10; i++){
            for(int j = 0; j<10; j++){
                try{
                    nth_root(i,j);}
                catch(...){}
            }
        }
        
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
