 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
     
    vector<int> pipes {1005, 1497, 900 };
    vector<int> sizes {200,200,200,200,200,200,180,180,180,180,180,180};
    vector<int> pipeBuffer;
    vector<int> sizeBuffer;
    vector<int> pipeResult;
    vector<int> sizeResult;
    sort(pipes.begin(), pipes.end());
    sort(sizes.begin(), sizes.end());
    int garbageCount = 9000;
    do
    {
        do
        {
            auto size = sizes.begin();
            int length = 0;
            int garbge = 0;
            for (auto pipe : pipes)
            {
                pipeBuffer.push_back(pipe);
                while (size != sizes.end())
                {
                    if (*size + length <= pipe)
                    {
                        length += *size;
                        sizeBuffer.push_back(*size);
                        size++;
                    }
                    else
                    {
                        garbge += pipe - length;
                        length = 0;
                        break;
                    }
                }

                //MINIMIZE LAST PIPE
                garbge += pipe - length;
                
                if (size == sizes.end())
                {
                    
                    break;
                }
            }

            
            if (garbge <= garbageCount && length)
            {
                garbageCount = garbge;
                pipeResult = pipeBuffer;
                sizeResult = sizeBuffer;
                pipeBuffer.clear();
                sizeBuffer.clear();
            }
            else
            {
                pipeBuffer.clear();
                sizeBuffer.clear();
            }

        } while (next_permutation(sizes.begin(), sizes.end()));
    } while (next_permutation(pipes.begin(), pipes.end()));

    cout << "Pipe sizes ";
    for (auto pipe : pipeResult)
        cout << pipe << " ";

    cout << endl;

    cout << "Part sizes ";
    for (auto size : sizeResult)
        cout << size << " ";


}

 