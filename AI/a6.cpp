#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Rule structure
struct Rule
{
    string condition1;
    string condition2;
    string fact;
    string inference;
};
// Knowledge Base
vector<Rule> knowledgeBase = {

    {"completes work on time", "good communication",
     "good employee",
     "Employee performs tasks properly and communicates well"},

    {"good employee", "team player",
     "promotion candidate",
     "Good employee and team player can be promoted"},

    {"poor attendance", "",
     "needs improvement",
     "Poor attendance affects performance"},

    {"misses deadlines", "poor attendance",
     "low performance",
     "Missing deadlines and poor attendance reduce performance"}};

// Fact database
set<string> facts;
int main()
{
    // Input symptoms/employee attributes
    vector<string> attributes = {
        "completes work on time",
        "good communication",
        "team player",
        "poor attendance",
        "misses deadlines"};

    cout << "EMPLOYEE PERFORMANCE EXPERT SYSTEM\n";
    cout << "Enter y for YES and n for NO\n\n";

    // User input
    for (int i = 0; i < attributes.size(); i++)
    {
        cout << "Does employee have attribute: "
             << attributes[i] << " ? (y/n): ";

        string input;
        getline(cin, input);

        if (input == "y")
        {
            facts.insert(attributes[i]);
        }
    }
    vector<bool> usedRule(10, false);
    bool newFactFound = true;
    // Forward Chaining
    while (newFactFound)
    {
        newFactFound = false;

        for (int i = 0; i < knowledgeBase.size(); i++)
        {
            if (usedRule[i])
            {
                continue;
            }

            // Check first condition
            if (facts.count(knowledgeBase[i].condition1))
            {
                // Check second condition if exists
                if (knowledgeBase[i].condition2 == "" ||
                    facts.count(knowledgeBase[i].condition2))
                {
                    facts.insert(knowledgeBase[i].fact);

                    cout << "\nDerived Fact: "
                         << knowledgeBase[i].fact << endl;

                    cout << "Reason: "
                         << knowledgeBase[i].inference << endl;

                    usedRule[i] = true;

                    newFactFound = true;
                }
            }
        }
    }

    // Final facts
    cout << "\n------ FINAL EVALUATION ------\n";

    for (auto x : facts)
    {
        cout << x << endl;
    }

    return 0;
}