#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

int main() {
    // 1. std::vector & std::sort
    std::vector<int> scores = {88, 95, 72, 91, 84};
    std::cout << "--- std::vector & std::sort Demo ---\n";
    std::cout << "Original Scores: ";
    for (int s : scores) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    std::sort(scores.begin(), scores.end());
    std::cout << "Sorted Scores:   ";
    for (int s : scores) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    // 2. std::find algorithm
    int target = 91;
    auto it = std::find(scores.begin(), scores.end(), target);
    if (it != scores.end()) {
        std::cout << "Score " << target << " found in vector!\n";
    } else {
        std::cout << "Score " << target << " not found.\n";
    }

    // 3. std::map (Key-Value pairs)
    std::cout << "\n--- std::map (Roll No -> Name) Demo ---\n";
    std::map<int, std::string> students;
    students[101] = "Aarav";
    students[112] = "Pranav";
    students[105] = "Rohan";

    for (const auto& entry : students) {
        std::cout << "Roll No: " << entry.first << " | Name: " << entry.second << "\n";
    }

    return 0;
}