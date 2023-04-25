#include <iostream>
#include <cstdlib>
#include <string>

using namespace std; 

/* input for the number of values */
int array_length_query()
{
    int arr_length;
    
    cout<<"Input the number of values: ";
    cin>>arr_length;
    cin.ignore();
    
    return arr_length;
}

/* individual items input */
float* array_items_query(int arr_length)
{
    float* arr;
    int x, x_up_1; 
    arr = new float[arr_length];

    for (x = 0; x < arr_length; x++)
    {
        x_up_1 = x + 1;

        cout<<"Input item no."<<x_up_1<<": ";
        cin>>arr[x];
    }

    cin.ignore();

    return arr;
    delete arr;
}

/* sections a long string into words and returns a string(boolean)*/
string section(string str)
{
    string word, inputted_strings[6], result="FFFFFF";
    int y = 0, x = 0;

    for (auto x : str)
    {
        if (x == ' ')
        {
            inputted_strings[y] = word;
            y++;
            word = "";
        }
            else
            {
                word += x;
            } 
    }
    inputted_strings[y] = word;
    word = "";

    for (x = 0; x < 6; x++)
    {
        if (inputted_strings[x] == "average" || inputted_strings[x] == "mean")
        {
            result[0] = 'T';
        }
            else if (inputted_strings[x] == "median")
            {
                result[1] = 'T';
            }
                else if (inputted_strings[x] == "mode")
                {
                    result[2] = 'T';
                }
                    else if (inputted_strings[x] == "help")
                    {
                        result[3] = 'T';
                    }
                        else if (inputted_strings[x] == "clear")
                        {
                            result[4] = 'T';
                        }
                            else if (inputted_strings[x] == "EXIT")
                            {
                                result[5] = 'T';
                            }
    }

    return result;
}

void enter_to_continue()
{
    string wait;

    cout<<"Press Enter to continue: ";
    getline(cin, wait);
}

void median(float arr[], int arr_length)
{
    float actual_median;
    int x;

    if (arr_length % 2 == 0)
    {
        actual_median = (arr[arr_length/2] + arr[(arr_length/2)-1])/2;
    }
        else 
        {
            actual_median = arr[arr_length/2];
        }

    cout<<"Sorted values: ";

    for (x = 0; x < arr_length; x++)
    {
        cout<<arr[x]<<" ";
    }

    cout<<endl<<"The median: "<<actual_median<<endl<<endl;
}

void mode(float arr[], int arr_length)
{
    float *arr_2, *arr_3;
    int x, y, amount = 0, count = 0, mode; 
    bool isDuplicate;

    arr_2 = new float[arr_length];
    arr_3 = new float[arr_length];

    for (x = 0; x < arr_length; x++)
    {
        arr_3[x] = 0;
    }

    for (x = 0; x < arr_length; x++)
    {
        isDuplicate = false;
        for (y = 0; y  < amount; y++)
        {
            if (arr[x] == arr[y])
            {
                isDuplicate = true;
                arr_3[count - 1]++;
            }
        }

        if (!isDuplicate)
        {
            arr_2[count] = arr[x];
            arr_3[count]++;
            count++;
        }
        amount++;
    }

    for (x = 0; x < count; x++)
    {
        cout<<arr_2[x]<<" - "<<arr_3[x]<<endl;
    }
    
    mode = arr_3[0];

    for (x = 0; x < count; x++)
    {
        if (mode < arr_3[x])
        {
            mode = arr_3[x];
        }
    }

    cout<<endl<<"The mode/modes are the value/values ";

    for (x = 0; x < count; x++)
    {
        if (mode == arr_3[x])
        {
            cout<<arr_2[x]<<" ";
        }
    }

    cout<<"with "<<mode<<" repetition/repetitions"<<endl<<endl;

    delete arr_2, delete arr_3;
}

int main()
{
    string shell_input, available_commands[] = {"mean", "average", "median", "mode", "EXIT", "clear"}, result;
    int arr_length, x, y, counter = 0, index_buffer;
    float *arr, *arr_2, *arr_3, total, average, current_buffer, index_lowest;

    cout<<"Welcome to QuikS, a CLI program calculator for simple descriptive statistics the available commands are the following: "<<endl<<endl;
    cout<<"clear EXIT help mean/average median mode"<<endl<<endl;
    cout<<"if at any point you need a reminder of the commands type help and press enter"<<endl;
    cout<<"note: you can combine different commands to run them right after the other. Example: "<<endl;
    cout<<">>> average median"<<endl<<endl;
    
    /* main looping section */
    while (true)
    {
        cin.clear();
        cout<<">>> ";
        getline(cin, shell_input);
        result = section(shell_input);

        /* checking if any descriptive statistics is being done */
        if (result[0] == 'T' || result[1] == 'T' || result[2] == 'T')
        {
            arr_length = array_length_query();
            arr = new float[arr_length];
            arr = array_items_query(arr_length);
        }
        /* preparing sorted values for median and/or mode */
        if (result[1] == 'T' || result[2] == 'T')
        {
            for (x = 0; x < arr_length; x++)
            {
                current_buffer = arr[x];
                index_lowest = arr[x];
                counter = 0;

                for (y = x + 1; y < arr_length; y++)
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
                    arr[index_buffer] = current_buffer;
                }
            }
        }

        /* checking the input */
        if (result[0] == 'T') /* mean */
        {
            for (x = 0; x < arr_length;  x++)
            {
                total += arr[x];
            }

            average = total/arr_length;

            cout<<endl<<"The average is "<<average<<endl<<endl;
        }   
        if (result[1] == 'T') /* median */
        {
            median(arr, arr_length);
        }
        if (result[2] == 'T') /* mode */
        {
            mode(arr, arr_length);
        }
        if (result[3] == 'T') /* help */
        {
            cout<<endl<<endl;
            cout<<"Commands: average clear EXIT help mean median mode"<<endl;
        }
        if (result[4] == 'T') /* clear */
        {
            enter_to_continue();

            cout<<"\x1B[2J\x1B[H";
        }
        if (result[5] == 'T') /* EXIT */
        {
            enter_to_continue();            
            break;
        }
    }

    delete arr, arr_2, arr_3;
    return EXIT_SUCCESS;
}
