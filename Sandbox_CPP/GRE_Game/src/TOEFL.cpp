/*
    TOEFL.cpp
    The module represents my words shuffle game from the TOEFL Magoosh Application.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <type_traits>
#include <new>
#include <list>
#include <forward_list>
#include <map>
#include <iterator>
#include <deque>
#include <set>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;
static vector <string> current;

void common_vocabulary(int number)
{
    vector<string> common{"Function", "Substitute", "Nevertheless", "Issue", "Hypothesis",
                          "Hence", "Require", "Lecture", "Theory", "Emphasize",
                          "Establish", "Capable", "Involve", "Fundamental", "Analyze",
                          "Approach", "Indicate", "Investigate", "Feature", "Restrict",
                          "Assess", "Significant", "Contrast", "Modify", "Sufficient",
                          "Stress", "Despite", "Identify", "Adequate", "Assume",
                          "Data", "Select", "Furthermore", "Instance", "Method",
                          "Context", "Overall", "Consume", "Constant", "Predict",
                          "Illustrate", "Accurate", "Adjust", "Whereas", "Brief",
                          "Brief", "Register", "Demonstrate", "Trend", "Concept", "Project"};

    vector<string> easy{"Acquire", "Participate", "Major", "Previous", "Maintain",
                        "Expand", "Access", "Available", "Relevant", "Obvious",
                        "Region", "Research", "Strategy", "Imply", "Source",
                        "Occupy", "Remove", "Minor", "Evident", "Specify",
                        "Achieve", "Complex", "Individual", "Resource", "Contact",
                        "Resolve", "Physical", "Period", "Mental", "Occur",
                        "Consequence", "Conduct", "Transfer", "Respond", "Section",
                        "Reject", "Affect", "Maximize", "React", "Challenge",
                        "Construct", "Rely", "Primary", "Assist", "Evaluate",
                        "Comment", "Focus", "Culture", "Label", "Circumstance"};

    switch (number)
    {
        case 1:
            current = common;
            break;
        case 2:
            current = easy;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }

}

void medium_vocabulary(int number)
{
    vector<string> medium_first{"Notion", "Obtain", "Element", "Shift", "Benefit",
                                "Link", "Expose", "Community", "Initial", "Vary",
                                "Invest", "Contribute", "Alternative", "Decline", "Role",
                                "Administration", "Internal", "Aware", "Regulate", "Precise",
                                "Site", "Equivalent", "Proceed", "Philosophy", "Range",
                                "Distribute", "Distinct", "Network", "Considerable", "Annual",
                                "Status", "Reside", "Prior", "Debate", "Layer",
                                "Enable", "Sustain", "Potential", "Tradition", "Concentrate",
                                "Secure", "Stable", "Attribute", "Conflict", "Attitude",
                                "Labor", "Authority", "Correspond", "Interpret", "Estimate"};

    vector<string> medium_second{"Overwhelm", "Downfall", "Provoke", "Complement", "Behalf",
                                 "Ornamental", "Drawback", "Constraint", "Migrate", "Overcome",
                                 "Defective", "Scarce", "Absent", "Displace", "Era",
                                 "Hazard", "Gratify", "Elegant", "Readily", "Coherent",
                                 "Reconcile", "Convey", "Persist", "Advocate", "Controversy",
                                 "Consent", "Momentum", "Compel", "Ambiguous", "Foster",
                                 "Emit", "Impose", "Rigid", "Concede", "Scrap",
                                 "Slender", "Culminate", "Tint", "Undertake", "Tentative",
                                 "Convoluted", "Hierarchy", "Prestigious", "Deter", "Endeavor",
                                 "Via", "Specimen", "Linger", "Accumulate", "Perpetual"};

    vector<string> medium_third{"Disperse", "Foe", "Resent", "Demolish", "Vast",
                                "Impending", "Endure", "Conform", "Abrupt", "Durable",
                                "Defiant", "Bulky", "Shimmer", "Provided", "Coincide",
                                "Inclination", "Eccentric", "Extravagant", "Impede", "Integral",
                                "Distort", "Warp", "Disparate", "Persevere", "Robust",
                                "Trigger", "Stunning", "Preemptive", "Impartial", "Indifference",
                                "Complementary", "Dusk", "Overlap", "Conducive", "Cling",
                                "Extract", "Widespread", "Mend", "Crude", "Persistent",
                                "Obscure", "Devoid", "Courteous", "Roam", "Sketch",
                                "Revolutionary", "Protocol", "Extinct", "Abundant", "Controversial"};

    switch (number)
    {
        case 1:
            current = medium_first;
            break;
        case 2:
            current = medium_second;
            break;
        case 3:
            current = medium_third;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }
}

void hard_vocabulary(int number)
{
    vector<string> hard_first{"Deduce", "Welfare", "Generate", "Area", "Capacity",
                              "Orient", "Perspective", "Perceive", "Seek", "Retain",
                              "Apparent", "Justify", "Compensate", "Grant", "Enforce",
                              "Integrate", "Entity", "Negate", "External", "Derive",
                              "Scheme", "Valid", "Component", "Pursue", "Coordinate",
                              "Monitor", "Diverse", "Institute", "Consist", "Alter",
                              "Discrete", "Facilitate", "Underlying", "Factor", "Proportion",
                              "Constitute", "Framework", "Commit", "Objective", "Phase",
                              "Emerge", "Subsequent", "Aspect", "Impact", "Constrain",
                              "Policy", "Exclude", "Core", "Principle", "Criteria"};

    vector<string> hard_second{"Dynamic", "Mundane", "Plead", "Fraudulent", "Rustic",
                               "Strenuous", "Vivid", "Detrimental", "Counterpart", "Covert",
                               "Relic", "Congregate", "Analogous", "Induce", "Jolt",
                               "Cherish", "Perplex", "Strive", "Tedious", "Sloping",
                               "Delusion", "Entice", "Twilight", "Dissipate", "Illusory",
                               "Outgoing", "Successor", "Compulsory", "Transitory", "Astute",
                               "Encroach", "Blunt", "Exhaustive", "Ailment", "Anomaly",
                               "Secrete", "Meticulous", "Grave", "Propagate", "Vanquish",
                               "Append", "Carve", "Incentive", "Pale", "Recede",
                               "Instrumental", "Fatigue", "Probe", "Preposterous", "Fluctuate"};

    vector<string> hard_third{"Turbulent", "Ragged", "Analogy", "Futile", "Remnant",
                              "Scores", "Consensus", "Devise", "Endorse", "Potent",
                              "Clumsy", "Fracture", "Amend", "Prevail", "Upheaval",
                              "Brisk", "Irrevocable", "Meager", "Tenacious", "Rugged",
                              "Deviate", "Ingenuity", "Synthesize", "Implausible", "Harness",
                              "Profound", "Cozy", "Obsolete", "Novel", "Barren",
                              "Invoke", "Pivotal", "Intersperse", "Paradox", "Apprehension",
                              "Outlook", "Waive", "Viable", "Dormant", "Apathetic",
                              "Serene", "Derivative", "Superfluous", "Eradicate", "Striking",
                              "Affluent", "Feasible", "Colossal", "Elicit", "Faint"};

    vector<string> hard_fourth{"Refute", "Oversee", "Adjacent", "Sheer", "Hue",
                               "Fasten", "Proliferate", "Ominous", "Ensue", "Undermine",
                               "Comprise", "Evade", "Anomalous", "Flee", "Conspicuous",
                               "Innate", "Calamity", "Rural", "Abstain", "Dreary",
                               "Plausible", "Medium", "Intrinsic", "Perpetuate", "Intervene",
                               "Apathy", "Procure", "Oblong", "Predominant", "Jagged",
                               "Arduous", "Blatant", "Diffuse", "Shred", "Thrive",
                               "Liable", "Elude", "Drowsy", "Agile", "Confer",
                               "Esteem", "Desist", "Secluded", "Tame", "Vicarious",
                               "Subsume", "Incline", "Fragrant", "Stall", "Yield", "Prevalent"};

    switch (number)
    {
        case 1:
            current = hard_first;
            break;
        case 2:
            current = hard_second;
            break;
        case 3:
            current = hard_third;
            break;
        case 4:
            current = hard_fourth;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }
}

void challenging_vocabulary(int number)
{
    vector<string> challenging_first{"Excavate", "Elective", "Lull", "Thwart", "Trivial",
                                     "Baffle", "Impetus", "Infinitesimal", "Morph", "Lavish",
                                     "Pseudonym", "So-called", "Rife", "Rebound", "Seasoned",
                                     "Marked", "Inept", "Ruthless", "Beckon", "Augment",
                                     "Urbane", "Strife", "Wane", "Swivel", "Erode",
                                     "Abolish", "Brittle", "Accrete", "Indigenous", "Fastidious",
                                     "Forgo", "Overt", "Hamper", "Irrefutable", "Offset",
                                     "Apt", "Despondent", "Dwell", "Hinder", "Exacting",
                                     "Drench", "Forge", "Celebrated", "Plague", "Overshadow",
                                     "Convene", "Flourish", "Craze", "Profuse", "Nuance"};

    vector<string> challenging_second{"Avert", "Feeble", "Fable", "Quaint", "Prose",
                                      "Undergo", "Innocuous", "Deplete", "Tactful", "Seep",
                                      "Pressing", "Ornate", "Coax", "Adept", "Wares",
                                      "Sound", "Lure", "Arid", "Hoist", "Adorn",
                                      "Indignant", "Advent", "Cope", "Drought", "Telling",
                                      "Verge", "Adverse", "Erratic", "Murky", "Jeopardy",
                                      "Dwelling", "Wary", "Haphazard", "Juxtapose", "Fuse",
                                      "Salvage", "Prolific", "Paramount", "Remote", "Disingenuous",
                                      "Gaudy", "Forage", "Torrent", "Elusive", "Levy",
                                      "Banish", "Wither", "Sever", "Bleak", "Minute"};

    vector<string> challenging_third{"Forthcoming", "Bombard", "Endow", "Spearhead", "Propulsion",
                                     "Dwindle", "Dubious", "Dismal", "Thaw", "Catalyst",
                                     "Savage", "Supplant", "Inexorable", "Involved", "Qualify",
                                     "Cohesive", "Spur", "Spawn", "Trappings", "Adhere",
                                     "Cull", "Lucid", "Knack", "Crave", "Morale",
                                     "Mushroom", "Aroma", "Notwithstanding", "Foremost", "Apex",
                                     "Eerie", "Incessant", "Pretext", "Fleeting", "Overlook",
                                     "Hurl", "Retract", "Facet", "Vessel", "Trickle",
                                     "Depress", "Raze", "Audacious", "Barter", "Exacerbate",
                                     "Grueling", "Peril", "Hazy", "Lurk", "Uphold"};

    switch (number)
    {
        case 1:
            current = challenging_first;
            break;
        case 2:
            current = challenging_second;
            break;
        case 3:
            current = challenging_third;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }
}

int toefl_vocabulary()
{
    //---------------------------the vocabulary list---------------------------------------------
    vector <string> :: iterator itr;
    string choice;
    int number = 0; //condition = 0;
    chapter:
    cout<<"Which section of the TOEFL vocabulary would you like to train?"<<endl;
    cin>>choice;
    /*while(!((choice != "common") && (choice != "COMMON") && (choice != "Common") &&
    (choice != "basic") && (choice != "BASIC") && (choice != "Basic") &&
    ((choice != "advanced") && (choice != "ADVANCED") && (choice != "ADVANCED") )))
    {
        cout<<"False answer entered. Please specify the chapter."<<endl;
        cin>>choice;
    }
     */
    //---------------------------the conditions list---------------------------------------------
    if((choice == "common") || (choice == "COMMON") || (choice == "Common"))
    {
        cout<<"Please provide the number of part from 1 or 2 of the vocabulary list:"<<endl;
        cin>>number;
        common_vocabulary(number);
        //integers.empty() == true ? cout << "Vector is empty"<<endl : cout <<"Vector isn't empty"<< endl;
    }

    else if((choice == "medium") || (choice == "MEDIUM") || (choice == "Medium"))
    {
        cout<<"Please provide the number of part from 1 to 3 of the vocabulary list:"<<endl;
        cin>>number;
        medium_vocabulary(number);
    }

    else if((choice == "hard") || (choice == "HARD") || (choice == "Hard"))
    {
        cout<<"Please provide the number of part from 1 to 4 of the vocabulary list:"<<endl;
        cin>>number;
        hard_vocabulary(number);
    }

    else if((choice == "challenging") || (choice == "CHALLENGING") || (choice == "Challenging"))
    {
        cout<<"Please provide the number of part from 1 to 3 of the vocabulary list:"<<endl;
        cin>>number;
        challenging_vocabulary(number);
    }
    else
    {
        cout<<"False answer entered. Please specify the chapter."<<endl;
        goto chapter;
    }
//---------------------------the shuffle section ---------------------------------------------
    static int a=1;
    for(;;)
    {
        srand((unsigned) time(NULL));
        random_shuffle(current.begin(), current.end());
        for (itr = current.begin(); itr != current.end(); itr++)
        {
            cout <<"The "<<a<<" word for the turn: "<<endl;
            cout<<*itr << endl;
            a++;
            cin.get();
        }
        if (a>=50)
            break;
    }
    return a;
}