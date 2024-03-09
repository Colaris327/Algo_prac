#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "input: ";
    // example: 4 19 10
    // 2 3 5 7 8 11 13 14 16 18
    int distance, total_length, station_num;
    cin >> distance >> total_length >> station_num;

    vector<int> station_position;
    int temp;
    while (station_num--)
    {
        cin >> temp;
        station_position.push_back(temp);
    }
    station_position.push_back(INT_MAX);

    int current = 0;
    for (int i = 0; i != station_position.size(); i++)
    {
        if ((current + distance >= station_position[i]) && (current + distance < station_position[i + 1]))
        {
            cout << "stop at " << station_position[i] << endl;
            current = station_position[i];
        }
    }

    return 0;
}