#include<iostream>
#include<deque>
#include<string>
using namespace std;
/*
문제 : 3111번 검열
분류 : 덱
*/
int main()
{
	string word;
	string target;
	cin >> word >> target;
	int change = 0;
	int change2 = 0;
	string temp = "";
	string temp2 = "";
	string final = "";
	deque<char> fst;
	deque<char> lst;
	long long k = word.size();
	long long idx = 0;
	long long idx2 = target.size()-1;
	while (idx<=idx2) {
		while (idx <= idx2) {
			fst.push_back(target[idx++]);
			change = 0;
			if (fst.size() >= word.size()) {
				change = 1;
				for (int i = 0; i < word.size(); i++) {
					if (word[i] != fst[fst.size() - word.size() + i]) {
						change = 0;
						break;
					}
				}
			}
			if (change) {
				for (int i = 0; i < word.size(); i++)fst.pop_back();
				break;
			}
		}
		while (idx <= idx2) {
			lst.push_front(target[idx2--]);
			change = 0;
			if (lst.size() >= word.size()) {
				change = 1;
				for (int i = 0; i < word.size(); i++) {
					if (word[i] != lst[i]) {
						change = 0;
						break;
					}
				}
			}
			if (change) {
				for (int i = 0; i < word.size(); i++)lst.pop_front();
				break;
			}
		}

	}

	string answer;
	for (int i = 0; i < fst.size(); i++)answer.push_back(fst[i]);
	for (int i = 0; i < lst.size(); i++)answer.push_back(lst[i]);
	
	while (answer.find(word) < 30000)
		answer.erase(answer.find(word), word.size());
	if(!answer.empty())cout << answer;
}
