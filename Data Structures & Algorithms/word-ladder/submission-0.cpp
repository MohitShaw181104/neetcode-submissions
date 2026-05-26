class Solution {
public:

    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        queue<pair<string,int>> q;

        q.push({beginWord, 1});

        unordered_set<string> st(
            wordList.begin(),
            wordList.end()
        );

        // endWord must exist
        if(st.find(endWord) == st.end()) {
            return 0;
        }

        st.erase(beginWord);

        while(!q.empty()) {

            string word = q.front().first;
            int steps = q.front().second;

            q.pop();

            // reached target
            if(word == endWord) {
                return steps;
            }

            // change every character
            for(int i = 0; i < word.size(); i++) {

                char original = word[i];

                // try all alphabets
                for(char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // valid dictionary word
                    if(st.find(word) != st.end()) {

                        q.push({word, steps + 1});

                        st.erase(word);
                    }
                }

                // restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};