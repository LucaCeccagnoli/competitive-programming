#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

bool compareJobs(Job &j1, Job &j2){
    return j1.profit > j2.profit;
}

void job_sequencing(vector<Job> jobs, int max_time){
    vector<int> slots(max_time, -1);
    set<int> free_slots;

    // sort jobs from most profitable to least
    sort(jobs.begin(), jobs.end(), compareJobs);

    // initialize BST
    for(int i=0; i < max_time; i++){
        free_slots.insert(i);
    }

    for(int i=0; i < jobs.size(); i++){
        // find slot that is predecessor of the job's deadline
        int slot = *free_slots.lower_bound(jobs[i].deadline);
        free_slots.erase(slot);

        slots[slot] = jobs[i].id;
    }

    cout << "optimal job sequence: ";
    for(int i=0; i < slots.size(); i++){
        cout << slots[i] << " ";
    }
    cout << endl;
}

int main(){
    // input variables
    int size, val; 
    string input;

    vector<Job> jobs;
    int max_time = 0; // max deadline, starts at 0

    cout << "input number of jobs" << endl;
    cin >> size;
    cin.ignore();

    cout << "input " << size << " jobs:" << "deadline profit" << endl;
    stringstream ss; 
    for(int i = 0; i < size; i++){
        getline(cin, input);
        ss = stringstream(input);
        Job new_job;

        new_job.id = i;

        ss >> val;
        new_job.deadline = val;

        if(new_job.deadline > max_time){
            max_time = new_job.deadline;
        }

        ss >> val;
        new_job.profit = val;

        jobs.push_back(new_job);
    }

    job_sequencing(jobs, max_time);
}