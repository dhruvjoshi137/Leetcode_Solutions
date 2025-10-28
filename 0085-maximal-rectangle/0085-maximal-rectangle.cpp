class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v;
        for(int j=0;j<m;j++){
            v.push_back(matrix[0][j] - '0');
        }
        int mx = MaximumAreaHistogram(v);

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }else{
                    v[j] = v[j]+1;
                }
                
            }
            mx = max(mx,MaximumAreaHistogram(v));
        }
        return mx;
    }

    int MaximumAreaHistogram(vector<int>& arr){
        int n = arr.size();
        vector<int> left;
        stack<pair<int,int>> s;

        for(int i=0;i<n;i++){
            int pseudoIndex = -1;
            if(s.size()==0){
                left.push_back(pseudoIndex);
            }else if(s.size()>0 && s.top().first<arr[i]){
                left.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }if(s.size()==0){
                    left.push_back(pseudoIndex);
                }else{
                    left.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
    

    while(!s.empty()){
        s.pop();
    }
    vector<int> right;

        for(int i=n-1;i>=0;i--){
            int pseudoIndex = n;
            if(s.size()==0){
                right.push_back(pseudoIndex);
            }else if(s.size()>0 && s.top().first<arr[i]){
                right.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=arr[i]){
                while(s.size()>0 && s.top().first>=arr[i]){
                    s.pop();
                }if(s.size()==0){
                    right.push_back(pseudoIndex);
                }else{
                    right.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
            reverse(right.begin(),right.end());

        int maxArea = 0;
        for(int i=0;i<n;i++){
            int width = right[i]-left[i]-1;
            int area = width*arr[i];
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};