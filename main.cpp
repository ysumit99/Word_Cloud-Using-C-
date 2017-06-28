/*  WORD CLOUD (using C++ 14) 
Author : YADAV SUMITKUMAR 
		 CSE Sec-C
		 Reg.No : 149105478
 to compile: g++ main.cpp -std=c++0x
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, found;
	string str;
	ifstream fi("out.txt");
	ofstream fo("word_cloud.html");

	vector<string> stopwords = {",",".",";","is","were","has","we","a","an","the","of","from","to","when","will","be","at","but","in","and"};
	vector< pair<string, int> > list;
	vector< pair<string, int> >::iterator it;

	if( !fi.is_open() || !fo.is_open()) {
		cout << "Error opening files." << endl;
		return 0;
	}

	while (fi >> str) 
	{
		// Checking for stopwords
		if (find(stopwords.begin(), stopwords.end(), str) != stopwords.end()) {
			continue;
		}

		found = 0;
		// Searching if word already exists
    	for (i = 0; i < list.size(); i++) {
    		if (str == list[i].first) {
    			found = 1;
    			break;
    		}
    	}

    	if (found == 1) {		// Increment Frequency if exists
    		list[i].second = list[i].second + 1;
    	} else {				// Add to the list if does not exists 
    		list.push_back(make_pair(str, 1));
    	}
	}

	fo << "<html>\n<title>Word Cloud</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n</head>\n<body>\n<div class=\"para\">\n";

	for ( it = list.begin() ; it != list.end() ; it++) {
		
		if (it->second == 1) {
			fo << "<span class=\"text1\">" + it->first + "</span>\n";
		}
		else if (it->second == 2) {
			fo << "<span class=\"text2\">" + it->first + "</span>\n";
		}
		else if (it->second == 3) {
			fo << "<span class=\"text3\">" + it->first + "</span>\n";
		}
		else if (it->second == 4) {
			fo << "<span class=\"text4\">" + it->first + "</span>\n";
		}
		else if (it->second > 4) {
			fo << "<span class=\"text5\">" + it->first + "</span>\n";
		}
	}

	fo << "</div>\n</body>\n</html>";

	fi.close();
	fo.close();
	return 0;
}