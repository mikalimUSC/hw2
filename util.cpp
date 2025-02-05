#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords) {
    set<string> wordset;

    if (rawWords.size() < 2) {
        return wordset;
    } else {
        int startindex = 0;
        int substrlen = 0;
        string newword = "";
        int i = 0;
        
        while (i < rawWords.size()) {
            // cout<< "start of loop. rawWords is " << rawWords<<endl;
            
            if (rawWords[i] == ';' || rawWords[i] == '.' || rawWords[i] == ',' || 
                rawWords[i] == ':' || rawWords[i] == '\'') {
                
                substrlen = i - startindex;
                // cout << "substrlen is " << substrlen << ", startindex is " << startindex << endl;
                newword = rawWords.substr(startindex, substrlen);
                // cout << "newword is " << newword << endl;
                
                if (newword.size() >= 2) {
                    wordset.insert(newword);
                }
                
                startindex = i + 1; // Move startindex to the character after punctuation
            }
            
            if (i == rawWords.size() - 1 && rawWords.size() >= 2) {
                newword = rawWords.substr(startindex); // Capture the last word
                // cout << "last word is " << newword << endl;
                
                if (newword.size() >= 2) {
                    wordset.insert(newword);
                }
            }
            
            i++;
        }
    }
    
    return wordset;
}



/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
