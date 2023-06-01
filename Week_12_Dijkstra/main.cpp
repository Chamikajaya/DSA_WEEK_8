#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<int>>& adj_matrix, int source) {
    int num_vertices = adj_matrix.size();

    vector<int> shortest_distances(num_vertices, INT_MAX);
    shortest_distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int curr_distance = pq.top().first;
        int min_node = pq.top().second;
        pq.pop();

        for (int neighbour = 0; neighbour < num_vertices; ++neighbour) {
            int weight = adj_matrix[min_node][neighbour];
            if (weight > 0) {
                int new_distance = curr_distance + weight;

                if (shortest_distances[neighbour] > new_distance) {
                    pq.push(make_pair(new_distance, neighbour));
                    shortest_distances[neighbour] = new_distance;
                }
            }
        }
    }

    return shortest_distances;
}

int main() {
    vector<vector<int>> adj_matrix = {
            {0, 10, 0, 0, 15, 5},
            {10, 0, 10, 30, 0, 0},
            {0, 10, 0, 12, 5, 0},
            {0, 30, 12, 0, 0, 20},
            {15, 0, 5, 0, 0, 0},
            {5, 0, 0, 20, 0, 0}
    };

    vector<int> avg_times;
    for (int i = 0; i < 6; ++i) {
        cout << "When the source node is " << i << " ->" << endl;
        vector<int> shortest = dijkstra(adj_matrix, i);
        for (int j = 0; j < shortest.size(); ++j) {
            cout << "Shortest distance to node " << j << " is " << shortest[j] << endl;
        }

        int sum = 0;
        for (int distance : shortest) {
            sum += distance;
        }
        double avg_time_taken = static_cast<double>(sum) / 5.0;
        cout << "Average time when source is " << i << " is " << avg_time_taken << endl;
        avg_times.push_back(avg_time_taken);
        cout << endl;
    }

    vector<int> best_choices;
    double min_time = INT_MAX;
    for (int city = 0; city < avg_times.size(); ++city) {
        if (avg_times[city] < min_time) {
            min_time = avg_times[city];
        }
    }
    for (int city = 0; city < avg_times.size(); ++city) {
        if (avg_times[city] == min_time) {
            best_choices.push_back(city);
        }
    }

    cout << "The most suitable city(s) to build the hospital is/are -> ";
    for (int i = 0; i < best_choices.size(); ++i) {
        cout << best_choices[i] << " ";
    }
    cout << endl;

    return 0;
}
