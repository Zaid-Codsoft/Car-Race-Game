# Car-Race-Game
here this is a car racing game on console based. Where you have road from where your car can move and collect trophies AND coins and make sure the travel from path where there is no obstacles...
1. Develop a 2D console-based race car game using C++ without utilizing any
external graphics library. Implement a text-based user interface within the
console (A text-based user interface (TUI) relies on characters and text to

convey information to the user instead of graphical elements. In a console-
based game, a TUI might involve using ASCII characters and text to represent

various game elements). The game must also feature player-controlled race
cars, obstacles, tracks, and a scoring system.
2. Data Structures Integration:
a. Graphs for Map and Navigation:
- Map Representation: Create a graph to represent the game map. Nodes
in the graph represent locations or waypoints in the game world, while edges
represent paths between them. This graph can be used for player navigation.
- Navigation and Pathfinding: Implement algorithms like Dijkstra's algorithm
or any other shortest path finding algorithms on the graph to find optimal
paths for player-controlled race cars. The graph can help ensure that
characters navigate the race track efficiently and avoiding obstacles
b. Queues for Obstacle:
- Obstacle : Utilize a queue data structure to manage the generation of
obstacles. New obstacles can be added to the queue as they are generated,
and the game loop can process the queue to introduce these elements at
appropriate times.
- Example: If your game features randomly appearing obstacles on the race
track, you can enqueue obstacle objects with information about their type
and location. During each game update, you can dequeue these objects and
add them to the game world at the specified positions.
c. Linked Lists for Collected Coins and Game Trophies:
- Collected Items: Maintain a linked list to keep track of items collected by
players during the game, such as coins or trophies. Each node in the linked
list represents an item collected, with relevant information (e.g., item type,
score value).
- Example: As players collect coins or achieve milestones, you can add nodes
to the linked list. The linked list allows easy tracking of collected items and
can be used to update the player's score or display their achievements.
