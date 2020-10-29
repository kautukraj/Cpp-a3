#include "DataSequence.h"
#include "FiveNumberSummary.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>

using namespace std;

int split_input(float* arr, int n, char str[]) // split comma separated numbers
{
    int count = 0;
    char * token = strtok(str, ","); // get the first token
    // loop through the string to extract all other tokens
    while( token != nullptr )
    {
        float num = atof(token); // convert string to float
        if (num <= 0)
        {
            return -1; // -1 if number is not valid
        }
        else
        {
            *(arr + count) = num; // store in the array
            count++;
        }
        token = strtok(nullptr, ","); // increment the token
    }
    return 1; // indicates success
}


int main()
{
    vector <DataSequence> DSVector;

    int choice = 0; int count = 0;

    while (choice != '\n')
    {
        choice = getchar();

        if (choice == 'N')
        {
            //cout << "N command" << endl;
            choice = getchar(); // comma
            int n; // the number n
            cin >> n;
            if (n == 0)
            {
                // do nothing
            }
            else
            {
                DataSequence temp (n); // temporary object
                DSVector.push_back(temp); // insert into vector

                choice = getchar(); // a space
                char nums[1000]; // comma separated numbers
                cin >> nums;
                //cout << nums << endl;

                float numbers[n];
                int f = split_input(numbers, n, nums);
                if (f == -1)
                {
                    cout << "-1\n";
                    break;
                }

                for (int i = 0; i < n; i++)
                {
                    //cout << numbers[i] << endl;
                    DSVector[count].setElement(numbers[i]); // insert numbers
                }

                count++;

            }
            choice = getchar();
            int dl; // the delimiter
            cin >> dl;
            choice = getchar(); // space after -1
        }

        else if (choice == 'A')
        {
            //cout << "A command" << endl;
            choice = getchar(); // comma
            int index;
            cin >> index;
            //cout << "Index = " << index << endl;
            choice = getchar(); // comma
            float value;
            cin >> value;
            //cout << "Value = " << value << endl;

            DSVector[index].setElement(value); // append at the end

            choice = getchar(); // space
            int dl;
            cin >> dl; // delimiter
            //cout << "Delimiter = " << dl << endl;
            choice = getchar(); // space after -1
        }
        else
        {
            //cout << "Anything else, now breaking" << endl;
            break;
        }

    }

    for (DataSequence dataSequence: DSVector)
    {
        dataSequence.sort();
        dataSequence.getFiveNumberSummary();
        dataSequence.makeHistogram();
    }


    return 0 ; // return success
}
