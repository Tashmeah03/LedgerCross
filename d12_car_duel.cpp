#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops) {
    int num_refills = 0;
    int current_pos = 0;  
    stops.push_back(dist); 
    int n = stops.size();

    int i = 0; 
    while (i < n) {
        int last_pos = current_pos;
        while (i < n && stops[i] - current_pos <= tank) {
            last_pos = stops[i];
            i++;
        }
        if (last_pos == current_pos) {
           
            return -1;
        }
        if (last_pos != dist) {
            num_refills++;
        }
        current_pos = last_pos;
    }

    return num_refills;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
