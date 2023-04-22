#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void average()
{
    int amount, x, x_current;
    float final_average, total = 0, *arr;

    cout<<"Input the number of items: ";
    cin>>amount;

    arr =  new float[amount];

    for (x = 0; x < amount; x++)
    {
        x_current = x + 1;

        cout<<"Input "<<x_current<<": ";
        cin>>arr[x];

        total += arr[x];
    }
    
    cout<<"Your Input Values: ";

    for (x = 0; x < amount; x++)
    {
        cout<<arr[x]<<" ";
    }

    final_average = total/amount;

    cout<<endl<<"The average: "<<final_average<<endl;
    
    delete arr;
    cin.ignore();
}

void median()
{
    int amount, x, y = 0, x_current, current_buffer, index_lowest, index_buffer, median_even_1, median_even_2, median_odd, counter;
    float final_median, *arr, actual_median;

    cout<<"Input the number of items: ";
    cin>>amount;

    arr =  new float[amount];

    for (x = 0; x < amount; x++)
    {
        x_current = x + 1;

        cout<<"Input "<<x_current<<": ";
        cin>>arr[x];
    }
    /*sort*/
    for (x = 0; x < amount; x++)
    {
        current_buffer = arr[x];
        index_lowest = arr[x];
        counter = 0;

        for (y = x + 1; y < amount; y++)
        {
            if (index_lowest > arr[y])
            {
                index_lowest = arr[y];
                index_buffer = y;
                counter++;
            }
        }

        if (counter != 0)
        {
            arr[x] = index_lowest;
            arr[index_buffer] =  current_buffer;
        }
    }

    cout<<"Sorted Values: ";

    for (x = 0; x < amount; x++)
    {
        cout<<arr[x]<<" ";
    }

    if (amount % 2 == 0)
    {
        median_even_1 = (amount/2);
        median_even_2 = median_even_1 - 1;
        actual_median = (arr[median_even_1] + arr[median_even_2])/2;
    }
    else 
    {
        median_odd = (amount/2);
        actual_median = arr[median_odd];
    }
    cout<<endl<<"The median: "<<actual_median<<endl;
    cin.ignore();
}

void mode()
{
    int amount; 
    cout<<"Input the number of items: ";
}

void help()
{
    cout<<"mean/average"<<endl;
    cout<<"median"<<endl;
    cout<<"mode"<<endl;
}

void scanner(string str)
{
    if (str == "average" || str == "mean")
    {
        average();
    }
        else if (str == "help")
        {
            help();
        }
            else if (str == "median")
            {
                median();
            }
                else if (str == "mode")
                {
                    mode();
                }
}

// Driver code
int main()
{
    string str;

    while (true)
    {
        cout<<">>> ";
        getline(cin, str);
        if (str == "EXIT")
        {
            break;
        }
        else 
        {
            scanner(str);
        }
        
        cin.clear();
    }
    return EXIT_SUCCESS;
}
