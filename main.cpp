#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>

#include "DSU.h"
#include "Utils.h"

using namespace std;
using namespace chrono;
using _time = chrono::time_point<chrono::system_clock>;

int main()
{
    DSU<int> set;

    set.MakeSet(1);
    set.MakeSet(7);
    set.MakeSet(11);

    cout << set.Find(7) << endl;
    cout << set << endl;
    cout << set.Find(3) << endl;
    cout << set << endl;

    set.Union(1, 7);
    set.Union(1, 11);
    cout << set << endl;

    set.Union(20, 11);
    cout << set << endl;

    /*srand(time(nullptr));
    
    for (size_t size = 200; size < 40000; size += 100) {

        DSU<int> set;

        //for (size_t i = 0; i < size; i++) {
        //    set.MakeSet((int)i);
        //}

        
        double min1 = 100000, max1 = 0, sum1 = 0;
        for (size_t i = 0; i < size * 2; i++) {
            _time  start1 = system_clock::now();
            int a = rand() % size, b = rand() % size;
            set.Union(a, b);
            _time  end1 = system_clock::now();

            double dt = duration<double>(end1 - start1).count();
            sum1 += dt;
            min1 = std::min(min1, dt);
            max1 = std::max(max1, dt);
        }
        

        double min2 = 100000, max2 = 0, sum2 = 0;
        for (size_t i = 0; i < (size / 10) * 7; i++) {
            _time  start2 = system_clock::now();
            size_t a = rand() % size;
            set.Find(a);
            _time  end2 = system_clock::now();

            double dt = duration<double>(end2 - start2).count();
            sum2 += dt;
            min2 = std::min(min2, dt);
            max2 = std::max(max2, dt);
        }
        

        cout << size << " " << (10e+5 * sum1 / (size * 2)) << " "
                            << (10e+5 * sum2 / ((size / 10) * 7)) << " "
                            << (10e+5 * min1 ) << " "
                            << (10e+5 * max1 ) << " "
                            << (10e+5 * min2 ) << " "
                            << (10e+5 * max2 ) << "\n";
    }*/
}