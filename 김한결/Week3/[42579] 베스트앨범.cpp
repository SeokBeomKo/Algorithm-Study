#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compareTotalPlay(pair<string, int> a, pair<string, int>b)
{
    return a.second > b.second;
}

bool compareGenrePlay(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second) return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;

    map<string, int> totalPlay; // 전체 재생 수
    map<string, vector<pair<int, int>>> genrePlay; // 장르 별 재생 수

    for(int i = 0; i < genres.size(); i++)
    {
        totalPlay[genres[i]] += plays[i];
        genrePlay[genres[i]].emplace_back(i, plays[i]);
    }

    vector<pair<string, int>> totalSort(totalPlay.begin(), totalPlay.end());
    sort(totalSort.begin(), totalSort.end(), compareTotalPlay);
    
    for(int i = 0; i < totalSort.size(); i++)
    {
        vector<pair<int, int>> genreSort = genrePlay[totalSort[i].first];
        sort(genreSort.begin(), genreSort.end(), compareGenrePlay);

        for(int j = 0; j < genreSort.size() && j < 2; j++)
        {
            answer.push_back(genreSort[j].first);
        }
    }

    return answer;
}
