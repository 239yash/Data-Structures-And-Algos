    bool checkInclusion(string s1, string s2)
    {
        if(s1.length() > s2.length())
            return false;
        
        std::unordered_map<char, int> ms1;
        std::unordered_map<char, int> window;
        for(auto x : s1)
            ms1[x]++;
        
        int mct = 0;
        int des_mct = s1.length();
        
        int i = 0;
        while(i < s2.length())
        {
            if(i < s1.length())
            {
                window[s2[i]]++;
                if(ms1.find(s2[i]) != ms1.end() && window[s2[i]] <= ms1[s2[i]])
                    mct++;
                
                if(mct == des_mct)
                    return true;
                
                // cout<<mct<<endl;
            }
            else
            {
                window[s2[i]]++;
                if(ms1.find(s2[i]) != ms1.end() && window[s2[i]] <= ms1[s2[i]])
                    mct++;
                
                // cout<<mct<<endl;  
                if(ms1.find(s2[i - des_mct]) != ms1.end() && window[s2[i - des_mct]] <= ms1[s2[i - des_mct]])
                    mct--;
                window[s2[i - des_mct]]--; 
                
                
                if(mct == des_mct)
                    return true;
            }
            
            i++;
        }
        
        return false;
    }
