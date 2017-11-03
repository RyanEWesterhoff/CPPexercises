#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

//Summary: Given a set of n jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

//Input
//The first line of input contains an integer T denoting the number of test cases.Each test case consist of an integer N denoting the number of jobs and the next line consist of Job id, Deadline and the Profit associated to that Job.

//Output
//Output the number of jobs done and the maximum profit.

//sort descending
void insertionSortSecond(vector<pair<int, int>> &v) {
	pair<int, int> key;
	int j;
	for (unsigned i = 0; i < v.size(); i++) {
		key = v[i];
		j = i - 1;

		while (j >= 0 && v[j].second < key.second) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}

int main() {
	int tests;
	string tIn;
	int numJobs = 4;
	string jIn;
	vector<pair<int, int>> jobs;
	string jVals;
	int temp;
	int maxJobs = 0;
	vector<int> optimalJobs;

	cout << "Test Cases: " << endl;
	getline(cin, tIn);
	tests = stoi(tIn);

	for (int t = 0; t < tests; t++) {
		cout << "Number of jobs: " << endl;
		getline(cin, jIn);
		stringstream s1(jIn);
		s1 >> numJobs;

		cout << "Job values: " << endl;
		getline(cin, jVals);
		stringstream s2(jVals);


	for (int i = 0; i < numJobs; i++) {
		s2 >> temp;
		pair<int, int> p;
		s2 >> temp;
		p.first = temp;
		if (p.first > maxJobs)
			maxJobs = p.first;
		s2 >> temp;
		p.second = temp;
		jobs.push_back(p);
	}

	//initialize optimal vector
	for (int i = 0; i < maxJobs; i++) {
		optimalJobs.push_back(0);
	}

	insertionSortSecond(jobs);

	for (int i = maxJobs; i > 0; i--) {
		int j = 0;
		while (jobs[j].first < i)
			j++;
		optimalJobs[i] = jobs[j].second;
		jobs.erase(jobs.begin() + j);
	}

	temp = 0;
	int totalJobs = 0;
	for (unsigned i = 1; i <= optimalJobs.size(); i++) {
		//cout << i << ": " << optimalJobs[i] << endl;
		temp += optimalJobs[i];
		if (optimalJobs[i] != 0)
			totalJobs++;
	}
	cout << "Jobs Completed: " << totalJobs << endl;
	cout << "Max Profit: " << temp << endl;

	}

	return 0;
}
