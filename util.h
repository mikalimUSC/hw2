#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>



using namespace std;
/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

 
    typename std::set<T>::iterator i;
    std::set<T> output;
    std::set<T>* greater = &s1;
    std::set<T>* lesser = &s2;


    if (s1.size() <s2.size()){
        greater = &s2;
        lesser = &s1;
    }


    i = greater->begin();
    while(i != greater->end()){
        if(output.size() >= lesser->size()){
            break;
        }
        if(lesser->find(*i) != lesser->end()){
            output.insert(*i);
        }
        i++;
    }
    return output;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    typename std::set<T>::iterator i;
    std::set<T> output;

    i = s1.begin();
    while(i!=s1.end()){
        output.insert(*i);
        i++;
    }
    i = s2.begin();
     while(i!=s2.end()){
        output.insert(*i);
        i++;
    }

    return output;
    
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
