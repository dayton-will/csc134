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
    // Entrance Hall connections
    connections[ENTRANCE_HALL][NORTH] = LIBRARY;    // Entrance Hall -> North -> Library
    connections[ENTRANCE_HALL][EAST] = KITCHEN;     // Entrance Hall -> East -> Kitchen
    connections[ENTRANCE_HALL][SOUTH] = -1;         // No connection south
    connections[ENTRANCE_HALL][WEST] = GARDEN;      // Entrance Hall -> West -> Garden
    
    // Library connections
    connections[LIBRARY][NORTH] = -1;               // No connection north
    connections[LIBRARY][EAST] = -1;                // No connection east
    connections[LIBRARY][SOUTH] = ENTRANCE_HALL;    // Library -> South -> Entrance Hall
    connections[LIBRARY][WEST] = -1;                // No connection west
    
    // Kitchen connections
    connections[KITCHEN][NORTH] = -1;               // No connection north
    connections[KITCHEN][EAST] = -1;                // No connection east
    connections[KITCHEN][SOUTH] = BASEMENT;         // Kitchen -> South -> Basement
    connections[KITCHEN][WEST] = ENTRANCE_HALL;     // Kitchen -> West -> Entrance Hall
    
    // Garden connections
    connections[GARDEN][NORTH] = -1;                // No connection north
    connections[GARDEN][EAST] = ENTRANCE_HALL;      // Garden -> East -> Entrance Hall
    connections[GARDEN][SOUTH] = -1;                // No connection south
    connections[GARDEN][WEST] = -1;                 // No connection west
    
    // Basement connections
    connections[BASEMENT][NORTH] = KITCHEN;         // Basement -> North -> Kitchen
    connections[BASEMENT][EAST] = -1;               // No connection east
    connections[BASEMENT][SOUTH] = -1;              // No connection south
    connections[BASEMENT][WEST] = -1;               // No connection west
    
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