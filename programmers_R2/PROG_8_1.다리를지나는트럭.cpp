#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    vector<int> finish_truck;
    int total_truck = truck_weights.size();
    vector<pair<int, int>> road;

    while (finish_truck.size() != total_truck)
    {
        for (int i = 0; i < road.size(); i++)
        {
            cout << road[i].first << "," << road[i].second << "//";
        }
        cout << endl;
        answer += 1;
        if (!road.empty())
        {
            for (int i = 0; i < road.size(); i++)
            {
                road[i].second += 1;
            }

            if (road[0].second > bridge_length)
            {
                finish_truck.push_back(road[0].first);
                road.erase(road.begin());
            }
        }

        int on_road_truck_weight = 0;
        for (int i = 0; i < road.size(); i++)
        {
            on_road_truck_weight += road[i].first;
        }

        if (road.empty())
        {
            road.push_back(make_pair(truck_weights[0], 1));
            if (!truck_weights.empty())
            {
                truck_weights.erase(truck_weights.begin());
            }
        }
        else if (on_road_truck_weight <= weight)
        {
            road.push_back(make_pair(truck_weights[0], 1));
            if (!truck_weights.empty())
            {
                truck_weights.erase(truck_weights.begin());
            }
        }
    }

    return answer;
}

int main()
{
    int bridge_length1 = 2;
    int weight1 = 10;
    vector<int> truck_weights1{7, 4, 5, 6};

    int bridge_length2 = 100;
    int weight2 = 100;
    vector<int> truck_weights2{10};

    int bridge_length3 = 100;
    int weight3 = 100;
    vector<int> truck_weights3{10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

    cout << solution(bridge_length1, weight1, truck_weights1) << endl;
    // cout << solution(bridge_length2, weight2, truck_weights2) << endl;
    // cout << solution(bridge_length3, weight3, truck_weights3) << endl;
}
/*
        for (int i = 0; i < road.size(); i++)
        {
            cout << road[i].first << "," << road[i].second << "//";
        }
        cout << endl;
*/