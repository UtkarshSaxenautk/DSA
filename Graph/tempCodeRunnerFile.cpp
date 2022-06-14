 ans.push_back(make_pair(v[0].second.first , v[0].second.second));
    temp.push_back(make_pair(v[0].second.first , v[0].second.second));
    for(int i = 1; i < v.size(); i++){
        if(check(temp , v[i].second.first , v[i].second.second) == true){
            ans.push_back(make_pair(v[i].second.first , v[i].second.second));
            count += v[i].first;
        }
        temp.push_back(make_pair(v[i].second.first , v[i].second.second));
    }
