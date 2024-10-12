#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iostream>
using namespace std;
struct Directory {
	vector<int> subDir;
	vector<int> files;
};
struct File {
	string name;
	File(string _name) : name(_name) {}
};

int main() {
	int d, f;
	cin >> d >> f;
	unordered_map<string,int> directoryIdx;
	unordered_map<string,int> fileIdx;
	vector<File> files;
	vector<Directory> directories;
	directories.push_back(Directory());
	directoryIdx.insert({ "main", 0});
	for (int i = 0; i < d + f; i++) {
		string dst, src;
		int type;
		cin >> dst >> src >> type;
		if (directoryIdx.find(dst) == directoryIdx.end()) {
			directories.emplace_back();
			directoryIdx.insert({ dst, directories.size() - 1 });
		} 
		int dstIdx = directoryIdx.find(dst)->second;

		switch (type)
		{
		case 0: {
			auto it = fileIdx.find(src);
			if (it == fileIdx.end()) {
				files.emplace_back(src);
				fileIdx.insert({ src, files.size() - 1});
				directories[dstIdx].files.push_back(files.size() - 1);
			}
			else {
				directories[dstIdx].files.push_back(it->second);
			}
			break;
		}
		case 1: {
			if (directoryIdx.find(src) == directoryIdx.end()) {
				directories.emplace_back();
				directoryIdx.insert({ src, directories.size() - 1 });
			}
			int srcIdx = directoryIdx.find(src)->second;
			directories[dstIdx].subDir.push_back(srcIdx);
			break;
		}
		default:
			break;
		}
	}
	int queryNum;
	cin >> queryNum;

	for (int i = 0; i < queryNum; i++) {
		string query;
		cin >> query;
		int fd = 0;
		int fileNum = 0;
		unordered_set<int> fileType;
		
		fd = query.find_last_of('/');

		string dir;
		if (fd == string::npos) dir = query;
		else dir = query.substr(fd + 1, query.size());

		stack<int> s;
		if(directoryIdx.find(dir) != directoryIdx.end()) s.push(directoryIdx[dir]);
		do {
			int j = s.top();
			s.pop();
			fileNum += directories[j].files.size();
			for (int idx : directories[j].files) {
				fileType.insert(idx);
			}
			for (int idx : directories[j].subDir) {
				s.push(idx);
			}
		}
		while(!s.empty());
		cout << fileType.size() << ' ' << fileNum << '\n';
	}
	return 0;
}
