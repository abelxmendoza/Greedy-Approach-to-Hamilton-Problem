# Project 1 
# CS 335 Algorithms Engineering
# Dr. Sampson Akwafuo 
# Written by Abel Mendoza


#Greedy Approach to Hamilton Problem


# Function to find the preferred starting city given the city distances, fuel available at each city, and the car's MPG
def find_starting_city(city_distances, fuel, mpg):
    
    # Find the total number of cities
    num_cities = len(city_distances)
    
    # Find the minimum amount of fuel required to complete the circular journey 
    # This is the sum of all distances divided by the MPG
    min_fuel_required = sum(city_distances) / mpg
    
    # If the total fuel available is less than the minimum fuel required, return -1 since the journey is impossible
    if sum(fuel) < min_fuel_required:
        return -1
    
    # Otherwise, iterate over each city and attempt to start from that city
    for start_city in range(num_cities):
        
        # Assume starting from this city is possible
        possible_start = True
        
        # Initialize the fuel tank to be empty
        fuel_tank = 0
        
        # Iterate over each city starting from the current starting city
        for i in range(start_city, start_city+num_cities):
            
            # Calculate the index of the current city (taking into account the circular nature of the journey)
            city_index = i % num_cities
            
            # Add the fuel available at the current city to the fuel tank
            fuel_tank += fuel[city_index]
            
            # Calculate the distance to the next city
            next_city_distance = city_distances[city_index]
            
            # Calculate the fuel required to travel to the next city
            fuel_required = next_city_distance / mpg
            
            # If the fuel in the tank is less than the fuel required, starting from this city is not possible
            if fuel_tank < fuel_required:
                possible_start = False
                break
            
            # Otherwise, subtract the fuel required to travel to the next city from the fuel tank
            fuel_tank -= fuel_required
        
        # If starting from this city is possible, return the index of this city as the preferred starting city
        if possible_start:
            return start_city
    
    # If no starting city is found, return -1
    return -1

# Example usage
city_distances = [5, 25, 15, 10, 15]
fuel = [1, 2, 1, 0, 3]
mpg = 10

preferred_starting_city = find_starting_city(city_distances, fuel, mpg)

# Print the result
print("preferred starting city for the sample above is city: ", preferred_starting_city)

# Output: 4

