// lecture 12 : how sorting simplifies complex array problem

/*  
Problem : “Sort People by Height”
You’re given a list of people and their heights. Your task is to sort them 
so the tallest person comes first and the shortest comes last.

For example:
Names:   ["Anita", "Rahul", "Sneha", "Kabir", "Tina"]
Heights(cm): [160,     175,     150,     180,    165]
*/

// Manual sorting(selection sort) approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names = {"Anita", "Rahul", "Sneha", "Kabir", "Tina"};
    vector<int> heights = {160, 175, 150, 180, 165};

    int n = names.size();

    // Step 1: Combine names and heights into a vector of pairs
    vector<pair<int, string>> people;
    for (int i = 0; i < n; i++) {
        people.push_back({heights[i], names[i]});
    }

    // Step 2: Selection Sort (descending by height)
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (people[j].first > people[maxIndex].first) {
                maxIndex = j;
            }
        }
        swap(people[i], people[maxIndex]);
    }

    // Step 3: Print sorted names
    cout << "Sorted people by height:\n";
    for (auto p : people) {
        cout << p.second << " (" << p.first << ")\n";
    }

    return 0;
}


// Efficient Approach: Using STL sort
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names = {"Anita", "Rahul", "Sneha", "Kabir", "Tina"};
    vector<int> heights = {160, 175, 150, 180, 165};

    int n = names.size();

    vector<pair<int, string>> people;
    for (int i = 0; i < n; i++) {
        people.push_back({heights[i], names[i]});
    }

    // Sort using built-in sort (descending by height)
    sort(people.begin(), people.end(), [](pair<int, string> a, pair<int, string> b) {
        return a.first > b.first;
    });

    // Print sorted people
    cout << "Sorted people by height:\n";
    for (auto p : people) {
        cout << p.second << " (" << p.first << ")\n";
    }

    return 0;
}