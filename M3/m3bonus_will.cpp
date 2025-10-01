/*
Zork-Style: ATD Mobile Detailer vs. The Monday Apocalypse
CSC 134-ish • v0.4 (Post-Supply Branches) — endl style
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

        // Location-specific second choice
        post_supply_branch(stop, cleanliness, transport, job_ok, supplies);

        outbreak_intro(cleanliness, transport, job_ok, supplies);
        cout << "\n=== Demo round complete! (v0.4) ===" << endl;
    } while (play_again());

    cout << "Thanks for playing — may your foam cannon always sing." << endl;
    return 0;
}

// --- Definitions ---

void show_title() {
    cout << "=============================================" << endl;
    cout << " ATD MOBILE DETAIL: MONDAY APOCALYPSE (v0.4)" << endl;
    cout << "=============================================" << endl;
    cout << "You are a professional automotive detailer." << endl;
    cout << "Route: morning → first job → supply stop (+ mini-branch) → hmm, zombies?" << endl;
    cout << endl;
}

int read_int_in_range(int min_val, int max_val, const string& prompt) {
    while (true) {
        cout << prompt << endl;
        int value;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Oops, numbers only please." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (value < min_val || value > max_val) {
            cout << "Please enter a number from " << min_val << " to " << max_val << "." << endl;
            continue;
        }
        return value;
    }
}

int morning_routine() {
    cout << "You wake up to your alarm labeled: \"BE A RESPONSIBLE ADULT\"." << endl;
    cout << "Do you:" << endl;
    cout << "  1) Shower like a professional human" << endl;
    cout << "  2) Blast some deodorant and call it 'Speed Shower™'" << endl;
    int choice = read_int_in_range(1, 2, "Enter choice (1-2):");

    if (choice == 1) {
        cout << "Sparkling. Minty. Glorious. Customers will weep with joy." << endl;
        cout << endl;
        return 1;
    } else {
        cout << "Bold choice. Your charisma will need to do some heavy lifting today." << endl;
        cout << endl;
        return 0;
    }
}

int choose_transport() {
    cout << "Commute time! Your options:" << endl;
    cout << "  1) Tacoma — reliable, holds gear, smells faintly of tire shine" << endl;
    cout << "  2) Motorcycle — fast, fun, backpack with just the essentials" << endl;
    cout << "  3) Run there — you’re training for a 50k race anyway, right?" << endl;
    int pick = read_int_in_range(1, 3, "Enter choice (1-3):");

    switch (pick) {
        case 1:
            cout << "You load the ATD kit into the Tacoma like a pro. Seatbelt click." << endl;
            cout << endl;
            return 1;
        case 2:
            cout << "Helmet on. Vroom. You look very aerodynamic and slightly late." << endl;
            cout << endl;
            return 2;
        case 3:
            cout << "You begin running with a bucket, a hose, and a dream. Neighbors film." << endl;
            cout << endl;
            return 3;
        default:
            return 1; // unreachable due to validation
    }
}

int first_client(int transport) {
    cout << "You arrive at your first client: a soccer-van coated in the trifecta: goldfish, dog glitter (\"fur\"), and mystery stickiness." << endl;

    if (transport == 2) {
        cout << "Your motorcycle backpack held: one microfiber, one bottle of APC, and optimism." << endl;
        cout << "The van laughs in Cheerios." << endl;
        cout << "Client: \"Can you also shampoo the headliner and fix my son’s slime sculpture?\"" << endl;
        cout << "You quote bravely, but this might take longer." << endl;
        cout << endl;
        return 0;
    } else {
        cout << "You unload the full ATD kit like a magician pulling gear from a hat." << endl;
        cout << "Foam cannon sings. The van confesses its sins. You restore honor to the minivan clan." << endl;
        cout << endl;
        return 1;
    }
}

int choose_supply_stop() {
    cout << "With rumors swirling, you decide a quick supply stop wouldn’t hurt." << endl;
    cout << "Where do you swing by?" << endl;
    cout << "  1) Hardware Store — duct tape, utility knife, bungee cords" << endl;
    cout << "  2) Grocery Store — water, beans, and \"emergency donuts\"" << endl;
    cout << "  3) Detail Supply Warehouse — extra microfibers, APC, clay bars" << endl;
    return read_int_in_range(1, 3, "Enter choice (1-3):");
}

int resolve_supply(int stop, int cleanliness, int transport, int job_ok) {
    int supplies = 0; // 0 (meh), 1 (useful), 2 (very useful)
    switch (stop) {
        case 1:
            cout << "Hardware Store smells like destiny. You grab duct tape and bungees." << endl;
            if (transport == 2) {
                cout << "Bungees tame the backpack bulge. 10/10 would strap again." << endl;
                supplies = 2;
            } else {
                cout << "Useful stuff, but the Tacoma already has a small hardware aisle." << endl;
                supplies = 1;
            }
            break;
        case 2:
            cout << "Grocery Store: You acquire water, beans, and a box of maple-glazed morale." << endl;
            if (cleanliness == 0) {
                cout << "You share a donut with the cashier to distract from your 'Speed Shower™'." << endl;
            } else {
                cout << "You are clean, caffeinated, and now slightly sticky with glaze." << endl;
            }
            supplies = 1;
            break;
        case 3:
            cout << "Detail Supply Warehouse: microfibers leap into your cart voluntarily." << endl;
            if (job_ok == 0) {
                cout << "Fresh towels = fresh start. You feel professionally reborn." << endl;
                supplies = 1;
            } else {
                cout << "You stack-boost your already immaculate workflow. Foam cannon purrs." << endl;
                supplies = 2;
            }
            break;
        default: break;
    }
    cout << "\nYou load up and check the news again. People are really into biting." << endl;
    cout << endl;
    return supplies;
}

void post_supply_branch(int stop, int cleanliness, int transport, int job_ok, int supplies) {
    switch (stop) {
        case 1: { // Hardware Store branch
            cout << "[Hardware Lot] A slow-moving cluster of biters shuffles near the exit." << endl;
            cout << "Use your haul to:" << endl;
            cout << "  1) Bungee-barricade the door (quiet, controlled)" << endl;
            cout << "  2) Duct-tape a leaf blower to make a \"noise lure\" (loud, risky)" << endl;
            int c = read_int_in_range(1, 2, "Enter choice (1-2):");
            if (c == 1) {
                if (supplies >= 2) cout << "Professional-grade strapping! Door secured. Zombies ponder knots." << endl;
                else               cout << "It holds… mostly. One zombie squeezes through and gets stuck like a beached Roomba." << endl;
            } else {
                if (transport == 2) cout << "Leaf blower lure works, but your helmet amplifies the noise. You flee stylishly." << endl;
                else                cout << "Lure succeeds. Bonus: the Tacoma bed vibrates like a subwoofer. Free car audio demo." << endl;
            }
            break;
        }
        case 2: { // Grocery Store branch
            cout << "[Grocery Aisle] People duel with shopping carts. You spot supplies on a high shelf." << endl;
            cout << "What’s the move?" << endl;
            cout << "  1) Help folks form a ladder (teamwork)" << endl;
            cout << "  2) Distract the crowd with free donuts, then snag the goods (tactical glaze)" << endl;
            int c = read_int_in_range(1, 2, "Enter choice (1-2):");
            if (c == 1) {
                if (cleanliness == 1) cout << "You look trustworthy and smell like mint. Cooperation achieved. Supplies secured." << endl;
                else                   cout << "They hesitate… then you share water. Teamwork unlocked. Supplies secured." << endl;
            } else {
                cout << "You shout \"FREE DONUTS!\" and the crowd migrates like geese. You ninja the shelf items." << endl;
                if (job_ok == 1) cout << "A grateful parent hands you a coupon for non-expired beans." << endl;
            }
            break;
        }
        case 3: { // Detail Warehouse branch
            cout << "[Detail Warehouse] Another detailer waves: \"Trade?\" He offers options." << endl;
            cout << "Pick a trade:" << endl;
            cout << "  1) Your clay bars for his compact inverter (power tiny tools)" << endl;
            cout << "  2) Your APC for his mystery 5-gal drum labeled \"???\" (bold)" << endl;
            int c = read_int_in_range(1, 2, "Enter choice (1-2):");
            if (c == 1) {
                if (transport == 2) cout << "Inverter fits under your seat. Moto win! Tiny power = big utility later." << endl;
                else                cout << "Inverter rides in the Tacoma. You feel grid-adjacent and smug." << endl;
            } else {
                cout << "You crack the drum: turns out it’s premium tire shine concentrate. Zombies are mesmerized by the gloss." << endl;
                if (supplies >= 2) cout << "You mix a perfect ratio. Beading so crisp it’s basically social distancing." << endl;
            }
            break;
        }
        default:
            cout << "[Parking Lot] You contemplate life, sip water, and rehearse your heroic stare." << endl;
            break;
    }
    cout << "\nYou slip away toward the client’s neighborhood as the day gets... chewy." << endl;
    cout << endl;
}

void outbreak_intro(int cleanliness, int transport, int job_ok, int supplies) {
    cout << "As you’re finishing up, you notice three things:" << endl;
    cout << "  • Your phone pings with a news alert: \"PLEASE DO NOT PANIC but also maybe panic\"." << endl;
    cout << "  • A man across the street is chasing a mailman while trying to bite envelopes." << endl;
    cout << "  • The dog you just de-furred says \"braaaiiins\" (probably)." << endl;
    cout << endl;

    if (cleanliness == 1) cout << "Good news: you smell fantastic. If zombies hunt by scent, they’ll pick the Speed-Shower guy." << endl;
    else                  cout << "You smell intriguing. Zombies are foodies now." << endl;

    if (transport == 3)   cout << "You consider running away. You are already running, technically." << endl;
    if (job_ok == 1)      cout << "The client, grateful, offers you a tip… in canned beans. \"These might be currency soon.\"" << endl;
    else                  cout << "The client asks if the apocalypse includes a discount. You pretend the foam cannon is a fire hose and leave." << endl;

    if (supplies >= 2)    cout << "Thanks to your supply stop, you jury-rig a quick door barricade / hose-lasso." << endl;
    else if (supplies==1) cout << "Your supplies aren’t glamorous, but they help. You hand a donut to a non-zombie. Morale +1." << endl;
    else                  cout << "You have… water. Which is good. Hydration is important when fleeing politely." << endl;

    cout << "\nA lone zombie shuffles toward the freshly detailed van, admiring the beading." << endl;
    cout << "To be continued…" << endl;
}

bool play_again() {
    cout << "\nPlay again?" << endl;
    cout << "  1) Yes" << endl;
    cout << "  2) No" << endl;
    int choice = read_int_in_range(1, 2, "Enter choice (1-2):");
    return (choice == 1);
}
