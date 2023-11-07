 

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string print(vector<int> vec)
{
    string buff;
    for (auto i : vec)
        buff += to_string(i);
    
    cout << buff << endl;
    return buff;
    
}





int main()
{
     
    vector<int> pipes{ 600, 708 };//{1005, 1497 };
    sort(pipes.begin(), pipes.end());
    vector<int> sizes{ 180,708 }; //{200,200,200,200,200,200,180,180,180,180,180,180};
    sort(sizes.begin(), sizes.end());
    int result = 0;
    do
    {
        for (auto pipe : pipes)
        {
            cout << pipe << " ";
        }
        cout << endl;
        do
        {

            auto size = sizes.begin();
            int length = 0;
            for (auto pipe : pipes)
            {
                while (size != sizes.end())
                {
                    if (*size + length <= pipe)
                    {
                        length += *size;
                        size++;
                    }
                    else
                    {
                        length = 0;
                        break;
                    }
                }
            }

            if ((pipes.back() - length) > result)
            {
                result = pipes.back() - length;
                for (auto size : sizes)
                {
                    cout << size << " - ";
                }

                cout << pipes.back() - length << endl;
            }

        } while (next_permutation(sizes.begin(), sizes.end()));
    } while (next_permutation(pipes.begin(), pipes.end()));

    

}

 