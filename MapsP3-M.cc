#include <iostream>
#include <vector>
using namespace std;

//Summary: Given n points in the plane that are all pairwise distinct, a “boomerang” is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

int distance(vector<pair<int, int>>& points, int firstIdx, int secondIdx) {
	int dx = points[firstIdx].first - points[secondIdx].first;
	int dy = points[firstIdx].second - points[secondIdx].second;

	return dx * dx + dy * dy;
}

int numberOfBoomerangs(vector<pair<int, int>>& points) {
	int booms = 0;
	for (unsigned int i = 0; i < points.size(); i++) {
			for (unsigned int j = 0; j < points.size(); j++) {
				if(i == j) continue;
				for (unsigned int k = 0; k < points.size(); k++) {
					if((i == k) || (j == k)) continue;
					if (distance(points, i, j) == distance(points, i, k)) {
						booms++;
					}
				}
			}
		}
	return booms;
}

int main() {

	vector<pair<int, int>> points;
	points.push_back(make_pair(0, 0));
	points.push_back(make_pair(1, 0));
	points.push_back(make_pair(2, 0));

	cout << "Number of Boomerangs: " << numberOfBoomerangs(points) << endl;;

	 /*THIS CODE IS INCLUDED IF DISPLAY OF EACH BOOMERANG IS DESIRED
 	struct boomerang {
		pair<int, int> i;
		pair<int, int> j;
		pair<int, int> k;
	};
 	vector<boomerang> boomerangs;
	for (unsigned int i = 0; i < points.size(); i++) {
		for (unsigned int j = 0; j < points.size(); j++) {
			if(i == j) continue;
			for (unsigned int k = 0; k < points.size(); k++) {
				if((i == k) || (j == k)) continue;
				if (distance(points, i, j) == distance(points, i, k)) {
					boomerang foundBoom;
					foundBoom.i = points[i];
					foundBoom.j = points[j];
					foundBoom.k = points[k];
					boomerangs.push_back(foundBoom);
				}
			}
		}
	}

	for (unsigned int i = 0; i < boomerangs.size(); i++) {
		cout << "Found boomerang: " << "[" << boomerangs[i].i.first << ","
				<< boomerangs[i].i.second << "] ";
		cout << "[" << boomerangs[i].j.first << "," << boomerangs[i].j.second
				<< "] ";
		cout << "[" << boomerangs[i].k.first << "," << boomerangs[i].k.second
				<< "] ";
		cout << endl;
	}
	*/
}

