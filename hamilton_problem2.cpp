#include <iostream>
#include <vector>
using namespace std;

// Function to find the preferred starting city given the city distances, fuel available at each city, and the car's MPG
int find_starting_city(vector<int>& city_distances, vector<int>& fuel, int mpg) {
    
    // Find the total number of cities
    int num_cities = city_distances.size();
    
    // Find the minimum amount of fuel required to complete the circular journey 
    // This is the sum of all distances divided by the MPG
    double min_fuel_required = accumulate(city_distances.begin(), city_distances.end(), 0) / static_cast<double>(mpg);
    
    // If the total fuel available is less than the minimum fuel required, return -1 since the journey is impossible
    if (accumulate(fuel.begin(), fuel.end(), 0) < min_fuel_required) {
        return -1;
    }
    
    // Otherwise, iterate over each city and attempt to start from that city
    for (int start_city = 0; start_city < num_cities; start_city++) {
        
        // Assume starting from this city is possible
        bool possible_start = true;
        
        // Initialize the fuel tank to be empty
        double fuel_tank = 0;
        
        // Iterate over each city starting from the current starting city
        for (int i = start_city; i < start_city+num_cities; i++) {
            
            // Calculate the index of the current city (taking into account the circular nature of the journey)
            int city_index = i % num_cities;
            
            // Add the fuel available at the current city to the fuel tank
            fuel_tank += fuel[city_index];
            
            // Calculate the distance to the next city
            int next_city_distance = city_distances[city_index];
            
            // Calculate the fuel required to travel to the next city
            double fuel_required = static_cast<double>(next_city_distance) / static_cast<double>(mpg);
            
            // If the fuel in the tank is less than the fuel required, starting from this city is not possible
            if (fuel_tank < fuel_required) {
                possible_start = false;
                break;
            }
            
            // Otherwise, subtract the fuel required to travel to the next city from the fuel tank
            fuel_tank -= fuel_required;
        }
        
        // If starting from this city is possible, return the index of this city as the preferred starting city
        if (possible_start) {
            return start_city;
        }
    }
    
    // If no starting city is found, return -1
    return -1;
}

int main() {
    // Example usage
    vector<int> city_distances = {5, 25, 15, 10, 15};
    vector<int> fuel = {1, 2, 1, 0, 3};
    int mpg = 10;

    int preferred_starting_city = find_starting_city(city_distances, fuel, mpg);

    // Print the result
    cout << "Preferred starting city for the sample above is city: " << preferred_starting_city << endl;

    // Output: 4
    return 0;
}
