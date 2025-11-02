#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>

using namespace std;
using namespace std::chrono;

const int NROWS = 4;
const int NCOLS = 3;
const int DEPTH = 2;

const int SAMPLERUNS = 15;

int main() {
    int nSampleRuns = 0;
    int olympicDataSet[DEPTH][NROWS][NCOLS];
    
    for (int i = 0; i < SAMPLERUNS; i++) {
        //opens the external file containing the codes we will be importing into our vector, list, and sets
        ifstream vFin("codes.txt");
        //using the chrono library, marks the starting time at which we start this code block 
        auto vStart1 = high_resolution_clock::now();

        //declares a vector of strings and populates the vector with the codes found in our text file, while the file is open
        vector<string> vTrip;
        string codes;
        while (getline(vFin, codes)) {
            vTrip.push_back(codes);
        }

        //using the chrono library, marks the time at which the program finishes populating the vector
        auto vEnd1 = high_resolution_clock::now();
        //calculates the time in microseconds by finding the ending and starting time of our code block
        auto vDuration1 = duration_cast<microseconds>(vEnd1 - vStart1);
        //closes the input file
        vFin.close();

        olympicDataSet[0][0][0] = vDuration1.count();
        olympicDataSet[1][0][0] += olympicDataSet[0][0][0];

        ifstream lFin("codes.txt");
        //using the chrono library, marks the starting time at which we start this code block 
        auto lStart1 = high_resolution_clock::now();
        //declares a list of strings and populates the list with the codes found in our text file, while the file is open
        list<string> lTrip;
        while (getline(lFin, codes)) {
            lTrip.push_back(codes);
        }

        //using the chrono library, marks the time at which the program finishes populating the list
        auto lEnd1 = high_resolution_clock::now();
        //calculates the time in microseconds by finding the ending and starting time of our code block
        auto lDuration1 = duration_cast<microseconds>(lEnd1 - lStart1);
        //closes the input file
        lFin.close();

        olympicDataSet[0][0][1] = lDuration1.count();
        olympicDataSet[1][0][1] += olympicDataSet[0][0][1];

        ifstream sFin("codes.txt");
        //using the chrono library, marks the starting time at which we start this code block 
        auto sStart1 = high_resolution_clock::now();

        //declares a set of strings and populates the set with the codes found in our text file, while the file is open
        set<string> sTrip;
        while (getline(sFin, codes)) {
            sTrip.insert(codes);
        }

        //using the chrono library, marks the time at which the program finishes populating the set
        auto sEnd1 = high_resolution_clock::now();
        //calculates the time in microseconds by finding the ending and starting time of our code block
        auto sDuration1 = duration_cast<microseconds>(sEnd1 - sStart1);
        //closes the input file
        sFin.close();

        olympicDataSet[0][0][2] = sDuration1.count();
        olympicDataSet[1][0][2] += olympicDataSet[0][0][2];

        //outputs the container types, as well as the time it took each of the code blocks to complete populating their containers
        cout << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set\n";
        cout << "Read" << setw(20) << vDuration1.count() << setw(16) << lDuration1.count() << setw(15) << sDuration1.count() << endl;
        
        auto vStart2 = high_resolution_clock::now();

        //calls the sort function, which automatically sorts the vector from the beginning to the end of the vector
        sort(vTrip.begin(), vTrip.end());

        auto vEnd2 = high_resolution_clock::now();
        auto vDuration2 = duration_cast<microseconds>(vEnd2 - vStart2);

        auto lStart2 = high_resolution_clock::now();

        //calls the sort() function which automatically sorts the list
        lTrip.sort();

        auto lEnd2 = high_resolution_clock::now();
        auto lDuration2 = duration_cast<microseconds>(lEnd2 - lStart2);

        //sets the duration to negative one, because the set already sorts itself without having to call a separate function
        int sDuration2 = -1;

        //outputs how quickly each class container can sort its contents
        cout << "Sort" << setw(20) << vDuration2.count() << setw(16) << lDuration2.count() << setw(15) << sDuration2 << endl;

        auto vStart3 = high_resolution_clock::now();

        //calls the insert function, which inputs the designated string into the middle of the vector
        vTrip.insert(vTrip.begin() + (vTrip.size()/2), "TESTCODE");

        auto vEnd3 = high_resolution_clock::now();
        auto vDuration3 = duration_cast<microseconds>(vEnd3 - vStart3);

        auto lStart3 = high_resolution_clock::now();

        //using an interator, we use the advance command to traverse the list until our dedired position within the list
        auto lIt = lTrip.begin();
        advance(lIt, (lTrip.size()/2)-1);
        //calls the insert function, which inputs the designated string into the location determined by the iterator
        lTrip.insert(lIt, "TESTCODE");

        auto lEnd3 = high_resolution_clock::now();
        auto lDuration3 = duration_cast<microseconds>(lEnd3 - lStart3);

        auto sStart3 = high_resolution_clock::now();

        //inputs the given string into the set
        sTrip.insert("TESTCODE");

        auto sEnd3 = high_resolution_clock::now();
        auto sDuration3 = duration_cast<microseconds>(sEnd3 - sStart3);

        //outputs how quickly each container could input a desired string into the middle of the vector and list and simply into the set as it automatically sorts the objects within the set
        cout << "Insert" << setw(17) << vDuration3.count() << setw(16) << lDuration3.count() << setw(15) << sDuration3.count() << endl;

        auto vStart4 = high_resolution_clock::now();

        //calls the erase function to delete the value at the designated location of the vector
        vTrip.erase(vTrip.begin() + (vTrip.size()/2));

        auto vEnd4 = high_resolution_clock::now();
        auto vDuration4 = duration_cast<microseconds>(vEnd4 - vStart4);

        auto lStart4 = high_resolution_clock::now();

        //using an iterator, we traverse to the desired location of the list using the advance function
        auto lIt2 = lTrip.begin();
        advance(lIt2, (lTrip.size()/2)-1);
        //calls the erase function, which deletes the value at the designated location of the list
        lTrip.erase(lIt2);

        auto lEnd4 = high_resolution_clock::now();
        auto lDuration4 = duration_cast<microseconds>(lEnd4 - lStart4);

        auto sStart4 = high_resolution_clock::now();

        //using an iterator, we traverse to the desired location of the set using the advance function
        auto sIt = sTrip.begin();
        advance(sIt, (sTrip.size()/2)-1);
        //calls the erase function, which deletes the value at the designated location of the set
        sTrip.erase(sIt);

        auto sEnd4 = high_resolution_clock::now();
        auto sDuration4 = duration_cast<microseconds>(sEnd4 - sStart4);

        //outputs how quickly each container can delete the value at the desired location
        cout << "Delete" << setw(17) << vDuration4.count() << setw(16) << lDuration4.count() << setw(15) << sDuration4.count() << endl;
    }
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/