/**
 * word_transform.cpp
 * The word transformation program, given a string, transform it into another.
 * Compilation: g++ -o word_transform word_transform.cpp -std=c++11
 * Created: 2015-09-20
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;
using std::runtime_error;

const string &
transform(const string &s, const map<string, string> &m);
map<string, string> buildMap(ifstream &map_file);
void word_transform(ifstream &map_file, ifstream &input);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Missing rules file and input file" << endl;
        return 1;
    }

    ifstream map_file(argv[1]);
    ifstream input(argv[2]);
    word_transform(map_file, input);
    map_file.close();
    input.close();

    return 0;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);   // store the transformations
    string text;                            // hold each line from input
    while (getline(input, text)) {          // read the line of input
        istringstream stream(text);         // read each word
        string word;
        bool firstword = true;              // controls whether a space is printed
        while (stream >> word) {
            if (firstword) {
                firstword = false;
            }
            else {
                cout << " ";                // print a space between words
            }
            // transformation returns its first arguments or its transformation
            cout << transform(word, trans_map); // print the output
        }
        cout << endl;                           // done with this line of input
    }
}

/* if a word appear multiple time, our loops will put the last corresponding
 * phrase into trans_map.
 */
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;      // holds the transformation
    string key;     // a word to transform
    string value;   // phrase to use instead
    // read the first word into key and the rest of the line into value
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {     // check that there is a transformation
            trans_map[key] = value.substr(1);   // skip leading space
        }
        else {
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m)
{
    // the actual map word; this part is the heart of the program
    auto map_it = m.find(s);
    // if this word is in the transformation map
    if (map_it != m.cend())
        return map_it->second;  // use the replacement word
    else
        return s;               // otherwise return the original unchanged
}
