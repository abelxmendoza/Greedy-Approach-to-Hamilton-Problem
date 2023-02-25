Greedy Approach to Hamilton Problem

This repository contains a Python implementation of an algorithm to solve the "Hamilton Problem" for a set of cities that are laid out in a circle, connected by a circular road that runs clockwise.
Problem Statement

Each city has a gas station that provides gallons of fuel, and the distances between these cities are known. You have a car that can drive some number of miles per gallon of fuel, and your goal is to pick a starting city such that you can fill up your car in that city (using that city’s gas station). You can then drive to the next city, refill up your car with that city's fuel, drive to the next city, and so on and so forth until you return back to the starting city with 0 or more gallons of fuel left. This city is called a preferred starting city. In this problem, it is guaranteed that there will always be exactly one valid starting city.
Usage

To use this algorithm, follow these steps:

    Clone this repository to your local machine using git clone.
    Open a terminal window and navigate to the directory containing the cloned repository.
    Run the following command to execute the Python program:

python hamilton_problem.py

    The program will prompt you to enter the distance between neighboring cities, gas available at each city, and the number of miles that your car can travel per gallon of fuel (MPG). Enter these values when prompted.
    The program will output the index of the preferred starting city.

Example

Suppose the distance between neighboring cities is [5, 25, 15, 10, 15], the gas available at each city is [1, 2, 1, 0, 3], and the car can travel 10 miles per gallon of fuel. Running the program with these inputs will output 4, indicating that the preferred starting city is city 4.
Contributing

If you wish to contribute to this project, feel free to submit a pull request or open an issue.
License

This project is licensed under the MIT License. See the LICENSE file for more details.
