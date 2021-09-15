#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll counter = 0;
unordered_map<int, pair<string, string>>db;
const string mp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


//BASE-62 ENCODER
string idToShortURL(ll id) {
	string shortURL;
	while (id) {
		shortURL.push_back(mp[id % 62]);
		id /= 62;
	}
	reverse(shortURL.begin(), shortURL.end());
	// shortURL = "www.tinyurl.com/" + shortURL;
	return shortURL;
}
// DECODE
ll shortURLtoID(string shortURL) {
	ll id = 0;
	for (int i = 0; i < shortURL.length(); ++i) {
		if ('a' <= shortURL[i] && shortURL[i] <= 'z') {
			id = id * 62 + shortURL[i] - 'a';
		}
		if ('A' <= shortURL[i] && shortURL[i] <= 'Z') {
			id = id * 62 + shortURL[i] - 'A' + 26;
		}
		if ('0' <= shortURL[i] && shortURL[i] <= '9') {
			id = id * 62 + shortURL[i] - '0' + 52;
		}
	}
	return id;
}

// Encodes a URL to a shortened URL.
string encode(string longUrl) {
	++counter;
	db[counter] = make_pair(longUrl, idToShortURL(counter));
	return db[counter].second;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
	int x = shortURLtoID(shortUrl);
	if (db.find(x) != db.end())
		return db[x].first;
	return "Such a tinyURL does not exist in DataBase.";
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int q;
	cin >> q;
	while (q--) {
		// 0 -> insert URL & 1 -> retrive the URL;
		int option;
		string s;
		cin >> option >> s;
		if (option == 0) {
			cout << "www.tinyurl.com/" << encode(s) << "\n";
		} else if (option == 1) {
			cout << decode(s) << "\n";
		} else {
			cout << "Invalid Option" << "\n";
		}
	}
	return 0;
}
