# Implement a Sports Team Management System in C

## Problem Description

The goal of this assignment is to apply your knowledge of Structures, Arrays, and Enumerations in C to create a sports team management system. You will handle a team of players, with each player having different attributes including their position on the field. The system will allow the user to add players, delete players, display team details, search for a specific player, and update player information.

### General Idea

1. Define a Player Position Enumeration: Define an enumeration Position that includes all possible positions a player can have (Goalkeeper, Defender, Midfielder, Forward).
2. Define a Player Structure: Define a structure Player that should have the following attributes [unique ID, name, position (of Position enum type), age, and number of goals scored].
3. Create an Array of Structures: Create an array of Player structures to store the player data for the entire team.
4. Add Players: Implement a function to add new players to the team. Each player should have a unique ID, name, position, age, and number of goals scored. It is impossible to add a new player with an already existing ID.
5. Delete Players: Implement a function to delete a player from the team using the player's unique ID.
6. Display Team: Implement a function to display all the players in the team along with their details.
7. Search Players: Implement a function to search for a specific player using the player's unique ID.
8. Update Player Info: Implement a function to update the information of a player using the player's unique ID.

### Input Format

The input file will contain multiple lines starting with commands like (Add, Delete, Update …) and ending with a Display command.

All commands should start with an uppercase letter and should be followed by the arguments needed for the command.

### Output Format

Your solution should be written to output.txt and it should end with a newline character.

### Examples

**input.txt**:
Add
7
Ahmad
Defender
25
10
Update
7
Ahmad
Defender
26
50
Add
1
Munir
Goalkeeper
31
89
Delete
7
Display

**output.txt**:
ID: 1, Name: Munir, Position: Goalkeeper, Age: 31, Goals: 89

**input.txt**:
Add
1
Alaa
Forward
25
100
Update
1
Munir
Forward
25
100
Search
1
Display

**output.txt**:
Found
ID: 1, Name: Munir, Position: Forward, Age: 25, Goals: 100

**input.txt**:
Add
12
Jay
Forward
25
100
Update
12
Munir
Forward
25
100
Search
1
Delete
1
Display

**output.txt**:
Not found
Impossible to delete
ID: 12, Name: Munir, Position: Forward, Age: 25, Goals: 100
