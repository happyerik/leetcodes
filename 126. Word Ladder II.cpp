class Solution {
public:
    void DFS(set<pair<string, int>> st, vector<string> vec)
    {
        for(auto val: st)
        {
            vec.push_back(val.first);
            if(hash.count(val.first) == 0)
            {
                reverse(vec.begin(), vec.end());
                return result.push_back(vec);
            }
            DFS(hash[val.first], vec);
            vec.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) 
    {
        wordList.insert(endWord);
        wordList.erase(beginWord);
        que.push(make_pair(beginWord, 1));
        while(!que.empty())
        {
            auto val = que.front();
            que.pop();

            for(int i = 0; i < val.first.size(); i++)
            {
                string tem = val.first;
                for(int j = 0; j < 26; j ++)
                {
                    tem[i] = 'a' + j;
                    if(wordList.count(tem))  //find the string in the dict and delete the item
                    {
                        que.push(make_pair(tem, val.second + 1));
                        wordList.erase(tem);
                        hash[tem].insert(val);
                    }
                    else if(hash.count(tem) && hash[tem].begin()->second == val.second)  
                        hash[tem].insert(val);
                }
            }
        }
        DFS(hash[endWord], vector<string>{endWord});
        return result;
    }
    vector<vector<string>> result;
    unordered_map<string, set<pair<string, int>>> hash;
    queue<pair<string, int>> que;
};