#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> routes = {
        "Moscow-Berlin",
        "Berlin-Paris",
        "Paris-Rome",
        "Rome-Moscow"
    };

    auto ptrRoutes = make_shared<vector<string>>(routes);

    auto countCity = [](const shared_ptr<vector<string>>& routesPtr, const string& city) {
        int count = 0;
        for (const auto& route : *routesPtr) {
            if (route.find(city) != string::npos) {
                count++;
            }
        }
        return count;
    };

    auto sortByLength = [](shared_ptr<vector<string>>& routesPtr) {
        sort(routesPtr->begin(), routesPtr->end(),
            [](const string& a, const string& b) {
                return a.length() > b.length();
            });
    };

    auto concat = [](const shared_ptr<vector<string>>& routesPtr) {
        string result;
        for (size_t i = 0; i < routesPtr->size(); ++i) {
            result += (*routesPtr)[i];
            if (i != routesPtr->size() - 1) {
                result += " -> ";
            }
        }
        return result;
    };

    int parisCount = countCity(ptrRoutes, "Paris");
    cout << "Количество маршрутов с \"Paris\": " << parisCount << endl;

    sortByLength(ptrRoutes);
    
    cout << "Отсортированные маршруты:" << endl;
    for (const auto& route : *ptrRoutes) {
        cout << route << endl;
    }

    string combinedRoute = concat(ptrRoutes);
    cout << "\nОбщий маршрут:" << endl;
    cout << combinedRoute << endl;

    return 0;
}