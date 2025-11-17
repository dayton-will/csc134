#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    LOOKOUT = 0,
    SHRINE = 1,
    LONGHOUSE = 2,
    TRAINING_YARD = 3,
    FOREST_EDGE = 4,
    SMITHY = 5,
    CARPENTERS_SHOP = 6,
    DRYING_RACKS = 7,
    DOCKS = 8,
    NUM_ROOMS = 5
};

int main() {
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Cliff Lookout",
        "Shrine",
        "Chieftain's Longhouse",
        "Training Yard",
        "Forest Edge"
        "Smithy"
        "Carpenter's Shop"
        "Drying Racks"
        "Docks"
    };
    
    // Room descriptions array
    
    /*
    Modify this code to fit the map of a viking longhouse with beach and ship.
    https://www.hurstwic.com/history/articles/society/text/seating.htm
    Rooms: 
    */
    string roomDescriptions[NUM_ROOMS] = {
        "A windswept, flat area at the highest point overlooking the entrance to the fjord. Below, you see the entrance to the shrine a few hundred meters away, and the village below.",
        "A clearing in the woods, ringed with stones. Placed at the base of trees and hanging from branches are various offerings -- skulls, bones, wood carvings, and iron nails. It's a little eerie.",
        "A longhouse where the village chieftain and his household live. Sod Roof.",
        "An area where the chieftain and his warriors train for battle. At one edge are racks for hanging bows, shields, and axes. At the opposite edge is a row of straw archery targets and wooden axe throwing targets.",
        "The edge of the pine forest. A narrow path winds through the trees; the air smells earthy -- moss, earth, and ancient pine trees."
        "A low-roofed smithy with a glowing forge. The village blacksmith is swinging his hammer -- a loud and rhythmic 'clank.'"
        "The local shipwright is carefully hewing planks that will fit together into a ship for raiding and trading next summer. The English will quake in their boots. (Always remember to pillage before you burn)."
        "Rows of wooden racks laden with meat and fish hanging over a fire to smoke."
        "A rough wooden dock stretching into the frigid sea. A longship bobs gently, its prow facing the open sea."
    };
    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // Define the connections between rooms using the Room enum
    /*Used ChatGPT 5.1 to assist with this. 
    Prompt: "Build the connections between rooms. Be sure to provide clear comments. 
    Use this style for the code and comments: (pasted professor's input)."
    */
   // Cliff Lookout connections
connections[CLIFF_LOOKOUT][NORTH] = -1;            // No connection north
connections[CLIFF_LOOKOUT][EAST]  = -1;            // No connection east
connections[CLIFF_LOOKOUT][SOUTH] = SHRINE;        // Cliff Lookout -> South -> Shrine
connections[CLIFF_LOOKOUT][WEST]  = -1;            // No connection west

// Shrine connections
connections[SHRINE][NORTH] = CLIFF_LOOKOUT;        // Shrine -> North -> Cliff Lookout
connections[SHRINE][EAST]  = -1;                   // No connection east
connections[SHRINE][SOUTH] = LONGHOUSE;            // Shrine -> South -> Chieftain's Longhouse
connections[SHRINE][WEST]  = -1;                   // No connection west

// Chieftain's Longhouse connections
connections[LONGHOUSE][NORTH] = SHRINE;            // Longhouse -> North -> Shrine
connections[LONGHOUSE][EAST]  = FOREST_EDGE;       // Longhouse -> East -> Forest Edge
connections[LONGHOUSE][SOUTH] = SMITHY;            // Longhouse -> South -> Smithy
connections[LONGHOUSE][WEST]  = TRAINING_YARD;     // Longhouse -> West -> Training Yard

// Training Yard connections
connections[TRAINING_YARD][NORTH] = -1;            // No connection north
connections[TRAINING_YARD][EAST]  = LONGHOUSE;     // Training Yard -> East -> Longhouse
connections[TRAINING_YARD][SOUTH] = SMITHY;        // Training Yard -> South -> Smithy
connections[TRAINING_YARD][WEST]  = -1;            // No connection west

// Forest Edge connections
connections[FOREST_EDGE][NORTH] = -1;              // No connection north
connections[FOREST_EDGE][EAST]  = -1;              // No connection east
connections[FOREST_EDGE][SOUTH] = -1;              // No connection south
connections[FOREST_EDGE][WEST]  = LONGHOUSE;       // Forest Edge -> West -> Longhouse

// Smithy connections
connections[SMITHY][NORTH] = LONGHOUSE;            // Smithy -> North -> Chieftain's Longhouse
connections[SMITHY][EAST]  = CARPENTER_SHOP;       // Smithy -> East -> Carpenter's Shop
connections[SMITHY][SOUTH] = DRYING_RACKS;         // Smithy -> South -> Drying Racks
connections[SMITHY][WEST]  = TRAINING_YARD;        // Smithy -> West -> Training Yard

// Carpenter's Shop connections
connections[CARPENTER_SHOP][NORTH] = -1;           // No connection north
connections[CARPENTER_SHOP][EAST]  = -1;           // No connection east
connections[CARPENTER_SHOP][SOUTH] = -1;           // No connection south
connections[CARPENTER_SHOP][WEST]  = SMITHY;       // Carpenter's Shop -> West -> Smithy

// Drying Racks connections
connections[DRYING_RACKS][NORTH] = SMITHY;         // Drying Racks -> North -> Smithy
connections[DRYING_RACKS][EAST]  = -1;             // No connection east
connections[DRYING_RACKS][SOUTH] = DOCKS;          // Drying Racks -> South -> Docks
connections[DRYING_RACKS][WEST]  = -1;             // No connection west

// Docks connections
connections[DOCKS][NORTH] = DRYING_RACKS;          // Docks -> North -> Drying Racks
connections[DOCKS][EAST]  = -1;                    // No connection east
connections[DOCKS][SOUTH] = -1;                    // No connection south
connections[DOCKS][WEST]  = -1;                    // No connection west
    
    // Game state
    int currentRoom = ENTRANCE_HALL; // Start in the Entrance Hall
    bool gameRunning = true;
    
    // Game loop
    while (gameRunning) {
        // Display current room information
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;
        
        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Get player input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;
        
        // Process movement commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "I don't understand that command." << endl;
        }
    }
    
    cout << "Thanks for playing!" << endl;
    return 0;
}