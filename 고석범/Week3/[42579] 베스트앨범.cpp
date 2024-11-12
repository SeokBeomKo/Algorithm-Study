#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<string, vector<int>>& a, pair<string, vector<int>>& b) 
{
    return a.second[0] > b.second[0];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<int>> m;     // 0 = 총 , 1 = 1위 인덱스, 2 = 2위 인덱스

    for (int i = genres.size() - 1; i >= 0; i--)
    {
        if (m[genres[i]].empty()) m[genres[i]] = { 0, -1, -1 };

        m[genres[i]][0] += plays[i];

        if (m[genres[i]][1] == -1 || plays[m[genres[i]][1]] <= plays[i])
        {
            m[genres[i]][2] = m[genres[i]][1];
            m[genres[i]][1] = i;
        }
        else if (m[genres[i]][2] == -1 || plays[m[genres[i]][2]] <= plays[i])
        {
            m[genres[i]][2] = i;
        }
    }

    vector<pair<string, vector<int>>> mv(m.begin(), m.end());
    sort(mv.begin(), mv.end(), compare);

    for (auto element : mv)
    {
        answer.push_back(element.second[1]);

        if (element.second[2] != -1) {
            answer.push_back(element.second[2]);
        }
    }

    return answer;
}
