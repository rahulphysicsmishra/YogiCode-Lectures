// O(1) : Constant Time

#include <iostream>
#include <vector>

int main() {
	std::vector<int> arr = {1, 2, 3, 4};
	std::cout << arr[2]; // Accessing an element by index
	return 0;
}

// O(n) : Linear Time

int main() {
    std::vector<int> arr = {1, 2, 3, 4};
    for (int i = 0; i < arr.size(); i++) { // Looping through all elements
        std::cout << arr[i] << " ";
    }
    return 0;
}

// O(n^2) : Quadratic Time

int main() {
    std::vector<int> arr = {1, 2, 3, 4};
    for (int i = 0; i < arr.size(); i++) { // Nested loops
        for (int j = 0; j < arr.size(); j++) {
            std::cout << arr[i] + arr[j] << " ";
        }
    }
    return 0;
}


// O(log n) : Logarithmic Time

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int left = 0, right = arr.size() - 1;
    while (left <= right) { // Binary search
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            std::cout << "Found at index: " << mid;
            return 0;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    std::cout << "Not found";
    return 0;
}

// Example for O(1) Space Complexity

int main() {
    int a = 5, b = 10;
    int sum = a + b; // Using a constant amount of space
    std::cout << "Sum: " << sum;
    return 0;
}


// Example for O(n) Space Complexity

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> squared; // Using space proportional to input size
    for (int num : arr) {
        squared.push_back(num * num);
    }
    for (int sq : squared) {
        std::cout << sq << " ";
    }
    return 0;
}


// Example for O(n^2) Space Complexity

int main() {
    int n = 3;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n)); // Using space proportional to n^2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = i + j;
        }
    }
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

