/*
Zork-Style: ATD Mobile Detailer vs. The Monday Apocalypse
CSC 134-ish • v0.4 (Post-Supply Branches)
author: dayton-will + Bjorn
desc: Morning → transport → first client → supply stop + location-specific branch → outbreak hook.
*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// --- Prototypes ---
void show_title();
int  read_int_in_range(int min_val, int max_val, const string& prompt);

int  morning_routine();                    // returns cleanliness (0/1)
int  choose_transport();                   // 1=truck, 2=moto, 3=run
int  first_client(int transport);          // 1=smooth, 0=not smooth

int  choose_supply_stop();                 // 1=hardware, 2=grocery, 3=detail warehouse
int  resolve_supply(int stop, int cleanliness, int transport, int job_ok); // returns supplies 0..2
void post_supply_branch(int stop, int cleanliness, int transport, int job_ok, int supplies);

void outbreak_intro(int cleanliness, int transport, int job_ok, int supplies);
bool play_again();

// --- Main ---
int main() {
    show_title();
    do {
        int cleanliness = morning_routine();
        int transport   = choose_transport();
        int job_ok      = first_client(transport);

        int stop        = choose_supply_stop();
        int supplies    = resolve_supply(stop, cleanliness, transport, job_ok);

        // NEW: a second choice unique to the selected store
        post_supply_branch(stop, cleanliness, transport, job_ok, supplies);

        outbreak_intro(cleanliness, transport, job_ok, supplies);
        cout << "\n=== Demo round complete! (v0.4) ===\n";
    } while (play_again());

    cout << "Thanks for playing — may your foam cannon always sing.\n";
    return 0;
}

// --- Definitions ---

void show_title() {
    cout << "=============================================\n";
    cout << " ATD MOBILE DETAIL: MONDAY APOCALYPSE (v0.4)\n";
    cout << "=============================================\n";
    cout << "You are a professional automotive detailer.\n";
    cout << "Route: morning → first job → supply stop (+ mini-branch) → hmm, zombies?\n\n";
}

int read_int_in_range(int min_val, int max_val, const string& prompt) {
    while (true) {
        cout << prompt;
        int value;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Oops, numbers only please.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (value < min_val || value > max_val) {
            cout << "Please enter a number from " << min_val << " to " << max_val << ".\n";
            continue;
        }
        return value;
    }
}

int morning_routine() {
    cout << "You wake up to your alarm labeled: \"BE A RESPONSIBLE ADULT\".\n";
    cout << "Do you:\n";
    cout << "  1) Shower like a professional human\n";
    cout << "  2) Blast some deodorant and call it 'Speed Shower™'\n";
    int choice = read_int_in_range(1, 2, "Enter choice (1-2): ");
    if (choice == 1) {
        cout << "Sparkling. Minty. Glorious. Customers will weep with joy.\n\n";
        return 1;
    } else {
        cout << "Bold choice. Your charisma will need to do some heavy lifting today.\n\n";
        return 0;
    }
}

int choose_transport() {
    cout << "Commute time! Your options:\n";
    cout << "  1) Tacoma — reliable, holds gear, smells faintly of tire shine\n";
    cout << "  2) Motorcycle — fast, fun, backpack with just the essentials\n";
    cout << "  3) Run there — you’re training for a 50k race anyway, right?\n";
    int pick = read_int_in_range(1, 3, "Enter choice (1-3): ");
    switch (pick) {
        case 1: cout << "You load the ATD kit into the Tacoma like a pro. Seatbelt click.\n\n"; return 1;
        case 2: cout << "Helmet on. Vroom. You look very aerodynamic and slightly late.\n\n";   return 2;
        case 3: cout << "You begin running with a bucket, a hose, and a dream. Neighbors film.\n\n"; return 3;
        default: return 1;
    }
}

int first_client(int transport) {
    cout << "You arrive at your first client: a soccer-van coated in the trifecta: goldfish, dog glitter (\"fur\"), and mystery stickiness.\n";
    if (transport == 2) {
        cout << "Your motorcycle backpack held: one microfiber, one bottle of APC, and optimism.\n";
        cout << "The van laughs in Cheerios.\n";
        cout << "Client: \"Can you also shampoo the headliner and fix my son’s slime sculpture?\"\n";
        cout << "You quote bravely, but this might take longer.\n\n";
        return 0;
    } else {
        cout << "You unload the full ATD kit like a magician pulling gear from a hat.\n";
        cout << "Foam cannon sings. The van confesses its sins. You restore honor to the minivan clan.\n\n";
        return 1;
    }
}

int choose_supply_stop() {
    cout << "With rumors swirling, you decide a quick supply stop wouldn’t hurt.\n";
    cout << "Where do you swing by?\n";
    cout << "  1) Hardware Store — duct tape, utility knife, bungee cords\n";
    cout << "  2) Grocery Store — water, beans, and \"emergency donuts\"\n";
    cout << "  3) Detail Supply Warehouse — extra microfibers, APC, clay bars\n";
    return read_int_in_range(1, 3, "Enter choice (1-3): ");
}

int resolve_supply(int stop, int cleanliness, int transport, int job_ok) {
    int supplies = 0; // 0 (meh), 1 (useful), 2 (very useful)
    switch (stop) {
        case 1:
            cout << "Hardware Store smells like destiny. You grab duct tape and bungees.\n";
            if (transport == 2) { cout << "Bungees tame the backpack bulge. 10/10 would strap again.\n"; supplies = 2; }
            else { cout << "Useful stuff, but the Tacoma already has a small hardware aisle.\n"; supplies = 1; }
            break;
        case 2:
            cout << "Grocery Store: You acquire water, beans, and a box of maple-glazed morale.\n";
            if (cleanliness == 0) { cout << "You share a donut with the cashier to distract from your 'Speed Shower™'.\n"; }
            else { cout << "You are clean, caffeinated, and now slightly sticky with glaze.\n"; }
            supplies = 1;
            break;
        case 3:
            cout << "Detail Supply Warehouse: microfibers leap into your cart voluntarily.\n";
            if (job_ok == 0) { cout << "Fresh towels = fresh start. You feel professionally reborn.\n"; supplies = 1; }
            else { cout << "You stack-boost your already immaculate workflow. Foam cannon purrs.\n"; supplies = 2; }
            break;
        default: break;
    }
    cout << "\nYou load up and check the news again. People are really into biting.\n\n";
    return supplies;
}

// NEW: location-specific second choice after the supply stop
void post_supply_branch(int stop, int cleanliness, int transport, int job_ok, int supplies) {
    switch (stop) {
        case 1: { // Hardware Store branch
            cout << "[Hardware Lot] A slow-moving cluster of biters shuffles near the exit.\n";
            cout << "Use your haul to: \n";
            cout << "  1) Bungee-barricade the door (quiet, controlled)\n";
            cout << "  2) Duct-tape a leaf blower to make a \"noise lure\" (loud, risky)\n";
            int c = read_int_in_range(1, 2, "Enter choice (1-2): ");
            if (c == 1) {
                if (supplies >= 2) cout << "Professional-grade strapping! Door secured. Zombies ponder knots.\n";
                else               cout << "It holds… mostly. One zombie squeezes through and gets stuck like a beached Roomba.\n";
            } else {
                if (transport == 2) cout << "Leaf blower lure works, but your helmet amplifies the noise. You flee stylishly.\n";
                else                cout << "Lure succeeds. Bonus: the Tacoma bed vibrates like a subwoofer. Free car audio demo.\n";
            }
            break;
        }
        case 2: { // Grocery Store branch
            cout << "[Grocery Aisle] People duel with shopping carts. You spot supplies on a high shelf.\n";
            cout << "What’s the move?\n";
            cout << "  1) Help folks form a ladder (teamwork)\n";
            cout << "  2) Distract the crowd with free donuts, then snag the goods (tactical glaze)\n";
            int c = read_int_in_range(1, 2, "Enter choice (1-2): ");
            if (c == 1) {
                if (cleanliness == 1) cout << "You look trustworthy and smell like mint. Cooperation achieved. Supplies secured.\n";
                else                   cout << "They hesitate… then you share water. Teamwork unlocked. Supplies secured.\n";
            } else {
                cout << "You shout \"FREE DONUTS!\" and the crowd migrates like geese. You ninja the shelf items.\n";
                if (job_ok == 1) cout << "A grateful parent hands you a coupon for non-expired beans.\n";
            }
            break;
        }
        case 3: { // Detail Warehouse branch
            cout << "[Detail Warehouse] Another detailer waves: \"Trade?\" He offers options.\n";
            cout << "Pick a trade:\n";
            cout << "  1) Your clay bars for his compact inverter (power tiny tools)\n";
            cout << "  2) Your APC for his mystery 5-gal drum labeled \"???\" (bold)\n";
            int c = read_int_in_range(1, 2, "Enter choice (1-2): ");
            if (c == 1) {
                if (transport == 2) cout << "Inverter fits under your seat. Moto win! Tiny power = big utility later.\n";
                else                cout << "Inverter rides in the Tacoma. You feel grid-adjacent and smug.\n";
            } else {
                cout << "You crack the drum: turns out it’s premium tire shine concentrate. Zombies are mesmerized by the gloss.\n";
                if (supplies >= 2) cout << "You mix a perfect ratio. Beading so crisp it’s basically social distancing.\n";
            }
            break;
        }
        default:
            // Shouldn’t happen, but be graceful.
            cout << "[Parking Lot] You contemplate life, sip water, and rehearse your heroic stare.\n";
            break;
    }
    cout << "\nYou slip away toward the client’s neighborhood as the day gets... chewy.\n\n";
}

void outbreak_intro(int cleanliness, int transport, int job_ok, int supplies) {
    cout << "As you’re finishing up, you notice three things:\n";
    cout << "  • Your phone pings with a news alert: \"PLEASE DO NOT PANIC but also maybe panic\".\n";
    cout << "  • A man across the street is chasing a mailman while trying to bite envelopes.\n";
    cout << "  • The dog you just de-furred says \"braaaiiins\" (probably).\n\n";

    if (cleanliness == 1) cout << "Good news: you smell fantastic. If zombies hunt by scent, they’ll pick the Speed-Shower guy.\n";
    else                  cout << "You smell intriguing. Zombies are foodies now.\n";

    if (transport == 3)   cout << "You consider running away. You are already running, technically.\n";
    if (job_ok == 1)      cout << "The client, grateful, offers you a tip… in canned beans. \"These might be currency soon.\"\n";
    else                  cout << "The client asks if the apocalypse includes a discount. You pretend the foam cannon is a fire hose and leave.\n";

    if (supplies >= 2)    cout << "Thanks to your supply stop, you jury-rig a quick door barricade / hose-lasso.\n";
    else if (supplies==1) cout << "Your supplies aren’t glamorous, but they help. You hand a donut to a non-zombie. Morale +1.\n";
    else                  cout << "You have… water. Which is good. Hydration is important when fleeing politely.\n";

    cout << "\nA lone zombie shuffles toward the freshly detailed van, admiring the beading.\n";
    cout << "To be continued…\n";
}

bool play_again() {
    cout << "\nPlay again?\n";
    cout << "  1) Yes\n";
    cout << "  2) No\n";
    int choice = read_int_in_range(1, 2, "Enter choice (1-2): ");
    return (choice == 1);
}
