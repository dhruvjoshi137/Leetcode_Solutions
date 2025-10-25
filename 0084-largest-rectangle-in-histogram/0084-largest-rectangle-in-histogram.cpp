class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left;
        vector<int> right;
        stack<pair<int,int>> s;

        for(int i=0;i<n;i++){
        int pseudoIndex = -1;
            if(s.size()==0){
                left.push_back(pseudoIndex);
            }else if(s.size()>0 && s.top().first<heights[i]){
                left.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    left.push_back(pseudoIndex);
                }else{
                    left.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }

        //clear the stack first
        while(!s.empty()){
            s.pop();
        }

        for(int i=n-1;i>=0;i--){
        int pseudoIndex = n;
            if(s.size()==0){
                right.push_back(pseudoIndex);
            }else if(s.size()>0 && s.top().first<heights[i]){
                right.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    right.push_back(pseudoIndex);
                }else{
                    right.push_back(s.top().second);
                }
            } 
            s.push({heights[i],i});
        }
            reverse(right.begin(),right.end());

  

        int maxArea=0;
        for(int i=0;i<n;i++){
            int width = right[i]-left[i]-1;
            int area = heights[i]*width;
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};