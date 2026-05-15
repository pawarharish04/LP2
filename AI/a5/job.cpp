#include <iostream>
#include <algorithm>
using namespace std;

class Job {
public:
    char id;
    int deadline;
    int profit;
};

class JobScheduling {
private:
    Job jobs[100];
    int n;

public:
    void input() {
        cout << "Enter number of jobs: ";
        cin >> n;

        cout << "Enter Job ID, Deadline and Profit:\n";

        for(int i = 0; i < n; i++) {
            cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        }
    }

    static bool compare(Job a, Job b) {
        return a.profit > b.profit;
    }

    void scheduleJobs() {

        sort(jobs, jobs + n, compare);

        int maxDeadline = 0;

        for(int i = 0; i < n; i++) {
            if(jobs[i].deadline > maxDeadline)
                maxDeadline = jobs[i].deadline;
        }

        char result[100];
        bool slot[100] = {false};

        int totalProfit = 0;

        for(int i = 0; i < n; i++) {

            for(int j = jobs[i].deadline - 1; j >= 0; j--) {

                if(slot[j] == false) {

                    result[j] = jobs[i].id;
                    slot[j] = true;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }

        cout << "\nSelected Jobs:\n";

        for(int i = 0; i < maxDeadline; i++) {
            if(slot[i])
                cout << result[i] << " ";
        }

        cout << "\nTotal Profit: " << totalProfit;
    }
};

int main() {

    JobScheduling js;

    js.input();
    js.scheduleJobs();

    return 0;
}